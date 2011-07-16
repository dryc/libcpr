/* This is free and unencumbered software released into the public domain. */

#include "build.h"
#include <signal.h> /* for pthread_kill() */

thread_t*
thread_alloc() {
  thread_t* thread = malloc(sizeof(thread_t));
  thread_init(thread);
  return thread;
}

int
thread_init(thread_t* thread) {
  validate_with_errno_return(thread != NULL);

  bzero(thread, sizeof(thread_t));

  const int rc = pthread_attr_init(&thread->attr);

  return likely(rc == 0) ? 0 : -(errno = rc);
}

int
thread_init_self(thread_t* thread) {
  const int result = thread_init(thread);

  if (likely(result == 0)) {
    thread->id = pthread_self();
  }

  return result;
}

bool
thread_is_self(thread_t* thread) {
  validate_with_false_return(thread != NULL);

  const int rc = pthread_equal(thread->id, pthread_self());

  return unlikely(rc != 0) ? TRUE : FALSE;
}

int
#ifdef __linux__
thread_set_affinity(thread_t* thread, const cpu_set_t* restrict mask) {
  validate_with_errno_return(mask != NULL);

  const pthread_t tid = likely(thread != NULL) ? thread->id : pthread_self();
  const int rc = pthread_setaffinity_np(tid, sizeof(cpu_set_t), (cpu_set_t*)mask);

  return likely(rc == 0) ? 0 : -(errno = rc);
#else
thread_set_affinity(thread_t* thread, const void* restrict mask) {
  validate_with_errno_return(mask != NULL);

  return -(errno = ENOTSUP); // operation not supported
#endif /* __linux__ */
}

int
thread_start(thread_t* thread, const thread_execute_t function) {
  validate_with_false_return(thread != NULL && function != NULL);

  const int rc = pthread_create(&thread->id, &thread->attr,
    (void*(*)(void*))function, thread);

  return likely(rc == 0) ? 0 : -(errno = rc);
}

int
thread_detach(thread_t* thread) {
  const pthread_t tid = likely(thread != NULL) ? thread->id : pthread_self();
  const int rc = pthread_detach(tid);

  return likely(rc == 0) ? 0 : -(errno = rc);
}

int
thread_join(thread_t* thread) {
  validate_with_errno_return(thread != NULL);

  const int rc = pthread_join(thread->id, &thread->value);

  return likely(rc == 0) ? 0 : -(errno = rc);
}

int
thread_cancel(thread_t* thread) {
  validate_with_errno_return(thread != NULL);

  const int rc = pthread_cancel(thread->id);

  return likely(rc == 0) ? 0 : -(errno = rc);
}

int
thread_kill(thread_t* thread, const int signal) {
  validate_with_errno_return(signal >= 0);

  const pthread_t tid = likely(thread != NULL) ? thread->id : pthread_self();
  const int rc = pthread_kill(tid, signal);

  return likely(rc == 0) ? 0 : -(errno = rc);
}
