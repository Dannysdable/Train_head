/*
* file: main.c
* 
* 2013-05-05
*/


#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#if 0
#include<stdlib.h>
#include<netinet/ip.h>
#include<netinet/tcp.h>
#include<netinet/igmp.h>
#endif

#include "main.h"
/*
*/

int main()
{
#if 0
#endif
	int sock, bytes_recieved, fromlen;
	char buffer[65535];
	struct sockaddr_in from;
	struct ip *ip;
	struct tcp *tcp;

	if ((sock = socket(AF_INET, SOCK_RAW, IPPROTO_TCP)) < 0)
	{
		printf("Creat socket faild\n");
		return 1;
	}

	while (1)
	{
		fromlen = sizeof(from);
		bytes_recieved = recvfrom(sock, buffer, sizeof(buffer), 0, 
					(struct sockaddr *)&from, &fromlen);
		printf("\nBytes received :: %5d\n", bytes_recieved);
		printf("Source address:: %s\n", inet_ntoa(from.sin_addr));

		ip = (struct ip *)buffer;

		printf("IP header length :: %d\n", ip->ip_length);
		printf("Protocol :: %d\n", ip->ip_protocol);

		tcp = (struct tcp *)(buffer + (4*ip->ip_length));

		printf("Source port :: %d\n", ntohs(tcp->tcp_source_port));
		printf("Dest port :: %d\n", ntohs(tcp->tcp_dest_port));
	}
}
