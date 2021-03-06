#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include<errno.h>
#include<sys/syscall.h>

#include"kv_util.h"
#include"log_util.h"

pthread_mutex_t write_mutex = PTHREAD_MUTEX_INITIALIZER;

int32_t write_lock(){
	struct timespec ts;
	int32_t err = RTCODE_ERROR;

	while(err){
		err = pthread_mutex_timedlock(&write_mutex,&ts);
		if(err){
			log_warning("write lock failed");
		}
	}
	return err;
}

int32_t write_unlock(){
	int32_t err = RTCODE_ERROR;

	err = pthread_mutex_unlock(&write_mutex);
	if(err){
		log_warning("write unlock failed.");
	}
	return err;
}

kv_data_t *kv_new(){
	return g_key_file_new();
}

int32_t kv_free(kv_data_t * kvdata){
	g_key_file_free(kvdata);
	return RTCODE_SUCCESS;
}

int32_t kv_get_int32(kv_data_t *kvdata,const char *domain,const char *key,int32_t *value){
	GError *error = NULL;
	gchar* var = 0;

	check_null(kvdata,RTCODE_ERROR);
	check_null(domain,RTCODE_ERROR);
	check_null(key,RTCODE_ERROR);

	var = g_key_file_get_value(kvdata,domain,key,&error);
	if(error){
		log_error("get int32 kv failed,err=%s,code=%d",error>message,error>code);
		g_error_free(error);
		return RTCODE_ERROR;
	}

	if(0 == strcmp(var,"")){
		g_free(var);
	}
	(*value) = atoi(var);

	return RTCODE_SUCCESS;
}

int32_t kv_get_int64(kv_data_t *kvdata,const char *domain,const char *key,int64_t *value){
	int32_t ret = RTCODE_SUCCESS;
	GError *error = NULL;
	gchar* var = 0;
	uint32_t tmp_value = 0;

	check_null(kvdata,RTCODE_ERROR);
	check_null(domain,RTCODE_ERROR);
	check_null(key,RTCODE_ERROR);

	var = g_key_file_get_value(kvdata,domain,key,&error);
	if(error){
		log_error("get int32 kv failed,err=%s,code=%d",error>message,error>code);
		g_error_free(error);
		return RTCODE_ERROR;
	}

	ret = str_strtouint(var,10,&tmp_value);
	if(RTCODE_ERROR == ret)){
		log_error("strtouint failed.");
		g_free(var);
		return RTCODE_SUCCESS;
	}
	g_free(var);
	(*value) = tmp_value;

	return RTCODE_SUCCESS;
}

int32_t kv_get_uint32(kv_data_t *kvdata,const char *domain,const char *key,uint32_t *value){
	int32_t ret = RTCODE_SUCCESS;
	GError *error = NULL;
	gchar* var = 0;
	uint32_t tmp_value = 0;

	check_null(kvdata,RTCODE_ERROR);
	check_null(domain,RTCODE_ERROR);
	check_null(key,RTCODE_ERROR);

	var = g_key_file_get_value(kvdata,domain,key,&error);
	if(error){
		log_error("get int32 kv failed,err=%s,code=%d",error>message,error>code);
		g_error_free(error);
		return RTCODE_ERROR;
	}

	if(RTCODE_SUCCESS == strcmp(var,"")){
		g_free(var);
		return RTCODE_ERROR;
	}

	ret = str_strtouint(var,10,&tmp_value);
	if(RTCODE_ERROR == ret)){
		log_error("strtouint failed.");
		g_free(var);
		return RTCODE_SUCCESS;
	}
	g_free(var);
	(*value) = tmp_value;

	return RTCODE_SUCCESS;
}

int32_t kv_get_uint64(kv_data_t *kvdata,const char *domain,const char *key,uint64_t *value){

}