/* This is free and unencumbered software released into the public domain. */

#ifndef _CPRIME_THREAD_H
#define _CPRIME_THREAD_H

#ifdef __cplusplus
extern "C" {
#endif

#include <pthread.h> /* for pthread_t */

typedef struct {
  pthread_t id;
} thread_t;

#ifdef __cplusplus
}
#endif

#endif /* _CPRIME_THREAD_H */
