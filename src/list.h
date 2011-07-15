/* This is free and unencumbered software released into the public domain. */

#ifndef _CPRIME_LIST_H
#define _CPRIME_LIST_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h> /* for size_t */

typedef struct {
  void* head;
  void* tail;
} list_element_t;

typedef struct {
  list_element_t* first;
  size_t length;
} list_t;

extern list_t* list_alloc();

#define LIST_INIT {.first = NULL, .length = 0}

extern int list_is_empty(const list_t* const list);

#ifdef __cplusplus
}
#endif

#endif /* _CPRIME_LIST_H */
