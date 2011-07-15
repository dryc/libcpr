/* This is free and unencumbered software released into the public domain. */

#ifndef _CPRIME_THREAD_H
#define _CPRIME_THREAD_H

#ifdef __cplusplus
extern "C" {
#endif

#include <pthread.h> /* for pthread_t, pthread_attr_t */

typedef struct thread_t {
  pthread_t id;
  pthread_attr_t attr;
} thread_t;

extern thread_t* thread_alloc();

extern int thread_init(thread_t* thread);

#ifdef __cplusplus
}
#endif

#endif /* _CPRIME_THREAD_H */
