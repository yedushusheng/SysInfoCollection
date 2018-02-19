#include "uuid_util.h"

struct uuid_log{
	int32_t index;
	char uuid_str[50][40];
};

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

/****************************************
* 函数名称: uuid_unparse
* 函数功能: 解析uuid
* 入     参: uuid
* 出     参: 无
* 返 回 值: ret 
* 备     注: 无
****************************************/
char *uuid_unparse(uuid_t uuid){
	int32_t index = 0;
	struct uuid_log *uuid_log_buf = NULL;
	uuid_log_buf = (struct uuid_log*)pthread_getspecific(uuid_log_key);

	if(NULL == uuid_log_buf){
		uuid_log_buf = (struct uuid_log *)calloc(1,sizeof(struct uuid_log));
		if(NULL == uuid_log_buf){
			log_error("calloc buffer for uuid log buffer failed,sysinfo:'%m'");
			return NULL;
		}
	}
	if(pthread_setspecific(uuid_log_key,uuid_log_buf)!=0){
		log_error("pthread set specific failed,sysinfo:'%m'");
		return NULL;
	}

	(uuid_log_buf->index)++;
	if(uuid_log_buf->index >= 50){
		uuid_log_buf->index = 0;
	}

	index = uuid_log_buf->index;
	uuid_unparse(uuid,uuid_log_buf->uuid_str[index]);

	return uuid_log_buf->uuid_str[index];
}

/****************************************
* 函数名称: uuid_cpmpare
* 函数功能: 比较两个uuid
* 入     参: uuid1，uuid2
* 出     参: 无
* 返 回 值: ret 
* 备     注: 无
****************************************/
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

/****************************************
* 函数名称: uuid_str_is_valid
* 函数功能: 判断uuid的字符串是否有效
* 入     参: char类型指针uuid_str
* 出     参: 无
* 返 回 值: ret 
* 备     注: 无
****************************************/
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