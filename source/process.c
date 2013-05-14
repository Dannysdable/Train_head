#include<stdio.h>
#include "func.h"
#include "packet.h"
#include "process.h"

char* get_url(char *data, int len)
{
	char *url;
	url = get_data_between(data, "Host: ", "\r\n", len);
	if(url != NULL){
		printf("url is %s\n", url);
	}else{
		return NULL;
	}

	return url;
}
