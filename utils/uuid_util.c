#include "uuid_util.h"

uuid_t null_uuid;
uuid_t one_uuid;
static pthread_key_t uuid_log_key;

/****************************************
* 函数名称: uuid_key_init
* 函数功能: 初始化uuid的key
* 入     参: 无
* 出     参: 无
* 返 回 值: ret 
* 备     注: 无
****************************************/
int32_t uuid_key_init(){
	int32_t ret = RTCODE_SUCCESS;

	ret = pthread_key_create(&uuid_log_key,uuid_key_destroy);
	if(RTCODE_ERROR == ret){
		log_error("pthread key create failed,sysinfo:'%m'");
		ret = RTCODE_ERROR;
	}
	else{
		ret = RTCODE_SUCCESS;
	}
	return ret;
}

/****************************************
* 函数名称: uuid_key_destroy
* 函数功能: 释放键key指针内存
* 入     参: void指针pointer
* 出     参: 无
* 返 回 值: 无
* 备     注: 无
****************************************/
void uuid_key_destroy(void * pointer){
	if(NULL != pointer){
		free(pointer);
		pointer = NULL;
	}
	return;
}

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