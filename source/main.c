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
#include<string.h>
#include<sys/types.h>
#if 0
#include<stdlib.h>
#include<netinet/ip.h>
#include<netinet/tcp.h>
#include<netinet/igmp.h>
#endif


#include "main.h"

#define INTERFACE 	"eth0"
#define MAXBUF		65535
#define ETH_P_ALL 	0x0003	/* every packet (be careful!!!) */
#define SIOCGIFFLAGS    0x8913	/* get flags                    */
#define IFF_PROMISC     0x100	/* receive all packets          */
#define SIOCSIFFLAGS    0x8914	/* set flags                    */
/*
 */


/*create raw sockets*/
int open_raw_socket (int sock);

int set_promisc (char *interface, int sock);

	int
main ()
{
	int sock, bytes_recieved;
	socklen_t fromlen;
	char buffer[MAXBUF];

	struct sockaddr_in from;
	struct packet *packet;

	//Open_Raw_Socket(sock);
	if ((sock = socket (PF_PACKET, SOCK_RAW, htons (ETH_P_ALL))) < 0)
	{
		/*Then the socket was not created properly and must die */
		perror ("The raw socket was not created");
		return 0;
	}

	//Set_Promisc(INTERFACE, sock);

	while (1)
	{
		fromlen = sizeof (from);
		memset (buffer, 0, MAXBUF);
		bytes_recieved = recvfrom(sock, buffer, sizeof(buffer), 0, (struct sockaddr *)&from, &fromlen);
		//bytes_recieved = recvfrom (sock, buffer, MAXBUF, 0, NULL, NULL);
		printf ("\nBytes received :: %5d\n", bytes_recieved);
		packet = (struct packet *) buffer;
	
	
		printf ("Source address :: %06x\n", (unsigned int)packet->eth.h_dest);
		printf ("Source address :: %06x\n", (unsigned int)packet->eth.h_source);
	}

	return 0;
}

/********************Done************************************************/
/************************************************************************/
#if 0
/*Set the network card to promiscuous mode*/
	int
Set_Promisc (char *interface, int sock)
{
	struct ifreq ifr;
	strncpy (ifr.ifr_ifrn.ifrn_name, interface, strnlen (interface) + 1);

	if ((ioctl (sock, SIOCGIFFLAGS, &ifr) == -1))
	{
		/*Could not retrieve flags for the interface */
		perror ("Could not retrive flags for the interface");
		return 0;
	}
	printf ("The interface is ::: %s\n", interface);
	perror ("Retrieved flags from interface successfully");
	ifr.ifr_ifru.ifru_flags |= IFF_PROMISC;

	/*DEBUG*/
	printf (" This fake error is in %s on line %d\n ", __FILE__,__LINE__);

	if (ioctl (sock, SIOCSIFFLAGS, &ifr) == -1)
	{
		/*Could not set the flags on the interface */
		perror ("Could not set the PROMISC flag:");
		return 0;
	}
	printf ("Setting interface ::: %s ::: to promisc", interface);

	return 0;
}
#endif
