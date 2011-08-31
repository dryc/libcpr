/* This is free and unencumbered software released into the public domain. */

#include "build.h"

list_t*
list_alloc() {
  return calloc(1, sizeof(list_t));
}

int
list_init(list_t* const list) {
  validate_with_errno_return(list != NULL);

  bzero(list, sizeof(list_t));

  list->first     = LIST_SENTINEL;
  list->length    = 0;
  list->free_func = free;

  return 0;
}

bool
list_is_empty(const list_t* const list) {
  validate_with_true_return(list != NULL);

  return unlikely(list->first == LIST_SENTINEL) ? TRUE : FALSE;
}

long
list_length(const list_t* const list) {
  validate_with_zero_return(list != NULL);

  return list->length;
}

long
list_count(const list_t* const restrict list, const void* const restrict ptr) {
  validate_with_zero_return(list != NULL);

  if (unlikely(ptr == NULL))
    return list->length;

  if (unlikely(list->length == 0))
    return 0;

  long count = 0;

  const pair_t* pair = list->first;
  while (likely(pair != LIST_SENTINEL)) {
    if (unlikely(pair->head == ptr)) {
      count++;
    }
    pair = pair->tail;
  }

  return count;
}

int
list_clear(list_t* list) {
  validate_with_errno_return(list != NULL);

  if (likely(list->length > 0)) {
    pair_t* pair = list->first;

    list->first  = LIST_SENTINEL;
    list->length = 0;

    while (likely(pair != LIST_SENTINEL)) {
      pair_t* const tail = pair->tail;

      if (likely(pair->head != NULL && list->free_func != NULL)) {
        list->free_func(pair->head);
        pair->head = NULL;
      }
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

int
list_reverse(list_t* list) {
  validate_with_errno_return(list != NULL);

  if (unlikely(list->length < 2))
    return 0; // nothing to do

  pair_t* prev = LIST_SENTINEL;
  {
    pair_t* pair = list->first;
    while (likely(pair != LIST_SENTINEL)) {
      pair_t* next = pair->tail;
      pair->tail = prev;
      prev = pair;
      pair = next;
    }
  }
  list->first = prev;

  return 0;
}

/* List Iterator API */

const iter_interface_t list_iter_interface = {
  .next = (iter_next_t)list_iter_next,
};

int
list_iter_next(list_iter_t* iter) {
  validate_with_errno_return(iter != NULL);

  if (likely(iter->element != NULL)) {
    iter->current = iter->element->head;
    iter->element = iter->element->tail;
    return TRUE;
  }

  return FALSE;
}
