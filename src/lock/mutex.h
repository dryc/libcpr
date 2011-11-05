/* This is free and unencumbered software released into the public domain. */

#ifndef _CPRIME_MUTEX_H_
#define _CPRIME_MUTEX_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <pthread.h> /* for pthread_mutex_t */

extern const class_t mutex_class;

typedef struct mutex_t {
  pthread_mutex_t id;
} mutex_t;

typedef struct mutex_interface_t {
  mutex_t* (*alloc)();
  void (*free)();
  int (*init)(mutex_t* mutex);
  int (*dispose)(mutex_t* mutex);
  int (*lock)(mutex_t* mutex);
  int (*trylock)(mutex_t* mutex);
  int (*unlock)(mutex_t* mutex);
} mutex_interface_t;

extern const mutex_interface_t mutex;

extern mutex_t* mutex_alloc();
extern void mutex_free(mutex_t* mutex);

#define MUTEX_INIT            {.id = PTHREAD_MUTEX_INITIALIZER}

#ifdef PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP /* Linux only */
#define MUTEX_INIT_RECURSIVE  {.id = PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP}
#endif

#ifdef PTHREAD_ERRORCHECK_MUTEX_INITIALIZER_NP /* Linux only */
#define MUTEX_INIT_ERRORCHECK {.id = PTHREAD_ERRORCHECK_MUTEX_INITIALIZER_NP}
#endif

extern int mutex_init(mutex_t* mutex);

extern int mutex_dispose(mutex_t* mutex);

extern int mutex_lock(mutex_t* mutex);
extern int mutex_trylock(mutex_t* mutex);

extern int mutex_unlock(mutex_t* mutex);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* _CPRIME_MUTEX_H_ */
