/* This is free and unencumbered software released into the public domain. */

#include "build.h"

public const class_t rwlock_class = {
  .name    = "rwlock",
  .super   = NULL,
  .vtable  = NULL, // TODO
};

public rwlock_t*
rwlock_alloc() {
  rwlock_t* rwlock = malloc(sizeof(rwlock_t));
  rwlock_init(rwlock);
  return rwlock;
}

public void
rwlock_free(rwlock_t* rwlock) {
  if (likely(rwlock != NULL)) {
    rwlock_dispose(rwlock);
    free(rwlock);
  }
}

public int
rwlock_init(rwlock_t* rwlock) {
  validate_with_errno_return(rwlock != NULL);

#ifndef DEBUG
  bzero(rwlock, sizeof(rwlock_t));
#endif

#ifdef HAVE_PTHREAD_RWLOCK_INIT
  const int rc = pthread_rwlock_init(&rwlock->id, NULL);
#else
  const int rc = ENOTSUP; // operation not supported
#endif

  return likely(rc == 0) ? SUCCESS : FAILURE(rc);
}

public int
rwlock_dispose(rwlock_t* rwlock) {
  validate_with_errno_return(rwlock != NULL);

#ifdef HAVE_PTHREAD_RWLOCK_DESTROY
  const int rc = pthread_rwlock_destroy(&rwlock->id);
#else
  const int rc = ENOTSUP; // operation not supported
#endif

#ifndef NDEBUG
  bzero(rwlock, sizeof(rwlock_t));
#endif

  return likely(rc == 0) ? SUCCESS : FAILURE(rc);
}

public int
rwlock_rdlock(rwlock_t* rwlock) {
  validate_with_errno_return(rwlock != NULL);

#ifdef HAVE_PTHREAD_RWLOCK_RDLOCK
  const int rc = pthread_rwlock_rdlock(&rwlock->id);
#else
  const int rc = ENOTSUP; // operation not supported
#endif

  return likely(rc == 0) ? SUCCESS : FAILURE(rc);
}

public int
rwlock_tryrdlock(rwlock_t* rwlock) {
  validate_with_errno_return(rwlock != NULL);

#ifdef HAVE_PTHREAD_RWLOCK_TRYRDLOCK
  const int rc = pthread_rwlock_tryrdlock(&rwlock->id);
#else
  const int rc = ENOTSUP; // operation not supported
#endif

  return likely(rc == 0) ? SUCCESS : FAILURE(rc);
}

public int
rwlock_wrlock(rwlock_t* rwlock) {
  validate_with_errno_return(rwlock != NULL);

#ifdef HAVE_PTHREAD_RWLOCK_WRLOCK
  const int rc = pthread_rwlock_wrlock(&rwlock->id);
#else
  const int rc = ENOTSUP; // operation not supported
#endif

  return likely(rc == 0) ? SUCCESS : FAILURE(rc);
}

public int
rwlock_trywrlock(rwlock_t* rwlock) {
  validate_with_errno_return(rwlock != NULL);

#ifdef HAVE_PTHREAD_RWLOCK_TRYWRLOCK
  const int rc = pthread_rwlock_trywrlock(&rwlock->id);
#else
  const int rc = ENOTSUP; // operation not supported
#endif

  return likely(rc == 0) ? SUCCESS : FAILURE(rc);
}

public int
rwlock_unlock(rwlock_t* rwlock) {
  validate_with_errno_return(rwlock != NULL);

#ifdef HAVE_PTHREAD_RWLOCK_UNLOCK
  const int rc = pthread_rwlock_unlock(&rwlock->id);
#else
  const int rc = ENOTSUP; // operation not supported
#endif

  return likely(rc == 0) ? SUCCESS : FAILURE(rc);
}
