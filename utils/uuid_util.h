#ifndef __UUID_UTIL_H__
#define __UUID_UTIL_H__

#include "basic_util.h"
#include "log_util.h"

int32_t uuid_key_init();
void uuid_key_destroy(void *pointer);
char *uuid_unparse(uuid_t uuid);
int32_t uuid_cpmpare(uuid_t uuid1,uuid_t uuid2);
int32_t uuid_str_is_valid(char *uuid_str);

extern uuid_t null_uuid;

#endif