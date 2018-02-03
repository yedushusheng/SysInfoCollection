#include"string_util.h"

void check_null(p){ 
	if(p)
		return RTCODE_ERROR;
	else
		return RTCODE_SUCCESS;
}