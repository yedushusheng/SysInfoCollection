#ifndef _THREAD_UTIL_H_
#define _THREAD_UTIL_H_

#include<pthread.h>

typedef pthread_mutex_t thread_mutex_t;
typedef pthread_rwlock_t thread_rwlock_t;
typedef pthread_mutexattr_t thread_mutexattr_t;
typedef pthread_rwlockattr_t thread_rwlockattr_t;

int32_t thread_mutex_init(thread_mutex_t *mutex,thread_mutexattr_t *attr);
int32_t thread_mutex_lock(thread_mutex_t *mutex);
int32_t thread_mutex_unlock(thread_mutex_t *mutex);