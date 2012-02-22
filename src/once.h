/* This is free and unencumbered software released into the public domain. */

#ifndef CPRIME_ONCE_H
#define CPRIME_ONCE_H

#ifdef __cplusplus
extern "C" {
#endif

#include <pthread.h> /* for pthread_once_t */

typedef struct once_t {
  pthread_once_t id;
} once_t;

#define ONCE_INIT {.id = PTHREAD_ONCE_INIT}

extern int once(once_t* guard, void (*function)(void));

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* CPRIME_ONCE_H */
