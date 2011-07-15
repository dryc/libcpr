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
  pthread_attr_init(&thread->attr);

  return 0;
}
