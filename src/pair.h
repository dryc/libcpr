/* This is free and unencumbered software released into the public domain. */

#ifndef _CPRIME_PAIR_H
#define _CPRIME_PAIR_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct pair_t {
  void* head;
  struct pair_t* tail;
} pair_t;

extern pair_t* pair_alloc();

#define PAIR_INIT {.head = NULL, .tail = NULL}

extern int pair_init_empty(pair_t* pair);
extern int pair_init_with(pair_t* pair, const void* const head, const pair_t* const tail);

#define pair_init(pair)                 pair_init_empty(pair)
#define pair_init_with_head(pair, head) pair_init_with(pair, head, NULL)
#define pair_init_with_tail(pair, tail) pair_init_with(pair, NULL, tail)

#ifdef __cplusplus
}
#endif

#endif /* _CPRIME_PAIR_H */
