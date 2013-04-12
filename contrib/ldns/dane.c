/*
 * Verify or create TLS authentication with DANE (RFC6698)
 *
 * (c) NLnetLabs 2012
 *
 * See the file LICENSE for the license.
 *
 */

#include <ldns/config.h>

#include <ldns/ldns.h>
#include <ldns/dane.h>

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

#ifdef HAVE_SSL
#include <openssl/ssl.h>
#include <openssl/err.h>
#include <openssl/x509v3.h>
#endif

ldns_status
ldns_dane_create_tlsa_owner(ldns_rdf** tlsa_owner, const ldns_rdf* name,
		uint16_t port, ldns_dane_transport transport)
{
	char buf[LDNS_MAX_DOMAINLEN];
	size_t s;

	assert(tlsa_owner != NULL);
	assert(name != NULL);
	assert(ldns_rdf_get_type(name) == LDNS_RDF_TYPE_DNAME);

	s = (size_t)snprintf(buf, LDNS_MAX_DOMAINLEN, "X_%d", (int)port);
	buf[0] = (char)(s - 1);

	switch(transport) {
	case LDNS_DANE_TRANSPORT_TCP:
		s += snprintf(buf + s, LDNS_MAX_DOMAINLEN - s, "\004_tcp");
		break;
	
	case LDNS_DANE_TRANSPORT_UDP:
		s += snprintf(buf + s, LDNS_MAX_DOMAINLEN - s, "\004_udp");
		break;

	case LDNS_DANE_TRANSPORT_SCTP:
		s += snprintf(buf + s, LDNS_MAX_DOMAINLEN - s, "\005_sctp");
		break;
	
	default:
		return LDNS_STATUS_DANE_UNKNOWN_TRANSPORT;
	}
	if (s + ldns_rdf_size(name) > LDNS_MAX_DOMAINLEN) {
		return LDNS_STATUS_DOMAINNAME_OVERFLOW;
	}
	memcpy(buf + s, ldns_rdf_data(name), ldns_rdf_size(name));
	*tlsa_owner = ldns_rdf_new_frm_data(LDNS_RDF_TYPE_DNAME,
			s + ldns_rdf_size(name), buf);
	if (*tlsa_owner == NULL) {
		return LDNS_STATUS_MEM_ERR;
	}
	return LDNS_STATUS_OK;
}


#ifdef HAVE_SSL
ldns_status
ldns_dane_cert2rdf(ldns_rdf** rdf, X509* cert,
		ldns_tlsa_selector      selector,
		ldns_tlsa_matching_type matching_type)
{
	unsigned char* buf = NULL;
	size_t len;

	X509_PUBKEY* xpubkey;
	EVP_PKEY* epubkey;

	unsigned char* digest;

	assert(rdf != NULL);
	assert(cert != NULL);

	switch(selector) {
	case LDNS_TLSA_SELECTOR_FULL_CERTIFICATE:

		len = (size_t)i2d_X509(cert, &buf);
		break;

	case LDNS_TLSA_SELECTOR_SUBJECTPUBLICKEYINFO:

#ifndef S_SPLINT_S
		xpubkey = X509_get_X509_PUBKEY(cert);
#endif
		if (! xpubkey) {
			return LDNS_STATUS_SSL_ERR;
		}
		epubkey = X509_PUBKEY_get(xpubkey);
		if (! epubkey) {
			return LDNS_STATUS_SSL_ERR;
		}
		len = (size_t)i2d_PUBKEY(epubkey, &buf);
		break;
	
	default:
		return LDNS_STATUS_DANE_UNKNOWN_SELECTOR;
	}

	switch(matching_type) {
	case LDNS_TLSA_MATCHING_TYPE_NO_HASH_USED:

		*rdf = ldns_rdf_new(LDNS_RDF_TYPE_HEX, len, buf);
		
		return *rdf ? LDNS_STATUS_OK : LDNS_STATUS_MEM_ERR;
		break;
	
	case LDNS_TLSA_MATCHING_TYPE_SHA256:

		digest = LDNS_XMALLOC(unsigned char, SHA256_DIGEST_LENGTH);
		if (digest == NULL) {
			LDNS_FREE(buf);
			return LDNS_STATUS_MEM_ERR;
		}
		(void) ldns_sha256(buf, (unsigned int)len, digest);
		*rdf = ldns_rdf_new(LDNS_RDF_TYPE_HEX, SHA256_DIGEST_LENGTH,
				digest);
		LDNS_FREE(buf);

		return *rdf ? LDNS_STATUS_OK : LDNS_STATUS_MEM_ERR;
		break;

	case LDNS_TLSA_MATCHING_TYPE_SHA512:

		digest = LDNS_XMALLOC(unsigned char, SHA512_DIGEST_LENGTH);
		if (digest == NULL) {
			LDNS_FREE(buf);
			return LDNS_STATUS_MEM_ERR;
		}
		(void) ldns_sha512(buf, (unsigned int)len, digest);
		*rdf = ldns_rdf_new(LDNS_RDF_TYPE_HEX, SHA512_DIGEST_LENGTH,
				digest);
		LDNS_FREE(buf);

		return *rdf ? LDNS_STATUS_OK : LDNS_STATUS_MEM_ERR;
		break;
	
	default:
		LDNS_FREE(buf);
		return LDNS_STATUS_DANE_UNKNOWN_MATCHING_TYPE;
	}
}


