/* This is free and unencumbered software released into the public domain. */

#ifndef _CPRIME_PROCESS_H
#define _CPRIME_PROCESS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <unistd.h> /* for pid_t */

#ifdef __linux__
#include <sched.h>  /* for cpu_set_t */
#endif

typedef struct process_t {
  pid_t id;
  int status;
} process_t;

extern process_t* process_alloc();
extern void process_free(process_t* process);

extern int process_init(process_t* process);
extern int process_init_with(process_t* process, const pid_t id);
extern int process_init_self(process_t* process);

extern int process_dispose(process_t* process);

extern bool process_is_self(process_t* process);

extern int process_set_priority(process_t* process, const int priority);

#ifdef __linux__
extern int process_set_affinity(process_t* process, const cpu_set_t* restrict mask);
#else
extern int process_set_affinity(process_t* process, const void* restrict mask);
#endif

extern int process_kill(process_t* process, const int signal);
extern int process_wait(process_t* process);

#ifdef __cplusplus
}
#endif

#endif /* _CPRIME_PROCESS_H */
