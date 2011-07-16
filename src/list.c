/* This is free and unencumbered software released into the public domain. */

#include "build.h"

list_t*
list_alloc() {
  return calloc(1, sizeof(list_t));
}

int
list_length(const list_t* const list) {
  validate_with_errno_return(list != NULL);

  return list->length;
}

int
list_is_empty(const list_t* const list) {
  validate_with_errno_return(list != NULL);

  return unlikely(list->first == NULL) ? TRUE : FALSE;
}

int
list_clear(list_t* list) {
  validate_with_errno_return(list != NULL);

  if (likely(list->length > 0)) {
    pair_t* pair = list->first;

    list->first = NULL;
    list->length = 0;

    while (likely(pair != NULL)) {
      pair_t* tail = pair->tail;
      pair_free(pair);
      pair = tail;
    }
  }

  return 0;
}

int
list_prepend_bool(list_t* list, const bool_t value) {
  validate_with_errno_return(list != NULL);

  return list_prepend_ptr(list, (void*)((intptr_t)value));
}

int
list_prepend_byte(list_t* list, const byte_t value) {
  validate_with_errno_return(list != NULL);

  return list_prepend_ptr(list, (void*)((uintptr_t)value));
}

int
list_prepend_char(list_t* list, const char_t value) {
  validate_with_errno_return(list != NULL);

  return list_prepend_ptr(list, (void*)((uintptr_t)value));
}

int
list_prepend_ptr(list_t* list, const void* const ptr) {
  validate_with_errno_return(list != NULL);

  pair_t* const pair = pair_construct((void*)ptr, list->first);

  return list_prepend_pair(list, pair);
}

int
list_prepend_pair(list_t* list, const pair_t* const pair) {
  validate_with_errno_return(list != NULL);

  list->first = (pair_t*)pair;
  list->length += 1;

  return list->length;
}
