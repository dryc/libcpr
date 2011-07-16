/* This is free and unencumbered software released into the public domain. */

#ifndef _CPRIME_PROCESS_H
#define _CPRIME_PROCESS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <unistd.h> /* for pid_t */

typedef struct process_t {
  pid_t id;
} process_t;

extern process_t* process_alloc();

extern int process_init(process_t* process);
extern int process_init_self(process_t* process);

extern bool process_is_self(process_t* process);

#ifdef __cplusplus
}
#endif

#endif /* _CPRIME_PROCESS_H */
