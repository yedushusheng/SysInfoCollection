#ifndef _LOG_UTIL_H_
#define _LOG_UTIL_H_

#define log_info(format,args...){\
	do{\
		//\
	}\
while(0)
		
#define log_warning(format,args...){\
	do{\
		log_info(format,##args);\
	}\
while(0)
	
#define log_error(format,args...){\
	do{\
		log_info(format,##args);\
	}\
while(0)
	
#define log_fatal(format,args...){\
	do{\
		log_info(format,##args);
	}\
while(0)