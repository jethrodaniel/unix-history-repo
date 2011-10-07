/*-
 * Copyright (c) 2005 by Marius Strobl <marius@FreeBSD.org>.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions, and the following disclaimer,
 *    without modification, immediately at the beginning of the file.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * $FreeBSD$
 */

#ifndef _SPARC64_PCI_SCHIZOVAR_H_
#define	_SPARC64_PCI_SCHIZOVAR_H_

struct schizo_softc;

struct schizo_iommu_state {
	struct iommu_state	sis_is;
	struct schizo_softc	*sis_sc;
};

struct schizo_softc {
	struct bus_dma_methods          sc_dma_methods;

	device_t			sc_dev;

	struct mtx			sc_sync_mtx;
	uint64_t			sc_sync_val;

	struct mtx			*sc_mtx;

	phandle_t			sc_node;

	u_int				sc_mode;
#define	SCHIZO_MODE_SCZ			0
#define	SCHIZO_MODE_TOM			1
#define	SCHIZO_MODE_XMS			2

	u_int				sc_flags;
#define	SCHIZO_FLAGS_BSWAR		(1 << 0)
#define	SCHIZO_FLAGS_XMODE		(1 << 1)

	bus_addr_t			sc_cdma_clr;
	uint32_t			sc_cdma_state;
#define	SCHIZO_CDMA_STATE_IDLE		(1 << 0)
#define	SCHIZO_CDMA_STATE_PENDING	(1 << 1)
#define	SCHIZO_CDMA_STATE_RECEIVED	(1 << 2)

	u_int				sc_half;
	uint32_t			sc_ign;
	uint32_t			sc_ver;
	uint32_t			sc_mrev;

	struct resource			*sc_mem_res[TOM_NREG];
	struct resource			*sc_irq_res[STX_NINTR];
	void				*sc_ihand[STX_NINTR];

	struct schizo_iommu_state	sc_is;

	struct rman			sc_pci_mem_rman;
	struct rman			sc_pci_io_rman;
	bus_space_handle_t		sc_pci_bh[STX_NRANGE];
	bus_space_tag_t			sc_pci_cfgt;
	bus_space_tag_t			sc_pci_iot;
	bus_dma_tag_t			sc_pci_dmat;

	uint32_t			sc_stats_dma_ce;
	uint32_t			sc_stats_pci_non_fatal;

	uint8_t				sc_pci_secbus;
	uint8_t				sc_pci_subbus;

	struct ofw_bus_iinfo		sc_pci_iinfo;

	SLIST_ENTRY(schizo_softc)	sc_link;
};

#endif /* !_SPARC64_PCI_SCHIZOVAR_H_ */