/* Ordinary PKIX validation of cert (with extra_certs to help)
 * against the CA's in store
 */
static ldns_status
ldns_dane_pkix_validate(X509* cert, STACK_OF(X509)* extra_certs,
		X509_STORE* store)
{
	X509_STORE_CTX* vrfy_ctx;
	ldns_status s;

	if (! store) {
		return LDNS_STATUS_DANE_PKIX_DID_NOT_VALIDATE;
	}
	vrfy_ctx = X509_STORE_CTX_new();
	if (! vrfy_ctx) {

		return LDNS_STATUS_SSL_ERR;

	} else if (X509_STORE_CTX_init(vrfy_ctx, store,
				cert, extra_certs) != 1) {
		s = LDNS_STATUS_SSL_ERR;

	} else if (X509_verify_cert(vrfy_ctx) == 1) {

		s = LDNS_STATUS_OK;

	} else {
		s = LDNS_STATUS_DANE_PKIX_DID_NOT_VALIDATE;
	}
	X509_STORE_CTX_free(vrfy_ctx);
	return s;
}


/* Orinary PKIX validation of cert (with extra_certs to help)
 * against the CA's in store, but also return the validation chain.
 */
static ldns_status
ldns_dane_pkix_validate_and_get_chain(STACK_OF(X509)** chain, X509* cert,
		STACK_OF(X509)* extra_certs, X509_STORE* store)
{
	ldns_status s;
	X509_STORE* empty_store = NULL;
	X509_STORE_CTX* vrfy_ctx;

	assert(chain != NULL);

	if (! store) {
		store = empty_store = X509_STORE_new();
	}
	s = LDNS_STATUS_SSL_ERR;
	vrfy_ctx = X509_STORE_CTX_new();
	if (! vrfy_ctx) {

		goto exit_free_empty_store;

	} else if (X509_STORE_CTX_init(vrfy_ctx, store,
					cert, extra_certs) != 1) {
		goto exit_free_vrfy_ctx;

	} else if (X509_verify_cert(vrfy_ctx) == 1) {

		s = LDNS_STATUS_OK;

	} else {
		s = LDNS_STATUS_DANE_PKIX_DID_NOT_VALIDATE;
	}
	*chain = X509_STORE_CTX_get1_chain(vrfy_ctx);
	if (! *chain) {
		s = LDNS_STATUS_SSL_ERR;
	}

exit_free_vrfy_ctx:
	X509_STORE_CTX_free(vrfy_ctx);

exit_free_empty_store:
	if (empty_store) {
		X509_STORE_free(empty_store);
	}
	return s;
}


/* Return the validation chain that can be build out of cert, with extra_certs.
 */
