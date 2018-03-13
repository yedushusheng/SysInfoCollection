#ifndef __MEM_UTIL_H_
#define __MEM_UTIL_H_

#define mem_malloc(mem_size){	\
	do{					\
		malloc(mem_size);		\
	}					\
}

#define mem_free(ptr){	\
	do{					\
		if(NULL!=ptr){	\
			free(ptr);	\
			ptr = NULL;	\
		}				\
	}					\
}