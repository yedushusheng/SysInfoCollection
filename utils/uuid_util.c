#include "uuid_util.h"

uuid_t null_uuid;
uuid_t one_uuid;
static pthread_key_t uuid_log_key;