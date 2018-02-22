#include <sys/types.h>
#include <sys/socker.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#include "net_util.h"
#include "log_util.h"

int32_t net_socket(int32_t family, int32_t type, int32_t protocol){
	int32_t ret = RTCODE_SUCCESS;
	ret = socket(family,type,protocol);
	if(ret == RTCODE_ERROR){
		log_error("socket(%d,%d,%d) call failed,error[%d] info is:%s.",family,type,protocol,errno,strerror(errno));
	}
	return ret;
}
