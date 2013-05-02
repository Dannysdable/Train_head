#ifndef FUNC_H_
#define FUNC_H_
#include "process.h"


void print_hex(char *str, int len);

char* get_between(char *src, char *head, char *end, int head_len);

void print_pkt(struct packet *pkt, char *addr);

#endif
