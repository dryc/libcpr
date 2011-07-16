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
  void* value;
} thread_t;

extern thread_t* thread_alloc();

extern int thread_init(thread_t* thread);
extern int thread_init_self(thread_t* thread);

extern bool thread_is_self(thread_t* thread);

extern int thread_join(thread_t* thread);
extern int thread_cancel(thread_t* thread);
extern int thread_kill(thread_t* thread, const int signal);

#ifdef __cplusplus
}
#endif

#endif /* _CPRIME_THREAD_H */
