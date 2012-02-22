/* This is free and unencumbered software released into the public domain. */

#include "build.h"
#include <signal.h>       /* for kill() */
#include <sys/resource.h> /* for setpriority() */
#include <sys/wait.h>     /* for waitpid() */

#ifdef __linux__
#include <sched.h>        /* for sched_setaffinity() */
#endif

public const class_t process_class = {
  .name    = "process",
  .super   = NULL,
  .vtable  = NULL, // TODO
};

public process_t*
process_alloc() {
  process_t* process = malloc(sizeof(process_t));
  process_init(process);
  return process;
}

public void
process_free(process_t* process) {
  if (likely(process != NULL)) {
    process_dispose(process);
    free(process);
  }
}

public int
process_init(process_t* process) {
  validate_with_errno_return(process != NULL);

  bzero(process, sizeof(process_t));

  return SUCCESS;
}

public int
process_init_with(process_t* process, const pid_t id) {
  const int result = process_init(process);

  if (likely(result == 0)) {
    process->id = id;
  }

  return result;
}

public int
process_init_self(process_t* process) {
  return process_init_with(process, getpid());
}

public int
process_dispose(process_t* process) {
  validate_with_errno_return(process != NULL);

#ifndef NDEBUG
  bzero(process, sizeof(process_t));
#endif

  return SUCCESS;
}

public bool
process_is_self(process_t* process) {
  validate_with_false_return(process != NULL);

  return unlikely(process->id == getpid()) ? TRUE : FALSE;
}

public int
process_set_priority(process_t* process, const int priority) {
  validate_with_errno_return(priority >= -20 && priority <= 20);

#ifdef HAVE_SETPRIORITY
  const int pid = likely(process != NULL) ? process->id : getpid();
  const int rc = setpriority(PRIO_PROCESS, pid, priority);
#else
  const int rc = errno = ENOTSUP; // operation not supported
#endif

  return likely(rc == 0) ? SUCCESS : FAILURE(errno);
}

public int
#ifdef __linux__
process_set_affinity(process_t* process, const cpu_set_t* restrict mask) {
  validate_with_errno_return(mask != NULL);

#ifdef HAVE_SCHED_SETAFFINITY
  const int pid = likely(process != NULL) ? process->id : 0;
  const int rc = sched_setaffinity(pid, sizeof(cpu_set_t), (cpu_set_t*)mask);
#else
  const int rc = errno = ENOTSUP; // operation not supported
#endif

  return likely(rc == 0) ? SUCCESS : FAILURE(errno);
#else
process_set_affinity(process_t* process, const void* restrict mask) {
  validate_with_errno_return(mask != NULL);

  return (void)process, FAILURE(ENOTSUP); // operation not supported
#endif /* __linux__ */
}

public int
process_kill(process_t* process, const int signal) {
  validate_with_errno_return(signal >= 0);

#ifdef HAVE_KILL
  const int pid = likely(process != NULL) ? process->id : getpid();
  const int rc = kill(pid, signal);
#else
  const int rc = errno = ENOTSUP; // operation not supported
#endif

  return likely(rc == 0) ? SUCCESS : FAILURE(errno);
}

public int
process_wait(process_t* process) {
  validate_with_errno_return(process != NULL);

#ifdef HAVE_WAITPID
  const int rc = waitpid(process->id, &process->status, 0);
#else
  const int rc = errno = ENOTSUP; // operation not supported
#endif

  return likely(rc >= 0) ? process->status : FAILURE(errno);
}
