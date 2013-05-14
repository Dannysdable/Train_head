#include <stdio.h>
#include <string.h>
#include "func.h"


char * get_data_between(char *src, char *begin, char *end, int src_len)
{
	char *tmp_begin, *tmp_end, *tmp;
	if(src == NULL || begin == NULL ){
		return NULL;
	}

	tmp_begin = strstr(src, begin);
	if(tmp_begin == NULL){
		printf("Not find\n");
		return NULL;
	}

	tmp_end = strstr(tmp_begin, end);
	if(tmp_end != NULL){
		*tmp_end='\0';
	}
	tmp = tmp_begin + strlen(begin);

	return tmp;	
}

