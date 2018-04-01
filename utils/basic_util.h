/*define return value of function*/
#define RTCODE_ERROR -1
#define RTCODE_SUCCESS 0
#define RTCODE_PARAM_ERROR -1
#define RTCODE_EXE_ERROR -1
#define RTCODE_MEM_ALLOC_ERROR -1

/*define the data type*/
typedef int int32_t ;
typedef unsigned int uint32_t ;
typedef long int int64_t ;
typedef unsigned long int uint64_t ;

/*define the cahr type*/
#define MAX_STR_LEN 256
typedef char[MAX_STR_LEN] maxstr ;

#define func_enter() log_info("enter function")
#define func_exit()  log_info("exit function")

#define check_return(ret,format,args...)\
	do{\
		if(ret!=RTCODE_SUCCESS){\
			log_error(format,##args);\
			func_exit();\
			return ret;\
		}\
	}while(0)

#define check_set_return(err,err_code,ret_val,format,args...)\
	do{\
		if(err!=RTCODE_SUCCESS){\
			err_code = err;\
			log_error(format,##args);\
			return ret_val;\
		}\
	}while(0)

#define check_null(var,ret)\
	do{\
		if(NULL==(var)){\
			log_error("parameter is invalid(null pointer)!:var="#var);\
			func_exit();\
			assert(0);\
			return ret;\
		}\
	}while(0)

#define check_null_return_void(var){\
	do{\
		if(NULL==(var)){\
			log_error("parameter is invalid(null poniter!:var="#var);\
			func_exit();\
			assert(0);\
			return;\
		}\
	}while(0)

#define check_fail_log(exp,format,args...)\
	do{\
		if(exp){\
			log_error(format,##args);\
		}\
	}while(0)

#define check_fail_log_ret_void(exp,format,args...)\
	do{\
		if(exp){\
			log_error(format,##args);\
			return;\
		}\
	}while(0)

#define check_fail_log_ret(exp,ret,format,args...)\
	do{\
		if(exp){\
			log_error(format,##args);\
			return ret;\
		}\
	}while(0)

#define do_fail_log(exp,done,format,args...)\
	do{\
		if(exp){\
			done;\
			log_error(format,##args);\
		}\
	}while(0)

#define do_fail_log_ret_void(exp,done,format,args...){\
	do{\
		if(exp){\
			done;\
			log_error(format,##args);\
			return;\
		}\
	}while(0)
	
#define do_fail_log_ret(exp,done,ret,format,args...){\
	do{\
		if(exp){\
			done;\
			log_error(format,##args);\
			return ret;\
		}\
	}while(0)
		
#define goto_log_if_fail(exp,tag,format,args...){\
	do{\
		if(exp){\
			goto tag;\
			log_error(format,##args);\
		}\
	}while(0)

#define goto_log_ret_void__if_fail(exp,tag,format,args...){\
	do{\
		if(exp){\
			goto tag;\
			log_error(format,##args);\
			return;\
		}\
	}while(0)
	
#define goto_log_ret_if_fail(exp,tag,ret,format,args...){\
	do{\
		if(exp){\
			goto tag;\
			log_error(format,##args);\
			return ret;\
		}\
	}while(0)
		
