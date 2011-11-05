/* This is free and unencumbered software released into the public domain. */

#ifndef _CPRIME_THREAD_H_
#define _CPRIME_THREAD_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <pthread.h> /* for pthread_t, pthread_attr_t */

#ifdef __linux__
#include <sched.h>   /* for cpu_set_t */
#endif

typedef struct thread_t {
  pthread_t id;
  pthread_attr_t attr;
  void* value;
  void* user_data;
} thread_t;

typedef void* (*thread_execute_t)(thread_t* thread);

extern thread_t* thread_alloc();
extern void thread_free(thread_t* thread);

extern int thread_init(thread_t* thread);
extern int thread_init_with_id(thread_t* thread, const pthread_t id);
extern int thread_init_with_user_data(thread_t* thread, const void* user_data);
extern int thread_init_self(thread_t* thread);

extern int thread_dispose(thread_t* thread);

extern bool thread_is_self(thread_t* thread);

#ifdef __linux__
extern int thread_set_affinity(thread_t* thread, const cpu_set_t* restrict mask);
#else
extern int thread_set_affinity(thread_t* thread, const void* restrict mask);
#endif

extern int thread_start(thread_t* thread, const thread_execute_t function);
extern int thread_detach(thread_t* thread);
extern int thread_join(thread_t* thread);
extern int thread_cancel(thread_t* thread);
extern int thread_kill(thread_t* thread, const int signal);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* _CPRIME_THREAD_H_ */
