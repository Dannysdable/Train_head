#ifndef PROCESS_H_
#define PROCESS_H_

struct packet{
	struct ether_header *eth_head;
	struct iphdr *ip_head;
	struct tcphdr *tcp_head;
	struct udphdr *udp_head;
	char data[0];
};

void process_ether(char *ether);

void process_ip(char *ip_pkt);

void process_tcp(char *tcp_pkt);

void process_http(char *http_pkt);

#endif
