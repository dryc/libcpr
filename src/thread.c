/* This is free and unencumbered software released into the public domain. */

#include "build.h"

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

  return unlikely(pthread_equal(thread->id, pthread_self()) != 0) ? TRUE : FALSE;
}

int
thread_join(thread_t* thread) {
  validate_with_errno_return(thread != NULL);

  const int rc = pthread_join(thread->id, &thread->value);

  return likely(rc == 0) ? 0 : -(errno = rc);
}
