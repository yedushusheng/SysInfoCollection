#include<stdlib.h>
#include<string.h>
#include<sys/type.h>

#include"thread_util.h"

int32_t thread_mutex_init(thread_mutex_t * mutex, thread_mutexattr_t * attr){
	int32_t ret = RTCODE_SUCCESS;
	ret = pthread_mutex_init((pthread_mutex_t*)mutex,(pthread_mutexattr_t*)attr);
	if(RTCODE_SUCCESS != ret){
		log_error("init thread mutex failed,ret=%d,err='%m'",ret);
	}
	return ret;
}

int32_t thread_mutex_lock(thread_mutex_t * mutex){
	int32_t ret = 0;
	ret = pthread_mutex_lock((pthread_mutex_t*)mutex);
	if(ret != 0){
		log_error("get mutex failed,return=%d,errno='%m'",ret);
	}
	return ret;
}

int32_t thread_mutex_unlock(thread_mutex_t * mutex){
	int32_t ret = 0;
	ret = pthread_mutex_unlock((pthread_mutex_t*)mutex);
	if(ret != 0){
		log_error("get mutex failed,return=%d,errno='%m'",ret);
	}
	return ret;
}