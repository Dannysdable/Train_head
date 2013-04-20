#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <errno.h>
#include <pcap/pcap.h>

#include "process.h"

struct pcaket p;
struct pcaket *pkt = &p;

void pkt_process(u_char *user, const struct pcap_pkthdr *h, const u_char *bytes)
{
	int i;
	printf("Capture pcaket time is %s", ctime((const time_t *)&h->ts.tv_sec));
	printf("Cpature pcaket length is %d\n", h->caplen);
	printf("Pcaket real length is %d\n", h->len);

	printf("Pcaket hex is: \n");
	for(i = 0; i < h->caplen; i++){
		if((i+1)%4 == 0){
			if(((i+1)%8 == 0)){
				printf("%02x\n", bytes[i]);
			}else{
				printf("%02x	", bytes[i]);
			}
		}else{
			printf("%02x ", bytes[i]);
		}
	}		
	printf("\n");
	process_ether((char *)bytes);
}

int main(int argc, char **argv)
{
	char *strDev;
	char errbuf[PCAP_ERRBUF_SIZE];
	pcap_t *device;

	strDev = pcap_lookupdev(errbuf);

	if(!strDev){
		printf("pcap_lookupdev() failed with %s\n", errbuf);
		exit(1);
	}else{
		printf("Device %s is aviable\n", strDev);
	}

	strDev = "wlan0";	
//	strDev = argv[1];	

/*
 	 device = pcap_create(strDev, errbuf);

	if(!device){
		printf("pcap_create() failed with %s\n", errbuf);
		exit(1);
	}else{
		printf("pcap_create successed\n");
	}
*/
	memset(errbuf, 0, sizeof(errbuf));
	device = pcap_open_live(strDev, 65536, 1, 0, errbuf);
	if(!device){
		printf("pcap_open_live() failed with %s\n", errbuf);
		exit(1);
	}else{
		printf("pcap_open_live() successed\n");
	}

	int ret = pcap_loop(device, 0, pkt_process, NULL);
	if(ret < 0){
		printf("pcap_loop() failed with %s\n", strerror(errno));
		exit(-1);
	}else{
		printf("pcap_loop() ret\n");
	}

	return 0;
}
