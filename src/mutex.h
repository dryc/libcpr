/* This is free and unencumbered software released into the public domain. */

#ifndef _CPRIME_MUTEX_H
#define _CPRIME_MUTEX_H

#ifdef __cplusplus
extern "C" {
#endif

#include <pthread.h> /* for pthread_mutex_t */

typedef struct mutex_t {
  pthread_mutex_t id;
} mutex_t;

typedef struct mutex_interface_t {
  mutex_t* (*alloc)();
  int (*init)(mutex_t* mutex);
  int (*lock)(mutex_t* mutex);
  int (*unlock)(mutex_t* mutex);
} mutex_interface_t;

extern const mutex_interface_t mutex;

extern mutex_t* mutex_alloc();

extern int mutex_init(mutex_t* mutex);

extern int mutex_lock(mutex_t* mutex);
extern int mutex_unlock(mutex_t* mutex);

#ifdef __cplusplus
}
#endif

#endif /* _CPRIME_MUTEX_H */
