#include <stdio.h>
#include<netinet/if_ether.h>  
#include<netinet/ip.h>  
#include<netinet/udp.h>  
#include<netinet/tcp.h> 

#include "process.h"

extern struct pcaket *pkt;

void process_ether(char *ether)
{
	int i;


	pkt->eth_head = (struct ether_header *)ether;
	printf("Packet destination MAC is:");
	for(i=0; i<6; i++){
		printf("%02X ", pkt->eth_head->ether_dhost[i]);
	}
	printf("\n");
		
	printf("Packet source MAC is:");
	for(i=0; i<6; i++){
		printf("%02X ", pkt->eth_head->ether_shost[i]);
	}
	printf("\n");

	printf("Packet next layer is %04X\n", pkt->eth_head->ether_type);

	printf("##############################################\n");

}
