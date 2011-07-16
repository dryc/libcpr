/* This is free and unencumbered software released into the public domain. */

#include "build.h"
#include <signal.h>       /* for kill() */
#include <sys/resource.h> /* for setpriority() */
#include <sys/wait.h>     /* for waitpid() */

#ifdef __linux__
#include <sched.h>        /* for sched_setaffinity() */
#endif

process_t*
process_alloc() {
  process_t* process = malloc(sizeof(process_t));
  process_init(process);
  return process;
}

int
process_init(process_t* process) {
  validate_with_errno_return(process != NULL);

  bzero(process, sizeof(process_t));

  return 0;
}

int
process_init_with(process_t* process, const pid_t id) {
  const int result = process_init(process);

  if (likely(result == 0)) {
    process->id = id;
  }

  return result;
}

int
process_init_self(process_t* process) {
  return process_init_with(process, getpid());
}

bool
process_is_self(process_t* process) {
  validate_with_false_return(process != NULL);

  return unlikely(process->id == getpid()) ? TRUE : FALSE;
}

int
process_set_priority(process_t* process, const int priority) {
  validate_with_errno_return(priority >= -20 && priority <= 20);

  const int pid = likely(process != NULL) ? process->id : getpid();
  const int rc = setpriority(PRIO_PROCESS, pid, priority);

  return likely(rc == 0) ? 0 : -errno;
}

int
#ifdef __linux__
process_set_affinity(process_t* process, const cpu_set_t* restrict mask) {
  validate_with_errno_return(mask != NULL);

  const int pid = likely(process != NULL) ? process->id : 0;
  const int rc = sched_setaffinity(pid, sizeof(cpu_set_t), (cpu_set_t*)mask);

  return likely(rc == 0) ? 0 : -errno;
#else
process_set_affinity(process_t* process, const void* restrict mask) {
  validate_with_errno_return(mask != NULL);

  return -(errno = ENOTSUP); // operation not supported
#endif /* __linux__ */
}

int
process_kill(process_t* process, const int signal) {
  validate_with_errno_return(signal >= 0);

  const int pid = likely(process != NULL) ? process->id : getpid();
  const int rc = kill(pid, signal);

  return likely(rc == 0) ? 0 : -errno;
}

int
process_wait(process_t* process) {
  validate_with_errno_return(process != NULL);

  const int rc = waitpid(process->id, &process->status, 0);

  return likely(rc >= 0) ? process->status : -errno;
}
