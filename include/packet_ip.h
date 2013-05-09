/*
 * IP层
 */
/* structure of an ip */
struct packet_ip {
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
