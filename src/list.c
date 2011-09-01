/* This is free and unencumbered software released into the public domain. */

#include "build.h"

list_t*
list_alloc() {
  return calloc(1, sizeof(list_t));
}

void
list_free(list_t* const list) {
  validate_with_void_return(list != NULL);
  list_reset(list);
  free(list);
}

int
list_init(list_t* const list) {
  return list_init_with(list, NULL, free);
}

int
list_init_with(list_t* const restrict list, const compare_func_t compare_func,
                                            const free_func_t free_func) {
  validate_with_errno_return(list != NULL);

  bzero(list, sizeof(list_t));

  list->first        = LIST_SENTINEL;
  list->length       = 0;
  list->compare_func = compare_func;
  list->free_func    = free_func;

  return 0;
}

int
list_reset(list_t* const list) {
  return list_clear(list);
}

int
list_clear(list_t* const list) {
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
list_count(const list_t* const restrict list, const void* const restrict elt) {
  validate_with_zero_return(list != NULL);

  if (unlikely(list->length == 0))
    return 0;

  long count = 0;

  const pair_t* pair = list->first;
  while (likely(pair != LIST_SENTINEL)) {
    if (unlikely(pair->head == elt)) { // TODO: list->compare_func(pair->head, elt)
      count++;
    }
    pair = pair->tail;
  }

  return count;
}

bool
list_lookup(const list_t* const restrict list, const void* const restrict elt) {
  validate_with_false_return(list != NULL);

  if (unlikely(list->length == 0))
    return FALSE;

  const pair_t* pair = list->first;
  while (likely(pair != LIST_SENTINEL)) {
    if (unlikely(pair->head == elt)) { // TODO: list->compare_func(pair->head, elt)
      return TRUE;
    }
    pair = pair->tail;
  }

  return FALSE;
}

int
list_prepend_bool(list_t* const list, const bool_t value) {
  validate_with_errno_return(list != NULL);

  return list_prepend_ptr(list, (void*)((intptr_t)value));
}

int
list_prepend_byte(list_t* const list, const byte_t value) {
  validate_with_errno_return(list != NULL);

  return list_prepend_ptr(list, (void*)((uintptr_t)value));
}

int
list_prepend_char(list_t* const list, const char_t value) {
  validate_with_errno_return(list != NULL);

  return list_prepend_ptr(list, (void*)((uintptr_t)value));
}

int
list_prepend_ptr(list_t* const restrict list, const void* const restrict ptr) {
  validate_with_errno_return(list != NULL);

  pair_t* const restrict pair = pair_construct((void*)ptr, list->first);

  return list_prepend_pair(list, pair);
}

int
list_prepend_pair(list_t* const restrict list, const pair_t* const restrict pair) {
  validate_with_errno_return(list != NULL);

  list->first = (pair_t*)pair;
  list->length += 1;

  return list->length;
}

int
list_reverse(list_t* const list) {
  validate_with_errno_return(list != NULL);

  if (unlikely(list->length <= 1))
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
