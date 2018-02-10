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