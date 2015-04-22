#include "sockaddrtest.h"

class socktoaTest : public sockaddrtest {
};

TEST_F(socktoaTest, IPv4AddressWithPort) {
	sockaddr_u input = CreateSockaddr4("192.0.2.10", 123);

	EXPECT_STREQ("192.0.2.10", socktoa(&input));
	EXPECT_STREQ("192.0.2.10:123", sockporttoa(&input));
}

TEST_F(socktoaTest, IPv6AddressWithPort) {
	const struct in6_addr address = {
		0x20, 0x01, 0x0d, 0xb8,
		0x85, 0xa3, 0x08, 0xd3, 
		0x13, 0x19, 0x8a, 0x2e,
		0x03, 0x70, 0x73, 0x34
	};

	const char* expected =
		"2001:db8:85a3:8d3:1319:8a2e:370:7334";
	const char* expected_port = 
		"[2001:db8:85a3:8d3:1319:8a2e:370:7334]:123";

	sockaddr_u input;
	memset(&input, 0, sizeof(input));
	AF(&input) = AF_INET6;
	SET_ADDR6N(&input, address);
	SET_PORT(&input, 123);

	EXPECT_STREQ(expected, socktoa(&input));
	EXPECT_STREQ(expected_port, sockporttoa(&input));
}

#ifdef ISC_PLATFORM_HAVESCOPEID
TEST_F(socktoaTest, ScopedIPv6AddressWithPort) {
	const struct in6_addr address = {
		0xfe, 0x80, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00,
		0x02, 0x12, 0x3f, 0xff, 
		0xfe, 0x29, 0xff, 0xfa
	};

	const char* expected =
		"fe80::212:3fff:fe29:fffa%5";
	const char* expected_port = 
		"[fe80::212:3fff:fe29:fffa%5]:123";

	sockaddr_u input;
	memset(&input, 0, sizeof(input));
	AF(&input) = AF_INET6;
	SET_ADDR6N(&input, address);
	SET_PORT(&input, 123);
	SCOPE_VAR(&input) = 5;

	EXPECT_STREQ(expected, socktoa(&input));
	EXPECT_STREQ(expected_port, sockporttoa(&input));
}
#endif	/* ISC_PLATFORM_HAVESCOPEID */

TEST_F(socktoaTest, HashEqual) {
	sockaddr_u input1 = CreateSockaddr4("192.00.2.2", 123);
	sockaddr_u input2 = CreateSockaddr4("192.0.2.2", 123);

	ASSERT_TRUE(IsEqual(input1, input2));
	EXPECT_EQ(sock_hash(&input1), sock_hash(&input2));
}

TEST_F(socktoaTest, HashNotEqual) {
	/* These two addresses should not generate the same hash. */
	sockaddr_u input1 = CreateSockaddr4("192.0.2.1", 123);
	sockaddr_u input2 = CreateSockaddr4("192.0.2.2", 123);

	ASSERT_FALSE(IsEqual(input1, input2));
	EXPECT_NE(sock_hash(&input1), sock_hash(&input2));
}

TEST_F(socktoaTest, IgnoreIPv6Fields) {
	const struct in6_addr address = {
		0x20, 0x01, 0x0d, 0xb8,
        0x85, 0xa3, 0x08, 0xd3, 
        0x13, 0x19, 0x8a, 0x2e,
        0x03, 0x70, 0x73, 0x34
	};

	sockaddr_u input1, input2;

	input1.sa6.sin6_family = AF_INET6;
	input1.sa6.sin6_addr = address;
	input1.sa6.sin6_flowinfo = 30L; // This value differs from input2.
	SET_PORT(&input1, NTP_PORT);

	input2.sa6.sin6_family = AF_INET6;
	input2.sa6.sin6_addr = address;
	input2.sa6.sin6_flowinfo = 10L; // This value differs from input1.
	SET_PORT(&input2, NTP_PORT);

	EXPECT_EQ(sock_hash(&input1), sock_hash(&input2));
}
