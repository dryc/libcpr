/* This is free and unencumbered software released into the public domain. */

#ifndef _CPRIME_ITER_H
#define _CPRIME_ITER_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct iter_t {
  void* user_data;
} iter_t;

extern iter_t* iter_alloc();
extern void iter_free(iter_t* iter);

#ifdef __cplusplus
}
#endif

#endif /* _CPRIME_ITER_H */
