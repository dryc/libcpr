/* This is free and unencumbered software released into the public domain. */

#ifndef _CPRIME_ITER_H
#define _CPRIME_ITER_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct iter_interface_t {
  int (*dispose)(void* iter);
} iter_interface_t;

typedef struct iter_t {
  iter_interface_t* methods;
  void* user_data;
  int position;
} iter_t;

extern iter_t* iter_alloc();
extern void iter_free(iter_t* iter);

extern int iter_init(iter_t* iter);
extern int iter_init_with(iter_t* iter, const iter_interface_t* methods, const void* user_data);

extern int iter_dispose(iter_t* iter);

#ifdef __cplusplus
}
#endif

#endif /* _CPRIME_ITER_H */
