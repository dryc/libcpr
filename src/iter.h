/* This is free and unencumbered software released into the public domain. */

#ifndef CPRIME_ITER_H
#define CPRIME_ITER_H

#ifdef __cplusplus
extern "C" {
#endif

typedef bool (*iter_next_t)(void* iter);

typedef struct iter_interface_t {
  iter_next_t next;
  int (*init)(void* iter);
  int (*dispose)(void* iter);
} iter_interface_t;

typedef struct iter_t {
  const iter_interface_t* methods;
  void* user_data;
  unsigned int position;
} iter_t;

extern iter_t* iter_alloc();
extern void iter_free(iter_t* iter);

#define ITER_INIT(methods, user_data) {methods, user_data, 0}

extern int iter_init(iter_t* iter);
extern int iter_init_with(iter_t* iter,
                          const iter_interface_t* restrict methods,
                          const void* restrict user_data);

extern int iter_dispose(iter_t* iter);

extern bool iter_next(void* iter);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* CPRIME_ITER_H */
