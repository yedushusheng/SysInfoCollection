#include"string_util.h"

void check_null(p){ 
	if(p)
		return RTCODE_ERROR;
	else
		return RTCODE_SUCCESS;
}

int32_t str_to_int(char * str, int32_t base, int32_t num){

}

int32_t Strncpy(char * dst, char *src, int32_t max_len){
	int32_t ret = RTCODE_SUCCESS;

	check_null(str, RTCODE_ERROR);
	strncpy(dst,src,max_len);
	dst[max_len-1] = '\0';

	return RTCODE_SUCCESS;
}