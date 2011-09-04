/* This is free and unencumbered software released into the public domain. */

#include "build.h"

spinlock_t*
spinlock_alloc() {
  spinlock_t* spinlock = malloc(sizeof(spinlock_t));
  if (is_nonnull(spinlock)) {
    spinlock_init(spinlock);
  }
  return spinlock;
}

void
spinlock_free(spinlock_t* const spinlock) {
  if (is_nonnull(spinlock)) {
    spinlock_dispose(spinlock);
    free(spinlock);
  }
}

int
spinlock_init(spinlock_t* const spinlock) {
  validate_with_errno_return(is_nonnull(spinlock));

#ifndef DEBUG
  bzero(spinlock, sizeof(spinlock_t));
#endif

#ifdef HAVE_PTHREAD_SPIN_INIT
  const int rc = pthread_spin_init(&spinlock->id, PTHREAD_PROCESS_PRIVATE);
#else
  const int rc = ENOTSUP; // operation not supported
#endif

  return likely(rc == 0) ? 0 : -(errno = rc);
}

int
spinlock_dispose(spinlock_t* const spinlock) {
  validate_with_errno_return(is_nonnull(spinlock));

#ifdef HAVE_PTHREAD_SPIN_DESTROY
  const int rc = pthread_spin_destroy(&spinlock->id);
#else
  const int rc = ENOTSUP; // operation not supported
#endif

#ifndef NDEBUG
  bzero(spinlock, sizeof(spinlock_t));
#endif

  return likely(rc == 0) ? 0 : -(errno = rc);
}

int
spinlock_lock(spinlock_t* const spinlock) {
  validate_with_errno_return(is_nonnull(spinlock));

#ifdef HAVE_PTHREAD_SPIN_LOCK
  const int rc = pthread_spin_lock(&spinlock->id);
#else
  const int rc = ENOTSUP; // operation not supported
#endif

  return likely(rc == 0) ? 0 : -(errno = rc);
}

int
spinlock_trylock(spinlock_t* const spinlock) {
  validate_with_errno_return(is_nonnull(spinlock));

#ifdef HAVE_PTHREAD_SPIN_TRYLOCK
  const int rc = pthread_spin_trylock(&spinlock->id);
#else
  const int rc = ENOTSUP; // operation not supported
#endif

  return likely(rc == 0) ? 0 : -(errno = rc);
}

int
spinlock_unlock(spinlock_t* const spinlock) {
  validate_with_errno_return(is_nonnull(spinlock));

#ifdef HAVE_PTHREAD_SPIN_UNLOCK
  const int rc = pthread_spin_unlock(&spinlock->id);
#else
  const int rc = ENOTSUP; // operation not supported
#endif

  return likely(rc == 0) ? 0 : -(errno = rc);
}
