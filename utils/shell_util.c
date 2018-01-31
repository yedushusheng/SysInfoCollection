#include "shell_util.h"

int32_t shell_exec(const char *command,char *buffer,int32_t buffer_length){
    FILE *file = NULL;
	char *p = NULL;
	int rc = 0;

	check_null(command,RTCODE_PARAM_ERROR);

	file = popen(command,"er")；
	if(file == NULL){
        int32_t error_no = errno;
		if(buffer){
			snprintf(buffer,buffer_length,"%d",error_no);
		}
		return RTCODE_ERROR;
	}
	if(buffer){
		p = fgets(buffer,buffer_length,file);
		rc = pclose(file);

		if(p == NULL){
			buffer[0] = '\0';
			return RTCODE_SUCCESS;
		}
		if(p[strlen(p)-1]=='\n'){
            p[strlen(p)-1] = 0;
		}
}