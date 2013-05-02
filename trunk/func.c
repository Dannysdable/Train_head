#include <stdio.h>
#include <sys/types.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/if_ether.h>  
#include <netinet/ip.h>  
#include <netinet/udp.h>  
#include <netinet/tcp.h>
#include "func.h"
//#include "process.h"

void print_hex(char *str, int len)
{
	u_char *tmp_str;
	tmp_str = (u_char *)str;
	int i;
	printf("Pcaket hex is: \n");
	for(i = 0; i < len; i++){
		if((i+1)%4 == 0){
			if(((i+1)%8 == 0)){
				printf("%02x\n", tmp_str[i]);
			}else{
				printf("%02x    ", tmp_str[i]);
			}
		}else{
			printf("%02x ", tmp_str[i]);
		}
	}               
	printf("\n");
}

char* get_between(char *src, char *head, char *end, int head_len)
{
	int len;
	
	char *src_head = strstr(src, head);
	if(src_head == NULL){
		return NULL;
	}

	char *src_end = strstr(src_head, end);
	if(src_end == NULL){
		return src_head;
	}else{
		len = src_end - src_head;
		src_head[len] = '\0';
		return src_head + head_len;
	}

	
}


void print_pkt(struct packet *pkt, char *addr)
{
	int i;	

	struct in_addr s_in;
	struct in_addr d_in;
	pkt->ip_head = (struct iphdr *)pkt->ip_head;

	s_in.s_addr = pkt->ip_head->saddr;
	d_in.s_addr = pkt->ip_head->daddr;

	
	printf("Packet source MAC is:");
	for(i=0; i<6; i++){
		printf("%02X ", pkt->eth_head->ether_shost[i]);
	}
	printf("\n");

	printf("Packet destination MAC is:");
		for(i=0; i<6; i++){
		printf("%02X ", pkt->eth_head->ether_dhost[i]);
	}
	printf("\n");

	printf("Packet source IP is: %s\n", inet_ntoa(s_in));
	printf("Packet destination IP is: %s\n", inet_ntoa(d_in));
	
	printf("Packet source IP is: %s\n", inet_ntoa(s_in));
	printf("Packet destination IP is: %s\n", inet_ntoa(d_in));

	printf("Http addr is: %s\n", addr);

	printf("\n");	
}
