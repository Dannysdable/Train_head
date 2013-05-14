#ifndef _PACKET_H
#define _PACKET_H

#include <sys/types.h>
#include <netinet/in.h>
/*
 * 数据链路层
 */

#define ETH_ALEN        6               /* Octets in one ethernet addr   */

struct packet_ethhdr {
	unsigned char   h_dest[ETH_ALEN];       /* destination eth addr */
	unsigned char   h_source[ETH_ALEN];     /* source ether addr    */
	u_int16_t        h_proto;                /* packet type ID field */
};
/*
 * IP层
 */
/* structure of an ip */
struct packet_ip {
	unsigned int ip_length:4;   /* Version */
	unsigned int ip_version:4;  /* Internet Header Length;IHL */
	u_int8_t ip_tos;            /* Type of Service;TOS */
	u_short ip_total_length;    /* Total Length;TL */
	u_short ip_id;              /* Identification */
	u_short ip_flags;           /* Flags */
#define IP_RF 0x8000             /* reserved fragment flag */
#define IP_DF 0x4000             /* dont fragment flag */
#define IP_MF 0x2000             /* more fragments flag */
#define IP_OFFMASK 0x1fff        /* mask for fragmenting bits */
	u_int8_t ip_ttl;            /* Time To Live;TTL */
	u_int8_t ip_protocol;       /* Protocol;PROT */
	u_short ip_cksum;           /* Header checksum */
	struct in_addr ip_source;   /* Source Address;SA */
	struct in_addr ip_dest;     /* Destination Address;DA */
};
/*
 * TCP层
 */
/* Structure of a TCP header */
struct packet_tcp {
	u_int16_t tcp_source_port;    /* Source Port */
	u_int16_t tcp_dest_port;      /* Destination Port */
	u_int32_t tcp_seqno;          /* Sequence Number */
	u_int32_t tcp_ackno;          /* Acknowledgment Number */
	u_int16_t tcp_res1:4;         /* Data Offset */
	u_int16_t tcp_hlen:4;         /* Reserved */
	u_int16_t tcp_res2:2;         /* Reserved */
	u_int16_t tcp_urg:1;
	u_int16_t tcp_ack:1;
	u_int16_t tcp_psh:1;
	u_int16_t tcp_rst:1;
	u_int16_t tcp_syn:1;
	u_int16_t tcp_fin:1;
	u_int16_t tcp_winsize;        /* Window */
	u_int16_t tcp_cksum;          /* Checksum */
	u_int16_t tcp_urgent;         /* Urgent Pointer */
};


struct packet {
	struct packet_ethhdr eth;
	struct packet_ip ip;
	struct packet_tcp tcp;
	char data[0];
};

#endif
