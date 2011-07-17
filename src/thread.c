/* This is free and unencumbered software released into the public domain. */

#include "build.h"
#include <signal.h> /* for pthread_kill() */

thread_t*
thread_alloc() {
  thread_t* thread = malloc(sizeof(thread_t));
  thread_init(thread);
  return thread;
}

void
thread_free(thread_t* thread) {
  if (likely(thread != NULL)) {
    thread_dispose(thread);
    free(thread);
  }
}

int
thread_init(thread_t* thread) {
  validate_with_errno_return(thread != NULL);

  bzero(thread, sizeof(thread_t));

  const int rc = pthread_attr_init(&thread->attr);

  return likely(rc == 0) ? 0 : -(errno = rc);
}

int
thread_init_with_id(thread_t* thread, const pthread_t id) {
  validate_with_errno_return(thread != NULL);

  bzero(thread, sizeof(thread_t));

  thread->id = id;
#ifdef __linux__
  const int rc = pthread_getattr_np(thread->id, &thread->attr);
#else
  const int rc = 0;
#endif

  return likely(rc == 0) ? 0 : -(errno = rc);
}

int
thread_init_with_user_data(thread_t* thread, const void* user_data) {
  int result = thread_init(thread);

  if (succeeded(result)) {
    thread->user_data = (void*)user_data;
  }

  return result;
}

int
thread_init_self(thread_t* thread) {
  return thread_init_with_id(thread, pthread_self());
}

int
thread_dispose(thread_t* thread) {
  validate_with_errno_return(thread != NULL);

  const int rc = pthread_attr_destroy(&thread->attr);

#ifndef NDEBUG
  bzero(thread, sizeof(thread_t));
#endif

  return likely(rc == 0) ? 0 : -(errno = rc);
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
