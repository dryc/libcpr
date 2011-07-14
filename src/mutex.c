/* This is free and unencumbered software released into the public domain. */

#include "build.h"
#include <stdlib.h> /* for calloc(), free(), malloc() */

mutex_t*
mutex_alloc() {
  mutex_t* mutex = malloc(sizeof(mutex_t));
  mutex_init(mutex);
  return mutex;
}

int
mutex_init(mutex_t* mutex) {
  validate_with_errno_return(mutex != NULL);

  bzero(mutex, sizeof(mutex_t));

  const int rc = pthread_mutex_init(&mutex->id, NULL);

  return likely(rc == 0) ? 0 : -(errno = rc);
}
