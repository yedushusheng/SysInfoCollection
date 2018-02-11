#include "time_util.h"

void time_to_str(time_t time,char* time_str,int32_t length){
	struct tm localtime;

	localtime_r(&time,&localtime);
	strftime(time_str,length,"%F %T",&localtime);
	return;
}