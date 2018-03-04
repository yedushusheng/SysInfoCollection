#include "cpu_info.h"

/****************************************
* 函数名称: get_cpu_phy_num
* 函数功能: 获取主机CPU的物理核数
* 入     参: int32_t指针类型
* 出     参: 无
* 返 回 值: ret 
* 备     注: 无
****************************************/
int32_t get_cpu_phy_num(int32_t *core){
	int32_t ret = RTCODE_SUCCESS;
	maxstr cmd = {0};
	maxstr buf = {0};

	check_null(core, RTCODE_ERROR);
	snprintf(cmd,sizeof(cmd),"%s","grep 'physical id' /proc/cpuinfo | sort u | wc l");
	ret = shell_exec(cmd, buf, sizeof(buf));
	if(RTCODE_ERROR == ret){
		log_error("exec cmd failed,cmd='%s',err='%s'",cmd,buf);
		return RTCODE_ERROR;
	}

	ret = str_to_int(buf,10,core);
	return ret;
}