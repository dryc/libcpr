/* This is free and unencumbered software released into the public domain. */

#include "build.h"

#ifdef HAVE_PTHREAD_KILL
#include <signal.h> /* for pthread_kill() */
#endif

public const class_t thread_class = {
  .name    = "thread",
  .super   = NULL,
  .vtable  = NULL, // TODO
};

public thread_t*
thread_alloc() {
  thread_t* thread = malloc(sizeof(thread_t));
  thread_init(thread);
  return thread;
}

public void
thread_free(thread_t* thread) {
  if (likely(thread != NULL)) {
    thread_dispose(thread);
    free(thread);
  }
}

public int
thread_init(thread_t* thread) {
  validate_with_errno_return(thread != NULL);

  bzero(thread, sizeof(thread_t));

#ifdef HAVE_PTHREAD_ATTR_INIT
  const int rc = pthread_attr_init(&thread->attr);
#else
  const int rc = 0;
#endif

  return likely(rc == 0) ? SUCCESS : FAILURE(rc);
}

public int
thread_init_with_id(thread_t* thread, const pthread_t id) {
  validate_with_errno_return(thread != NULL);

  bzero(thread, sizeof(thread_t));

  thread->id = id;
#ifdef HAVE_PTHREAD_GETATTR_NP
  const int rc = pthread_getattr_np(thread->id, &thread->attr);
#else
  const int rc = 0;
#endif

  return likely(rc == 0) ? SUCCESS : FAILURE(rc);
}

public int
thread_init_with_user_data(thread_t* thread, const void* user_data) {
  int result = thread_init(thread);

  if (succeeded(result)) {
    thread->user_data = (void*)user_data;
  }

  return result;
}

public int
thread_init_self(thread_t* thread) {
  return thread_init_with_id(thread, pthread_self());
}

public int
thread_dispose(thread_t* thread) {
  validate_with_errno_return(thread != NULL);

#ifdef HAVE_PTHREAD_ATTR_DESTROY
  const int rc = pthread_attr_destroy(&thread->attr);
#else
  const int rc = 0;
#endif

#ifndef NDEBUG
  bzero(thread, sizeof(thread_t));
#endif

  return likely(rc == 0) ? SUCCESS : FAILURE(rc);
}

public bool
thread_is_self(thread_t* thread) {
  validate_with_false_return(thread != NULL);

#ifdef HAVE_PTHREAD_EQUAL
  const int rc = pthread_equal(thread->id, pthread_self());
#else
  const int rc = ENOTSUP; // operation not supported
#endif

  return unlikely(rc != 0) ? TRUE : FALSE;
}

public int
#ifdef __linux__
thread_set_affinity(thread_t* thread, const cpu_set_t* restrict mask) {
#ifdef HAVE_PTHREAD_SETAFFINITY_NP
  const pthread_t tid = likely(thread != NULL) ? thread->id : pthread_self();
  int rc = 0;

  // Reset the thread's CPU affinity to enable it to run on all CPUs:
  if (unlikely(mask == NULL)) {
    const long cpu_count = sysconf(_SC_NPROCESSORS_ONLN);
    assert(cpu_count >= 1);

    cpu_set_t cpu_mask;
    CPU_ZERO(&cpu_mask);
    for (int i = 0; i < cpu_count; i++)
      CPU_SET(i, &cpu_mask);

    rc = pthread_setaffinity_np(tid, sizeof(cpu_set_t), &cpu_mask);
  }

  // Set the thread's CPU affinity to the given bitmask:
  else {
    rc = pthread_setaffinity_np(tid, sizeof(cpu_set_t), (cpu_set_t*)mask);
  }
#else
  const int rc = ENOTSUP; // operation not supported
#endif

  return likely(rc == 0) ? SUCCESS : FAILURE(rc);
#else
thread_set_affinity(thread_t* thread, const void* restrict mask) {
  validate_with_errno_return(mask != NULL);

  return (void)thread, FAILURE(ENOTSUP); // operation not supported
#endif /* __linux__ */
}

public int
thread_start(thread_t* thread, const thread_execute_t function) {
  validate_with_false_return(thread != NULL && function != NULL);

#ifdef HAVE_PTHREAD_CREATE
  const int rc = pthread_create(&thread->id, &thread->attr,
    (void*(*)(void*))function, thread);
#else
  const int rc = ENOTSUP; // operation not supported
#endif

  return likely(rc == 0) ? SUCCESS : FAILURE(rc);
}

public int
thread_detach(thread_t* thread) {
#ifdef HAVE_PTHREAD_DETACH
  const pthread_t tid = likely(thread != NULL) ? thread->id : pthread_self();
  const int rc = pthread_detach(tid);
#else
  const int rc = ENOTSUP; // operation not supported
#endif

  return likely(rc == 0) ? SUCCESS : FAILURE(rc);
}

public int
thread_join(thread_t* thread) {
  validate_with_errno_return(thread != NULL);

#ifdef HAVE_PTHREAD_JOIN
  const int rc = pthread_join(thread->id, &thread->value);
#else
  const int rc = ENOTSUP; // operation not supported
#endif

  return likely(rc == 0) ? SUCCESS : FAILURE(rc);
}

public int
thread_cancel(thread_t* thread) {
  validate_with_errno_return(thread != NULL);

#ifdef HAVE_PTHREAD_CANCEL
  const int rc = pthread_cancel(thread->id);
#else
  const int rc = ENOTSUP; // operation not supported
#endif

  return likely(rc == 0) ? SUCCESS : FAILURE(rc);
}

public int
thread_kill(thread_t* thread, const int signal) {
  validate_with_errno_return(signal >= 0);

#ifdef HAVE_PTHREAD_KILL
  const pthread_t tid = likely(thread != NULL) ? thread->id : pthread_self();
  const int rc = pthread_kill(tid, signal);
#else
  const int rc = ENOTSUP; // operation not supported
#endif

  return likely(rc == 0) ? SUCCESS : FAILURE(rc);
}
