/*define return value of function*/
#define RTCODE_ERROR -1
#define RTCODE_SUCCESS 0
#define RTCODE_PARAM_ERROR -1

/*define the data type*/
typedef int int32_t ;
typedef unsigned int uint32_t ;
typedef long int int64_t ;
typedef unsigned long int uint64_t ;

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

#define check_null_return_void(var){\
	do{\
		if(NULL==(var)){\
			log_error("parameter is invalid(null poniter!:var="#var);\
			func_exit();\
			assert();\
			return;\
		}\
	}while(0)