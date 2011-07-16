/* This is free and unencumbered software released into the public domain. */

#include "build.h"
#include <signal.h>   /* for kill() */
#include <sys/wait.h> /* for waitpid() */

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
process_init_self(process_t* process) {
  const int result = process_init(process);

  if (likely(result == 0)) {
    process->id = getpid();
  }

  return result;
}

bool
process_is_self(process_t* process) {
  validate_with_false_return(process != NULL);

  return unlikely(process->id == getpid()) ? TRUE : FALSE;
}

int
process_kill(process_t* process, const int signal) {
  validate_with_errno_return(process != NULL);

  const int rc = kill(process->id, signal);

  return likely(rc == 0) ? 0 : -errno;
}

int
process_wait(process_t* process) {
  validate_with_errno_return(process != NULL);

  const int rc = waitpid(process->id, &process->status, 0);

  return likely(rc >= 0) ? process->status : -errno;
}
