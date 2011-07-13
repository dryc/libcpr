/* This is free and unencumbered software released into the public domain. */

#ifndef _CPRIME_LIST_H
#define _CPRIME_LIST_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
  void* head;
  void* tail;
} list_element_t;

typedef struct {
  list_element_t* first;
  int length;
} list_t;

#ifdef __cplusplus
}
#endif

#endif /* _CPRIME_LIST_H */
