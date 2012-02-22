/* This is free and unencumbered software released into the public domain. */

#ifndef CPRIME_ONCE_H
#define CPRIME_ONCE_H

#ifdef __cplusplus
extern "C" {
#endif

#include <assert.h>  /* for assert() */
#include <pthread.h> /* for pthread_once_t, pthread_once() */

typedef struct once {
  pthread_once_t id;
} once_t;

#define ONCE_INIT {.id = PTHREAD_ONCE_INIT}

static inline void
once(once_t* const restrict guard,
     void (*function)(void)) {
  assert(is_nonnull(guard));
  assert(is_nonnull(function));
#if 1
  (void)pthread_once(&guard->id, function);
#else
  errno = ENOTSUP; // operation not supported
#endif
}

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* CPRIME_ONCE_H */
