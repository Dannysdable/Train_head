/*
 * 数据链路层
 */

#define ETH_ALEN        6               /* Octets in one ethernet addr   */

struct packet_ethhdr {
  unsigned char   h_dest[ETH_ALEN];       /* destination eth addr */
	unsigned char   h_source[ETH_ALEN];     /* source ether addr    */
	uint16_t        h_proto;                /* packet type ID field */
};
