/*
* file: main.c
* 
* 2013-05-05
* 
* if 0 部分为未调试部分
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

#define INTERFACE "eth0"
#define MAXBUF 65535
/*
*/


/*Create raw sockets*/
int Open_Raw_Socket(void);

int main()
{
	int sock, bytes_recieved, fromlen;
	char buffer[MAXBUF];
	struct sockaddr_in from;
	struct ip *ip;
	struct tcp *tcp;

	sock = Open_Raw_Socket();

	
	while (1)
	{
		fromlen = sizeof(from);
		bytes_recieved = recvfrom(sock, buffer, sizeof(buffer), 0, 
					(struct sockaddr *)&from, &fromlen);
		printf("\nBytes received :: %5d\n", bytes_recieved);

		ip = (struct ip *)buffer;

		printf("Source address:: %s\n", inet_ntoa(ip->ip_source));
		printf("Source address:: %s\n", inet_ntoa(ip->ip_dest));
		printf("IP header length :: %d\n", ip->ip_length);
		printf("Protocol :: %d\n", ip->ip_protocol);

		tcp = (struct tcp *)(buffer + (4*ip->ip_length));

		printf("Source port :: %d\n", ntohs(tcp->tcp_source_port));
		printf("Dest port :: %d\n", ntohs(tcp->tcp_dest_port));
	}
}

/*Create raw sockets*/
int Open_Raw_Socket()
{
	int sock; 
	if((sock = socket(AF_INET, SOCK_RAW, IPPROTO_TCP)) < 0)
	{
		/*Then the socket was not created properly and must die*/
		perror("The raw socket was not created");
		return 0;
	}
	return(sock); 
}
/********************Done************************************************/
/************************************************************************/
#if 0
int Set_Promisc(char *interface, int sock);
Set_Promisc(INTERFACE, sock);
#endif
#if 0
/*Set the network card to promiscuous mode*/
int Set_Promisc(char *interface, int sock )
{
	struct ifreq ifr;
	strncpy(ifr.ifr_name, interface,strnlen(interface)+1);

	if((ioctl(sock, SIOCGIFFLAGS, &ifr) == -1))
	{
		/*Could not retrieve flags for the interface*/
		perror("Could not retrive flags for the interface");
		return 0;
	}
	printf("The interface is ::: %s\n", interface);
	perror("Retrieved flags from interface successfully");
	ifr.ifr_flags |= IFF_PROMISC;

	if (ioctl (sock, SIOCSIFFLAGS, &ifr) == -1 )
	{
		/*Could not set the flags on the interface */
		perror("Could not set the PROMISC flag:");
		return 0;
	}
	printf("Setting interface ::: %s ::: to promisc", interface);
	
	return 0;
}
#endif
