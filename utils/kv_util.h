#ifndef __KV_UTIL_H_
#define __KV_UTIL_H_

#include<stdint.h>
#include<glib.h>

typedef GKeyFile kv_data_t;

kv_data_t *kv_new();
int32_t kv_free(kv_data_t *kvdata);