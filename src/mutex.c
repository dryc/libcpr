/* This is free and unencumbered software released into the public domain. */

#include "build.h"

const mutex_interface_t mutex = {
  .alloc        = mutex_alloc,
  .free         = mutex_free,
  .init         = mutex_init,
  .dispose      = mutex_dispose,
  .lock         = mutex_lock,
  .lock_or_fail = mutex_lock_or_fail,
  .unlock       = mutex_unlock,
};

mutex_t*
mutex_alloc() {
  mutex_t* mutex = malloc(sizeof(mutex_t));
  mutex_init(mutex);
  return mutex;
}

void
mutex_free(mutex_t* mutex) {
  if (likely(mutex != NULL)) {
    mutex_dispose(mutex);
    free(mutex);
  }
}

int
mutex_init(mutex_t* mutex) {
  validate_with_errno_return(mutex != NULL);

  bzero(mutex, sizeof(mutex_t));

  const int rc = pthread_mutex_init(&mutex->id, NULL);

  return likely(rc == 0) ? 0 : -(errno = rc);
}

int
mutex_dispose(mutex_t* mutex) {
  validate_with_errno_return(mutex != NULL);

  const int rc = pthread_mutex_destroy(&mutex->id);

#ifndef NDEBUG
  bzero(mutex, sizeof(mutex_t));
#endif

  return 0;
}

int
mutex_lock(mutex_t* mutex) {
  validate_with_errno_return(mutex != NULL);

  const int rc = pthread_mutex_lock(&mutex->id);

  return likely(rc == 0) ? 0 : -(errno = rc);
}

int
mutex_lock_or_fail(mutex_t* mutex) {
  validate_with_errno_return(mutex != NULL);

  const int rc = pthread_mutex_trylock(&mutex->id);

  return likely(rc == 0) ? 0 : -(errno = rc);
}

int
mutex_unlock(mutex_t* mutex) {
  validate_with_errno_return(mutex != NULL);

  const int rc = pthread_mutex_unlock(&mutex->id);

  return likely(rc == 0) ? 0 : -(errno = rc);
}