static ldns_status
ldns_dane_pkix_get_chain(STACK_OF(X509)** chain,
		X509* cert, STACK_OF(X509)* extra_certs)
{
	ldns_status s;
	X509_STORE* empty_store = NULL;
	X509_STORE_CTX* vrfy_ctx;

	assert(chain != NULL);

	empty_store = X509_STORE_new();
	s = LDNS_STATUS_SSL_ERR;
	vrfy_ctx = X509_STORE_CTX_new();
	if (! vrfy_ctx) {

		goto exit_free_empty_store;

	} else if (X509_STORE_CTX_init(vrfy_ctx, empty_store,
					cert, extra_certs) != 1) {
		goto exit_free_vrfy_ctx;
	}
	(void) X509_verify_cert(vrfy_ctx);
	*chain = X509_STORE_CTX_get1_chain(vrfy_ctx);
	if (! *chain) {
		s = LDNS_STATUS_SSL_ERR;
	} else {
		s = LDNS_STATUS_OK;
	}
exit_free_vrfy_ctx:
	X509_STORE_CTX_free(vrfy_ctx);

exit_free_empty_store:
	X509_STORE_free(empty_store);
	return s;
}


/* Pop n+1 certs and return the last popped.
 */
static ldns_status
ldns_dane_get_nth_cert_from_validation_chain(
		X509** cert, STACK_OF(X509)* chain, int n, bool ca)
{
	if (n >= sk_X509_num(chain) || n < 0) {
		return LDNS_STATUS_DANE_OFFSET_OUT_OF_RANGE;
	}
	*cert = sk_X509_pop(chain);
	while (n-- > 0) {
		X509_free(*cert);
		*cert = sk_X509_pop(chain);
	}
	if (ca && ! X509_check_ca(*cert)) {
		return LDNS_STATUS_DANE_NON_CA_CERTIFICATE;
	}
	return LDNS_STATUS_OK;
}


/* Create validation chain with cert and extra_certs and returns the last
 * self-signed (if present).
 */
static ldns_status
ldns_dane_pkix_get_last_self_signed(X509** out_cert,
		X509* cert, STACK_OF(X509)* extra_certs)
{
	ldns_status s;
	X509_STORE* empty_store = NULL;
	X509_STORE_CTX* vrfy_ctx;

	assert(out_cert != NULL);

	empty_store = X509_STORE_new();
	s = LDNS_STATUS_SSL_ERR;
	vrfy_ctx = X509_STORE_CTX_new();
	if (! vrfy_ctx) {
		goto exit_free_empty_store;

	} else if (X509_STORE_CTX_init(vrfy_ctx, empty_store,
					cert, extra_certs) != 1) {
		goto exit_free_vrfy_ctx;

	}
	(void) X509_verify_cert(vrfy_ctx);
	if (vrfy_ctx->error == X509_V_ERR_SELF_SIGNED_CERT_IN_CHAIN ||
	    vrfy_ctx->error == X509_V_ERR_DEPTH_ZERO_SELF_SIGNED_CERT){

		*out_cert = X509_STORE_CTX_get_current_cert( vrfy_ctx);
		s = LDNS_STATUS_OK;
	} else {
		s = LDNS_STATUS_DANE_PKIX_NO_SELF_SIGNED_TRUST_ANCHOR;
	}
exit_free_vrfy_ctx:
	X509_STORE_CTX_free(vrfy_ctx);

exit_free_empty_store:
	X509_STORE_free(empty_store);
	return s;
}


