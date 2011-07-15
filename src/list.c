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

  list_element_t* const element = malloc(sizeof(list_element_t));
  element->head = (void*)ptr;
  element->tail = list->first;

  return list_prepend_element(list, element);
}

int
list_prepend_element(list_t* list, const list_element_t* const element) {
  validate_with_errno_return(list != NULL);

  list->first = (list_element_t*)element;
  list->length += 1;

  return list->length;
}
