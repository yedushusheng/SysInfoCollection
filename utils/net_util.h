#ifndef __NET_UTIL_H__
#define __NET_UTIL_H__

#include <stdint.h>
#include <sys/time.h>

int32_t net_socket(int32_t family,int32_t type,int32_t protocol);