ldns_status
ldns_dane_select_certificate(X509** selected_cert,
		X509* cert, STACK_OF(X509)* extra_certs,
		X509_STORE* pkix_validation_store,
		ldns_tlsa_certificate_usage cert_usage, int offset)
{
	ldns_status s;
	STACK_OF(X509)* pkix_validation_chain = NULL;

	assert(selected_cert != NULL);
	assert(cert != NULL);

	/* With PKIX validation explicitely turned off (pkix_validation_store
	 *  == NULL), treat the "CA constraint" and "Service certificate
	 * constraint" the same as "Trust anchor assertion" and "Domain issued
	 * certificate" respectively.
	 */
	if (pkix_validation_store == NULL) {
		switch (cert_usage) {

		case LDNS_TLSA_USAGE_CA_CONSTRAINT:

			cert_usage = LDNS_TLSA_USAGE_TRUST_ANCHOR_ASSERTION;
			break;

		case LDNS_TLSA_USAGE_SERVICE_CERTIFICATE_CONSTRAINT:

			cert_usage = LDNS_TLSA_USAGE_DOMAIN_ISSUED_CERTIFICATE;
			break;

		default:
			break;
		}
	}

	/* Now what to do with each Certificate usage...
	 */
	switch (cert_usage) {

	case LDNS_TLSA_USAGE_CA_CONSTRAINT:

		s = ldns_dane_pkix_validate_and_get_chain(
				&pkix_validation_chain,
				cert, extra_certs,
				pkix_validation_store);
		if (! pkix_validation_chain) {
			return s;
		}
		if (s == LDNS_STATUS_OK) {
			if (offset == -1) {
				offset = 0;
			}
			s = ldns_dane_get_nth_cert_from_validation_chain(
					selected_cert, pkix_validation_chain,
					offset, true);
		}
		sk_X509_pop_free(pkix_validation_chain, X509_free);
		return s;
		break;


	case LDNS_TLSA_USAGE_SERVICE_CERTIFICATE_CONSTRAINT:

		*selected_cert = cert;
		return ldns_dane_pkix_validate(cert, extra_certs,
				pkix_validation_store);
		break;


	case LDNS_TLSA_USAGE_TRUST_ANCHOR_ASSERTION:

		if (offset == -1) {
			s = ldns_dane_pkix_get_last_self_signed(
					selected_cert, cert, extra_certs);
			return s;
		} else {
			s = ldns_dane_pkix_get_chain(
					&pkix_validation_chain,
					cert, extra_certs);
			if (s == LDNS_STATUS_OK) {
				s =
				ldns_dane_get_nth_cert_from_validation_chain(
					selected_cert, pkix_validation_chain,
					offset, false);
			} else if (! pkix_validation_chain) {
				return s;
			}
			sk_X509_pop_free(pkix_validation_chain, X509_free);
			return s;
		}
		break;


	case LDNS_TLSA_USAGE_DOMAIN_ISSUED_CERTIFICATE:

		*selected_cert = cert;
		return LDNS_STATUS_OK;
		break;
	
	default:
		return LDNS_STATUS_DANE_UNKNOWN_CERTIFICATE_USAGE;
		break;
	}
}


ldns_status
ldns_dane_create_tlsa_rr(ldns_rr** tlsa,
		ldns_tlsa_certificate_usage certificate_usage,
		ldns_tlsa_selector          selector,
		ldns_tlsa_matching_type     matching_type,
		X509* cert)
{
	ldns_rdf* rdf;
	ldns_status s;

	assert(tlsa != NULL);
	assert(cert != NULL);

	/* create rr */
	*tlsa = ldns_rr_new_frm_type(LDNS_RR_TYPE_TLSA);
	if (*tlsa == NULL) {
		return LDNS_STATUS_MEM_ERR;
	}

	rdf = ldns_native2rdf_int8(LDNS_RDF_TYPE_INT8,
			(uint8_t)certificate_usage);
	if (rdf == NULL) {
		goto memerror;
	}
	(void) ldns_rr_set_rdf(*tlsa, rdf, 0);

	rdf = ldns_native2rdf_int8(LDNS_RDF_TYPE_INT8, (uint8_t)selector);
	if (rdf == NULL) {
		goto memerror;
	}
	(void) ldns_rr_set_rdf(*tlsa, rdf, 1);

	rdf = ldns_native2rdf_int8(LDNS_RDF_TYPE_INT8, (uint8_t)matching_type);
	if (rdf == NULL) {
		goto memerror;
	}
	(void) ldns_rr_set_rdf(*tlsa, rdf, 2);

	s = ldns_dane_cert2rdf(&rdf, cert, selector, matching_type);
	if (s == LDNS_STATUS_OK) {
		(void) ldns_rr_set_rdf(*tlsa, rdf, 3);
		return LDNS_STATUS_OK;
	}
	ldns_rr_free(*tlsa);
	*tlsa = NULL;
	return s;

memerror:
	ldns_rr_free(*tlsa);
	*tlsa = NULL;
	return LDNS_STATUS_MEM_ERR;
}


/* Return tlsas that actually are TLSA resource records with known values
 * for the Certificate usage, Selector and Matching type rdata fields.
 */
