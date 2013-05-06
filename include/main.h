/*structure of an ip header*/
struct ip {
     unsigned int ip_length:4;          /*Version*/
     unsigned int ip_version:4;         /*Internet Header Length,IHL*/
     unsigned char ip_tos;              /*Type of Service,TOS*/
     unsigned short ip_total_length;    /*Total Length,TL*/
     unsigned short ip_id;              /*Identification*/
     unsigned short ip_flags;           /*Flags*/
     unsigned char ip_ttl;              /*Time To Live,TTL*/
     unsigned char ip_protocol;         /*Protocol,PROT*/
     unsigned short ip_cksum;           /*Header checksum*/
     unsigned int ip_source;            /*Source Address,SA*/
     unsigned int ip_dest;              /*Destination Address,DA*/
};

/* Structure of a TCP header */
struct tcp {
     unsigned short tcp_source_port;    /*Source Port*/
     unsigned short tcp_dest_port;      /*Destination Port*/
     unsigned int tcp_seqno;            /*Sequence Number*/
     unsigned int tcp_ackno;            /*Acknowledgment Number*/
     unsigned int tcp_res1:4,           /*Data Offset*/
               tcp_hlen:4,              /*Reserved*/
               tcp_res2:2               /*Reserved*/
               tcp_urg:1,
               tcp_ack:1,
               tcp_psh:1,
               tcp_rst:1,
               tcp_syn:1,
               tcp_fin:1;
     unsigned short tcp_winsize;        /*Window*/
     unsigned short tcp_cksum;          /*Checksum*/
     unsigned short tcp_urgent;         /*Urgent Pointer*/
};
