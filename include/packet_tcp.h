/*
 * TCP层
 */
/* Structure of a TCP header */
struct packet_tcp {
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
