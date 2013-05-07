#if 0
struct in_addr {
	in_addr_t s_addr;
};
#endif

/* structure of an ip */
struct ip {
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

/* Structure of a TCP header */
struct tcp {
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


struct ifmap 
{
	unsigned long mem_start;
	unsigned long mem_end;
	unsigned short base_addr;
	unsigned char irq;
	unsigned char dma;
	unsigned char port;
	/* 3 bytes spare */
};

typedef struct {
	unsigned short encoding;
	unsigned short parity;
} raw_hdlc_proto;

typedef struct {
	unsigned int interval;
	unsigned int timeout;
} cisco_proto;

typedef struct {
	unsigned int t391;
	unsigned int t392;
	unsigned int n391;
	unsigned int n392;
	unsigned int n393;
	unsigned short lmi;
	unsigned short dce;	/* 1 for DCE (network side) operation */
} fr_proto;

typedef struct {
	unsigned int dlci;
} fr_proto_pvc;			/* for creating/deleting FR PVCs */

#define IFNAMSIZ 16
typedef struct {
	unsigned int dlci;
	char master[IFNAMSIZ];	/* Name of master FRAD device */
}fr_proto_pvc_info;		/* for returning PVC information only */

typedef struct {
	unsigned int clock_rate;/* bits per second */
	unsigned int clock_type;/* internal, external, TX-internal etc. */
	unsigned short loopback;
} sync_serial_settings;		/* V.35, V.24, X.21 */

typedef struct {
	unsigned int clock_rate; /* bits per second */
	unsigned int clock_type; /* internal, external, TX-internal etc. */
	unsigned short loopback;
	unsigned int slot_map;
} te1_settings;                  /* T1, E1 */

struct if_settings
{
	unsigned int type;      /* Type of physical device or protocol */
	unsigned int size;      /* Size of the data allocated by the caller */
	union {
		/* {atm/eth/dsl}_settings anyone ? */
		raw_hdlc_proto   *raw_hdlc;
		cisco_proto      *cisco;
		fr_proto         *fr;
		fr_proto_pvc     *fr_pvc;
		fr_proto_pvc_info *fr_pvc_info;

		/* interface settings */
		sync_serial_settings *sync;
		te1_settings     *te1;
	} ifs_ifsu;
};

#define IFNAMSIZ        16
struct ifreq 
{
#define IFHWADDRLEN     6
	union
	{
		char ifrn_name[IFNAMSIZ];	/* if name, e.g. "en0" */
	} ifr_ifrn;

	union {
		struct  sockaddr ifru_addr;
		struct  sockaddr ifru_dstaddr;
		struct  sockaddr ifru_broadaddr;
		struct  sockaddr ifru_netmask;
		struct  sockaddr ifru_hwaddr;
		short   ifru_flags;
		int     ifru_ivalue;
		int     ifru_mtu;
		struct  ifmap ifru_map;
		char    ifru_slave[IFNAMSIZ];   /* Just fits the size */
		char    ifru_newname[IFNAMSIZ];
		void *  ifru_data;
		struct  if_settings ifru_settings;
	} ifr_ifru;
};
