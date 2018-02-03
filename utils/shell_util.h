#ifndef _SHELL_UTIL_H_
#define _SHELL_UTIL_H_

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<file.h>

#include"basic_util.h"
#include"string_util.h"

void shell_exec(const char * command, char * buffer, int32_t buffer_length);