static ldns_rr_list*
ldns_dane_filter_unusable_records(const ldns_rr_list* tlsas)
{
	size_t i;
	ldns_rr_list* r = ldns_rr_list_new();
	ldns_rr* tlsa_rr;

	if (! r) {
		return NULL;
	}
	for (i = 0; i < ldns_rr_list_rr_count(tlsas); i++) {
		tlsa_rr = ldns_rr_list_rr(tlsas, i);
		if (ldns_rr_get_type(tlsa_rr) == LDNS_RR_TYPE_TLSA &&
		    ldns_rr_rd_count(tlsa_rr) == 4 &&
		    ldns_rdf2native_int8(ldns_rr_rdf(tlsa_rr, 0)) <= 3 &&
		    ldns_rdf2native_int8(ldns_rr_rdf(tlsa_rr, 1)) <= 1 &&
		    ldns_rdf2native_int8(ldns_rr_rdf(tlsa_rr, 2)) <= 2) {

			if (! ldns_rr_list_push_rr(r, tlsa_rr)) {
				ldns_rr_list_free(r);
				return NULL;
			}
		}
	}
	return r;
}


/* Return whether cert/selector/matching_type matches data.
 */
static ldns_status
ldns_dane_match_cert_with_data(X509* cert, ldns_tlsa_selector selector,
		ldns_tlsa_matching_type matching_type, ldns_rdf* data)
{
	ldns_status s;
	ldns_rdf* match_data;

	s = ldns_dane_cert2rdf(&match_data, cert, selector, matching_type);
	if (s == LDNS_STATUS_OK) {
		if (ldns_rdf_compare(data, match_data) != 0) {
			s = LDNS_STATUS_DANE_TLSA_DID_NOT_MATCH;
		}
		ldns_rdf_free(match_data);
	}
	return s;
}


/* Return whether any certificate from the chain with selector/matching_type
 * matches data.
 * ca should be true if the certificate has to be a CA certificate too.
 */
static ldns_status
ldns_dane_match_any_cert_with_data(STACK_OF(X509)* chain,
		ldns_tlsa_selector      selector,
		ldns_tlsa_matching_type matching_type,
		ldns_rdf* data, bool ca)
{
	ldns_status s = LDNS_STATUS_DANE_TLSA_DID_NOT_MATCH;
	size_t n, i;
	X509* cert;

	n = (size_t)sk_X509_num(chain);
	for (i = 0; i < n; i++) {
		cert = sk_X509_pop(chain);
		if (! cert) {
			s = LDNS_STATUS_SSL_ERR;
			break;
		}
		s = ldns_dane_match_cert_with_data(cert,
				selector, matching_type, data);
		if (ca && s == LDNS_STATUS_OK && ! X509_check_ca(cert)) {
			s = LDNS_STATUS_DANE_NON_CA_CERTIFICATE;
		}
		X509_free(cert);
		if (s != LDNS_STATUS_DANE_TLSA_DID_NOT_MATCH) {
			break;
		}
		/* when s == LDNS_STATUS_DANE_TLSA_DID_NOT_MATCH,
		 * try to match the next certificate
		 */
	}
	return s;
}


