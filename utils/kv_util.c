#include"kv_util.h"

kv_data_t *kv_new(){
	return g_key)file_new();
}

int32_t kv_free(kv_data_t * kvdata){
	g_key_file_free(kvdata);
	return RTCODE_SUCCESS;
}