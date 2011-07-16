/* This is free and unencumbered software released into the public domain. */

#include "build.h"

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