ldns_status
ldns_dane_verify_rr(const ldns_rr* tlsa_rr,
		X509* cert, STACK_OF(X509)* extra_certs,
		X509_STORE* pkix_validation_store)
{
	ldns_status s;

	STACK_OF(X509)* pkix_validation_chain = NULL;

	ldns_tlsa_certificate_usage cert_usage;
	ldns_tlsa_selector          selector;
	ldns_tlsa_matching_type     matching_type;
	ldns_rdf*                   data;

	if (! tlsa_rr) {
		/* No TLSA, so regular PKIX validation
		 */
		return ldns_dane_pkix_validate(cert, extra_certs,
				pkix_validation_store);
	}
	cert_usage    = ldns_rdf2native_int8(ldns_rr_rdf(tlsa_rr, 0));
	selector      = ldns_rdf2native_int8(ldns_rr_rdf(tlsa_rr, 1));
	matching_type = ldns_rdf2native_int8(ldns_rr_rdf(tlsa_rr, 2));
	data          =                      ldns_rr_rdf(tlsa_rr, 3) ;

	switch (cert_usage) {
	case LDNS_TLSA_USAGE_CA_CONSTRAINT:
		s = ldns_dane_pkix_validate_and_get_chain(
				&pkix_validation_chain, 
				cert, extra_certs,
				pkix_validation_store);
		if (! pkix_validation_chain) {
			return s;
		}
		if (s == LDNS_STATUS_DANE_PKIX_DID_NOT_VALIDATE) {
			/*
			 * NO PKIX validation. We still try to match *any*
			 * certificate from the chain, so we return
			 * TLSA errors over PKIX errors.
			 *
			 * i.e. When the TLSA matches no certificate, we return
			 * TLSA_DID_NOT_MATCH and not PKIX_DID_NOT_VALIDATE
			 */
			s = ldns_dane_match_any_cert_with_data(
					pkix_validation_chain,
					selector, matching_type, data, true);

			if (s == LDNS_STATUS_OK) {
				/* A TLSA record did match a cert from the
				 * chain, thus the error is failed PKIX
				 * validation.
				 */
				s = LDNS_STATUS_DANE_PKIX_DID_NOT_VALIDATE;
			}

		} else if (s == LDNS_STATUS_OK) { 
			/* PKIX validated, does the TLSA match too? */

			s = ldns_dane_match_any_cert_with_data(
					pkix_validation_chain,
					selector, matching_type, data, true);
		}
		sk_X509_pop_free(pkix_validation_chain, X509_free);
		return s;
		break;

	case LDNS_TLSA_USAGE_SERVICE_CERTIFICATE_CONSTRAINT:
		s = ldns_dane_match_cert_with_data(cert,
				selector, matching_type, data);

		if (s == LDNS_STATUS_OK) {
			return ldns_dane_pkix_validate(cert, extra_certs,
					pkix_validation_store);
		}
		return s;
		break;

	case LDNS_TLSA_USAGE_TRUST_ANCHOR_ASSERTION:
		s = ldns_dane_pkix_get_chain(&pkix_validation_chain,
				cert, extra_certs);

		if (s == LDNS_STATUS_OK) {
			s = ldns_dane_match_any_cert_with_data(
					pkix_validation_chain,
					selector, matching_type, data, false);

		} else if (! pkix_validation_chain) {
			return s;
		}
		sk_X509_pop_free(pkix_validation_chain, X509_free);
		return s;
		break;

	case LDNS_TLSA_USAGE_DOMAIN_ISSUED_CERTIFICATE:
		return ldns_dane_match_cert_with_data(cert,
				selector, matching_type, data);
		break;

	default:
		break;
	}
	return LDNS_STATUS_DANE_UNKNOWN_CERTIFICATE_USAGE;
}


ldns_status
ldns_dane_verify(ldns_rr_list* tlsas,
		X509* cert, STACK_OF(X509)* extra_certs,
		X509_STORE* pkix_validation_store)
{
	size_t i;
	ldns_rr* tlsa_rr;
	ldns_status s = LDNS_STATUS_OK, ps;

	assert(cert != NULL);

	if (tlsas && ldns_rr_list_rr_count(tlsas) > 0) {
		tlsas = ldns_dane_filter_unusable_records(tlsas);
		if (! tlsas) {
			return LDNS_STATUS_MEM_ERR;
		}
	}
	if (! tlsas || ldns_rr_list_rr_count(tlsas) == 0) {
		/* No TLSA's, so regular PKIX validation
		 */
		return ldns_dane_pkix_validate(cert, extra_certs,
				pkix_validation_store);
	} else {
		for (i = 0; i < ldns_rr_list_rr_count(tlsas); i++) {
			tlsa_rr = ldns_rr_list_rr(tlsas, i);
			ps = s;
			s = ldns_dane_verify_rr(tlsa_rr, cert, extra_certs,
					pkix_validation_store);

			if (s != LDNS_STATUS_DANE_TLSA_DID_NOT_MATCH &&
			    s != LDNS_STATUS_DANE_PKIX_DID_NOT_VALIDATE) {

				/* which would be LDNS_STATUS_OK (match)
				 * or some fatal error preventing use from
				 * trying the next TLSA record.
				 */
				break;
			}
			s = (s > ps ? s : ps); /* prefer PKIX_DID_NOT_VALIDATE
						* over   TLSA_DID_NOT_MATCH
						*/
		}
		ldns_rr_list_free(tlsas);
	}
	return s;
}
#endif /* HAVE_SSL */
