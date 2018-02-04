#include<stdlib.h>
#include<string.h>
#include<sys/type.h>

#include"thread_util.h"

int32_t thread_mutex_init(thread_mutex_t * mutex, thread_mutexattr_t * attr){
	int32_t ret = RTCODE_SUCCESS;
	ret = pthread_mutex_init((pthread_mutex_t*)mutex,(pthread_mutexattr_t*)attr);
	if(RTCODE_ERROR == ret){
		log_error("init thread mutex failed,ret=%d,err='%m'",ret);
	}
	return ret;
}

int32_t thread_mutex_lock(thread_mutex_t * mutex){
	int32_t ret = RTCODE_SUCCESS;
	ret = pthread_mutex_lock((pthread_mutex_t*)mutex);
	if(RTCODE_ERROR == ret){
		log_error("get thread mutex lock failed,return=%d,errno='%m'",ret);
	}
	return ret;
}

int32_t thread_mutex_timedlock(thread_mutex_t * mutex, const struct timespec * timeout){
	int32_t ret = RTCODE_SUCCESS;
	ret = pthread_mutex_timedlock((pthread_mutex_t *mutex),timeout);
	if(RTCODE_ERROR == ret){
		log_error("get thread mutex timelock failed,ret=%d,errno='%m'",ret);
	}
	return ret;
}

int32_t thread_mutex_unlock(thread_mutex_t * mutex){
	int32_t ret = RTCODE_SUCCESS;
	ret = pthread_mutex_unlock((pthread_mutex_t*)mutex);
	if(RTCODE_ERROR == ret){
		log_error("get mutex failed,return=%d,errno='%m'",ret);
	}
	return ret;
}

int32_t thread_mutex_destroy(thread_mutexattr_t * mutex){
	int32_t ret = RTCODE_SUCCESS;
	ret = pthread_mutex_destroy((pthread_mutex_t *)mutex);
	if(RTCODE_ERROR == ret){
		log_error("destroy thread mutex failed,ret=%d,errno='%m'",ret);
	}
	return ret;
}

int32_t thread_rwlock_init(thread_rwlock_t * rwlock, thread_rwlockattr_t * attr){
	int32_t ret = RTCODE_SUCCESS;
	ret = pthread_rwlock_init((pthread_rwlock_t *)rwlock,(pthread_rwlockattr_t *)attr);
	if(RTCODE_ERROR == ret){
		log_error("init thread rwlock failed,ret=%d,errno='%m'",ret);
	}
	return ret;
}

int32_t thread_rwlock_rdlock(thread_rwlock_t * rwlock){
	int32_t ret = RTCODE_SUCCESS;
	ret = pthread_rwlock_rdlock((pthread_rwlock_t *)rwlock);
	if(RTCODE_ERROR == ret){
		log_error("get thread lock failed,ret=%d,errno='%m'",ret);
	}
	return ret;
}

int32_t thread_rwlock_wrlock(thread_rwlock_t * rwlock){
	int32_t ret = RTCODE_SUCCESS;
	ret = pthread_rwlock_wrlock((pthread_rwlock_t *)rwlock);
	if(RTCODE_ERROR == ret){
		log_error("get thread lock failed,ret=%d,errno='%m'",ret);
	}
	return ret;
}

int32_t thread_rwlock_unlock(thread_rwlock_t * rwlock){
	int32_t ret = RTCODE_SUCCESS;
	ret = pthread_rwlock_unlock((pthread_rwlock_t *)rwlock);
	if(RTCODE_ERROR == ret){
		log_error("get thread lock failed,ret=%d,errno='%m'",ret);
	}
	return ret;
}

int32_t thread_rwlock_destroy(thread_rwlock_t * rwlock){
	int32_t ret = RTCODE_SUCCESS;
	ret = pthread_rwlock_destroyk((pthread_rwlock_t *)rwlock);
	if(RTCODE_ERROR == ret){
		log_error("get thread lock failed,ret=%d,errno='%m'",ret);
	}
	return ret;
}