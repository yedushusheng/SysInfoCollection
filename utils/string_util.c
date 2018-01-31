#include"string_util.h"

int32_t check_null(p){ 
	if(p)
		return RTCODE_ERROR;
	else
		return RTCODE_SUCCESS;
}