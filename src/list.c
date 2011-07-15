/* This is free and unencumbered software released into the public domain. */

#include "build.h"
#include <stdlib.h> /* for calloc() */

list_t*
list_alloc() {
  return calloc(1, sizeof(list_t));
}

int
list_is_empty(const list_t* const list) {
  return unlikely(list->first == NULL) ? TRUE : FALSE;
}

int
list_prepend_bool(list_t* list, const bool_t value) {
  return list_prepend_ptr(list, (void*)((intptr_t)value));
}

int
list_prepend_byte(list_t* list, const byte_t value) {
  return list_prepend_ptr(list, (void*)((uintptr_t)value));
}

int
list_prepend_char(list_t* list, const char_t value) {
  return list_prepend_ptr(list, (void*)((uintptr_t)value));
}

int
list_prepend_ptr(list_t* list, const void* const ptr) {
  validate_with_errno_return(list != NULL);

  pair_t* const pair = pair_alloc();
  pair_init_with(pair, (void*)ptr, list->first);

  return list_prepend_pair(list, pair);
}

int
list_prepend_pair(list_t* list, const pair_t* const pair) {
  validate_with_errno_return(list != NULL);

  list->first = (pair_t*)pair;
  list->length += 1;

  return list->length;
}
