/* This is free and unencumbered software released into the public domain. */

#include "build.h"

public const class_t mutex_class = {
  .name    = "mutex",
  .super   = NULL,
  .vtable  = NULL, // TODO
};

public const mutex_interface_t mutex = {
  .alloc   = mutex_alloc,
  .free    = mutex_free,
  .init    = mutex_init,
  .dispose = mutex_dispose,
  .lock    = mutex_lock,
  .trylock = mutex_trylock,
  .unlock  = mutex_unlock,
};

public mutex_t*
mutex_alloc() {
  mutex_t* mutex = malloc(sizeof(mutex_t));
  mutex_init(mutex);
  return mutex;
}

public void
mutex_free(mutex_t* mutex) {
  if (likely(mutex != NULL)) {
    mutex_dispose(mutex);
    free(mutex);
  }
}

public int
mutex_init(mutex_t* mutex) {
  validate_with_errno_return(mutex != NULL);

#ifndef NDEBUG
  bzero(mutex, sizeof(mutex_t));
#endif

#ifdef HAVE_PTHREAD_MUTEX_INIT
  const int rc = pthread_mutex_init(&mutex->id, NULL);
#else
  const int rc = ENOTSUP; // operation not supported
#endif

  return likely(rc == 0) ? SUCCESS : FAILURE(rc);
}

public int
mutex_dispose(mutex_t* mutex) {
  validate_with_errno_return(mutex != NULL);

#ifdef HAVE_PTHREAD_MUTEX_DESTROY
  const int rc = pthread_mutex_destroy(&mutex->id);
#else
  const int rc = ENOTSUP; // operation not supported
#endif

#ifndef NDEBUG
  bzero(mutex, sizeof(mutex_t));
#endif

  return likely(rc == 0) ? SUCCESS : FAILURE(rc);
}

public int
mutex_lock(mutex_t* mutex) {
  validate_with_errno_return(mutex != NULL);

#ifdef HAVE_PTHREAD_MUTEX_LOCK
  const int rc = pthread_mutex_lock(&mutex->id);
#else
  const int rc = ENOTSUP; // operation not supported
#endif

  return likely(rc == 0) ? SUCCESS : FAILURE(rc);
}

public int
mutex_trylock(mutex_t* mutex) {
  validate_with_errno_return(mutex != NULL);

#ifdef HAVE_PTHREAD_MUTEX_TRYLOCK
  const int rc = pthread_mutex_trylock(&mutex->id);
#else
  const int rc = ENOTSUP; // operation not supported
#endif

  return likely(rc == 0) ? SUCCESS : FAILURE(rc);
}

public int
mutex_unlock(mutex_t* mutex) {
  validate_with_errno_return(mutex != NULL);

#ifdef HAVE_PTHREAD_MUTEX_UNLOCK
  const int rc = pthread_mutex_unlock(&mutex->id);
#else
  const int rc = ENOTSUP; // operation not supported
#endif

  return likely(rc == 0) ? SUCCESS : FAILURE(rc);
}
