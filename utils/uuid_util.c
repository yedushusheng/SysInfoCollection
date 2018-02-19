#include "uuid_util.h"

uuid_t null_uuid;
uuid_t one_uuid;
static pthread_key_t uuid_log_key;

int32_t uuid_cpmpare(uuid_t uuid1, uuid_t uuid2){
	int32_t ret = RTCODE_SUCCESS;
	int32_t i = 0;
	for(i=0;i<4;i++){
		if(((int32_t *)uuid1)[i]!=((int32_t *)uuid2)[i])
			ret = RTCODE_ERROR;
		else
			ret = RTCODE_SUCCESS;
	}
	return ret;
}

int32_t uuid_str_is_valid(char * uuid_str){
	int32_t ret = RTCODE_SUCCESS;
	if(NULL == id)
		ret = RTCODE_ERROR;
	if(strlen(id) != 36)
		ret = RTCODE_ERROR;
	if(id[8]!="||id[13]!="||id[18]!="||id[23]!=")
		ret = RTCODE_ERROR;
	else
		ret = RTCODE_SUCCESS;
	return ret;
}