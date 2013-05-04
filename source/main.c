/*
* file: main.c
* 
* 2013-05-05
*/


#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netinet/ip.h>
#include<netinet/tcp.h>
#include<netinet/igmp.h>
#include<arpa/inet.h>

/*
*/

int main()
{
	int sock, bytes_recieved, fromlen;
	char buffer[65535];
	struct sockaddr_in from;
	struct ip *ip;
	struct tcphdr *tcphdr;

	sock = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);

	while(1)
	{
		fromlen = sizeof(from);
		bytes_recieved = recvfrom(sock, buffer, sizeof(buffer), 0, 
					(struct sockaddr *)&from, &fromlen);
		printf("\nBytes received :: %5d\n", bytes_recieved);
		printf("Source address:: %s\n", inet_ntoa(from.sin_addr));

		ip = (struct ip *)buffer;

		printf("IP header length :: %d\n", ip->ip_hl);
		printf("Protocol :: %d\n", ip->ip_p);

		tcphdr = (struct tcphdr *)(buffer + (4*ip->ip_hl));

		printf("Source port :: %d\n", ntohs(tcphdr->source));
		printf("Dest port :: %d\n", ntohs(tcphdr->dest));
	}
}
