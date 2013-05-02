#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/if_ether.h>  
#include <netinet/ip.h>  
#include <netinet/udp.h>  
#include <netinet/tcp.h> 

#include "process.h"
#include "func.h"

struct packet p;
struct packet *pkt = &p;
extern int length;
char *tmp_pkt;

void process_ether(char *ether)
{
	if(length < sizeof(struct ether_header)){
		return;
	}

	pkt->eth_head = (struct ether_header *)ether;

	tmp_pkt = ether + sizeof(struct ether_header);
	length -= sizeof(struct ether_header); 

	switch(pkt->eth_head->ether_type){
		case 0x0008:
			process_ip(tmp_pkt);
			break;
		default:
			break;
	}
}

void process_ip(char *ip_pkt)
{
	if(length < sizeof(struct iphdr)){
		return;
	}

	pkt->ip_head = (struct iphdr *)ip_pkt;

	tmp_pkt += sizeof(struct iphdr);
	length -= sizeof(struct iphdr);
	switch(pkt->ip_head->protocol){
		case 0x0006:
			process_tcp(tmp_pkt);
			break;
		default:
			break;
	}

}


void process_tcp(char *tcp_pkt)
{
	if(length < sizeof(struct tcphdr)){
		return;
	}

	pkt->tcp_head = (struct tcphdr *) tmp_pkt;

	tmp_pkt += sizeof(struct tcphdr);
	length -= sizeof(struct tcphdr);
	switch(htons(pkt->tcp_head->dest)){
		case 80:
			process_http(tmp_pkt);
			break;
		default:
			break;	
	}

}

void process_http(char *http_head)
{
	char *addr;	

	if(length < 30){
		return;
	}

	addr = get_between(http_head, "Host:", "\r\n", strlen("Host:"));

	if(addr == NULL){
		printf("Not get addr!!!");
		return;
	}else{
		print_pkt(pkt, addr);
		printf("\n");	
	}
}
