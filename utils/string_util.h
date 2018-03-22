#ifndef _STRING_UTIL_H_
#define _STRING_UTIL_H_

void check_null(p);

int32_t str_to_int(char *str,int32_t base,int32_t num);
int32_t Strncpy(char *dst,char *src, int32_t max_len);
int32_t Str_trim(char *str);