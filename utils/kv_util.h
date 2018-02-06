#ifndef __KV_UTIL_H_
#define __KV_UTIL_H_

#include<stdint.h>
#include<glib.h>

typedef GKeyFile kv_data_t;

kv_data_t *kv_new();
int32_t kv_free(kv_data_t *kvdata);
int32_t kv_get_int32(kv_data_t *kvdata,const char *domain,const char *key,int32_t *value);
int32_t kv_get_int64(kv_data_t *kvdata,const char *domain,const char *key,int64_t *value);
int32_t kv_get_uint32(kv_data_t *kvdata,const char *domain,const char *key,uint32_t *value);
int32_t kv_get_uint64(kv_data_t *kvdata,const char *domain,const char *key,uint64_t *value);