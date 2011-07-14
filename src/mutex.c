/* This is free and unencumbered software released into the public domain. */

#include "build.h"
#include <stdlib.h> /* for calloc(), free(), malloc() */

const mutex_interface_t mutex = {
  .alloc  = mutex_alloc,
  .init   = mutex_init,
  .lock   = mutex_lock,
  .unlock = mutex_unlock,
};

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

int
mutex_lock(mutex_t* mutex) {
  validate_with_errno_return(mutex != NULL);

  const int rc = pthread_mutex_lock(&mutex->id);

  return likely(rc == 0) ? 0 : -(errno = rc);
}

int
mutex_unlock(mutex_t* mutex) {
  validate_with_errno_return(mutex != NULL);

  const int rc = pthread_mutex_unlock(&mutex->id);

  return likely(rc == 0) ? 0 : -(errno = rc);
}
