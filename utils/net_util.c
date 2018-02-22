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

int32_t net_listen(int sock_fd, int32_t back_log){
	int32_t ret = RTCODE_SUCCESS;
	ret = listen(sock_fd,back_log);
	if(RTCODE_ERROR == ret){
		log_error("listen(%d,%d,%d)call failed,error[%d] info is:%s.",sock_fd,back_log,errno,strerror(errno));
	}
	return ret;
}

int32_t net_accept(int sock_fd, struct sockaddr * addr, socklen_t * addr_len){
	int conn_fd = 0;
	conn_fd = accept(sock_fd,addr,addr_len);
	if(conn_fd < 0){
		log_error("accept(%d,%d,%d)call failed,error[%d]info is:%s.",sock_fd,strerror(errno));
		return RTCODE_ERROR;
	}
	return conn_fd;
}
