#ifndef _THREAD_UTIL_H_
#define _THREAD_UTIL_H_

#include"basic_util.h"
#include<pthread.h>

typedef pthread_mutex_t thread_mutex_t;
typedef pthread_rwlock_t thread_rwlock_t;
typedef pthread_key_t thread_ket_t;
typedef pthread_mutexattr_t thread_mutexattr_t;
typedef pthread_rwlockattr_t thread_rwlockattr_t;
typedef pthread_attr_t thread_attr_t;
typedef pthread_t thread_t;

#define THREAD_MUTEX_INITIALIZER PTHREAD_MUTEX_INITIALIZER
#define THREAD_RWCLOCK_INITIALIZER PTHREAD_RWLOCK_INITIALIZER

/*thread mutex function definition*/
int32_t thread_mutex_init(thread_mutex_t *mutex,thread_mutexattr_t *attr);
int32_t thread_mutex_lock(thread_mutex_t *mutex);
int32_t thread_mutex_timedlock(thread_mutex_t *mutex,const struct timespec *timeout);
int32_t thread_mutex_unlock(thread_mutex_t *mutex);
int32_t thread_mutex_destroy(thread_mutexattr_t *mutex);
/*thread rwlock function definition*/
int32_t thread_rwlock_init(thread_rwlock_t *rwlock,thread_rwlockattr_t *attr);
int32_t thread_rwlock_rdlock(thread_rwlock_t *rwlock);
int32_t thread_rwlock_wrlock(thread_rwlock_t *rwlock);
int32_t thread_rwlock_unlock(thread_rwlock_t *rwlock);
/*thread join*/
int32_t thread_join(thread_t thread,void **returnval);
