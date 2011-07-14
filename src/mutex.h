/* This is free and unencumbered software released into the public domain. */

#ifndef _CPRIME_MUTEX_H
#define _CPRIME_MUTEX_H

#ifdef __cplusplus
extern "C" {
#endif

#include <pthread.h> /* for pthread_mutex_t */

typedef struct {
  pthread_mutex_t id;
} mutex_t;

extern mutex_t* mutex_alloc();

extern int mutex_init(mutex_t* mutex);

#ifdef __cplusplus
}
#endif

#endif /* _CPRIME_MUTEX_H */
