/* This is free and unencumbered software released into the public domain. */

#ifndef _CPRIME_PAIR_H
#define _CPRIME_PAIR_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct pair_t {
  struct pair_t* tail;
  void* head;
} pair_t;

extern pair_t* pair_alloc();
extern void pair_free(pair_t* pair);

#define pair_construct0()               pair_alloc()
#define pair_construct1(head)           pair_construct_with(head, NULL)
#define pair_construct2(head, tail)     pair_construct_with(head, tail)
#define pair_construct(...)             CONCAT(pair_construct, ARITY(__VA_ARGS__))(__VA_ARGS__)

#define pair_construct_with_head(head)  pair_construct_with(head, NULL)
#define pair_construct_with_tail(tail)  pair_construct_with(NULL, tail)

extern pair_t* pair_construct_with(const void* const head, const pair_t* const tail);

#define PAIR_INIT                       {.head = NULL, .tail = NULL}

#define pair_init1(pair)                pair_init_empty(pair)
#define pair_init2(pair, head)          pair_init_with(pair, head, NULL)
#define pair_init3(pair, head, tail)    pair_init_with(pair, head, tail)
#define pair_init(...)                  CONCAT(pair_init, ARITY(__VA_ARGS__))(__VA_ARGS__)

#define pair_init_with_head(pair, head) pair_init_with(pair, head, NULL)
#define pair_init_with_tail(pair, tail) pair_init_with(pair, NULL, tail)

extern int pair_init_empty(pair_t* pair);
extern int pair_init_with(pair_t* pair, const void* const head, const pair_t* const tail);

extern int pair_dispose(pair_t* pair);

#ifdef __cplusplus
}
#endif

#endif /* _CPRIME_PAIR_H */
