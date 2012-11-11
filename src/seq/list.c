/* This is free and unencumbered software released into the public domain. */

#include "build.h"

public const class_t list_class = {
  .name    = "list",
  .super   = &seq_class,
  .vtable  = &list_vtable.base,
};

public list_t*
list_alloc() {
  return seq_alloc();
}

public void
list_free(list_t* const list) {
  validate_with_void_return(is_nonnull(list));
  list_dispose(list);
  free(list);
}

public int
list_init(list_t* const list) {
  return seq_init(list, LIST, NULL, free);
}

public int
list_init_with(list_t* const restrict list,
               const compare_func_t compare_func,
               const free_func_t free_func) {
  return seq_init(list, LIST, compare_func, free_func);
}

public int
list_dispose(list_t* const list) {
  return list_clear(list);
}

public int
list_clear(list_t* const list) {
  validate_with_errno_return(is_nonnull(list));

  if (likely(list->length > 0)) {
    pair_t* pair = list->data;

    list->data   = LIST_SENTINEL;
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

  return SUCCESS;
}

public bool
list_is_empty(const list_t* const list) {
  validate_with_true_return(is_nonnull(list));

  return unlikely(list->data == LIST_SENTINEL) ? TRUE : FALSE;
}

public long
list_length(list_t* const list) {
  validate_with_zero_return(is_nonnull(list));

  return list->length;
}

public long
list_count(list_t* const restrict list, const void* const restrict elt) {
  validate_with_zero_return(is_nonnull(list));

  if (unlikely(list->length == 0))
    return 0; // the list is empty

  long count = 0;

  const compare_func_t compare = list->compare_func;
  const pair_t* pair = list->data;
  while (likely(pair != LIST_SENTINEL)) {
    if (unlikely(pair->head == elt || (compare && compare(pair->head, elt) == COMPARE_EQ))) {
      count++;
    }
    pair = pair->tail;
  }

  return count;
}

public bool
list_lookup(list_t* const restrict list, const void* const restrict elt) {
  validate_with_false_return(is_nonnull(list));

  if (unlikely(list->length == 0))
    return FALSE;

  const compare_func_t compare = list->compare_func;
  const pair_t* pair = list->data;
  while (likely(pair != LIST_SENTINEL)) {
    if (unlikely(pair->head == elt || (compare && compare(pair->head, elt) == COMPARE_EQ))) {
      return TRUE;
    }
    pair = pair->tail;
  }

  return FALSE;
}

public int
list_prepend_bool(list_t* const list, const bool_t value) {
  validate_with_errno_return(is_nonnull(list));

  return list_prepend_ptr(list, (void*)((intptr_t)value));
}

public int
list_prepend_byte(list_t* const list, const byte_t value) {
  validate_with_errno_return(is_nonnull(list));

  return list_prepend_ptr(list, (void*)((uintptr_t)value));
}

public int
list_prepend_char(list_t* const list, const char_t value) {
  validate_with_errno_return(is_nonnull(list));

  return list_prepend_ptr(list, (void*)((uintptr_t)value));
}

public int
list_prepend_ptr(list_t* const restrict list,
                 const void* const restrict ptr) {
  validate_with_errno_return(is_nonnull(list));

  pair_t* const restrict pair = pair_construct((void*)ptr, list->data);

  return list_prepend_pair(list, pair);
}

public int
list_prepend_pair(list_t* const restrict list,
                  const pair_t* const restrict pair) {
  validate_with_errno_return(is_nonnull(list));

  list->data = (pair_t*)pair;
  list->length += 1;

  return list->length;
}

public int
list_insert(list_t* const restrict list,
            const void* const restrict elt) {
  validate_with_errno_return(is_nonnull(list));

  (void)list, (void)elt;
  return FAILURE(ENOTSUP); // TODO
}

public int
list_remove(list_t* const restrict list,
            const void* const restrict elt) {
  validate_with_errno_return(is_nonnull(list));

  (void)list, (void)elt;
  return FAILURE(ENOTSUP); // TODO
}

public int
list_replace(list_t* const restrict list,
             const void* const restrict elt1,
             const void* const restrict elt2) {
  validate_with_errno_return(is_nonnull(list));

  (void)list, (void)elt1, (void)elt2;
  return FAILURE(ENOTSUP); // TODO
}

public int
list_reverse(list_t* const list) {
  validate_with_errno_return(is_nonnull(list));

  if (unlikely(list->length <= 1))
    return SUCCESS; // nothing to do

  pair_t* prev = LIST_SENTINEL;
  {
    pair_t* pair = list->data;
    while (likely(pair != LIST_SENTINEL)) {
      pair_t* next = pair->tail;
      pair->tail = prev;
      prev = pair;
      pair = next;
    }
  }
  list->data = prev;

  return SUCCESS;
}

public int
list_sort(list_t* const list, const seq_sort_type_t how) {
  validate_with_errno_return(is_nonnull(list));
  validate_with_errno_return(how > SEQ_SORT_NONE);

  return FAILURE(ENOTSUP); // TODO
}

public const seq_vtable_t list_vtable = {
  .base    = {.klass = &list_class},
  .init    = NULL,
  .dispose = list_dispose,
  .clear   = list_clear,
  .length  = list_length,
  .count   = list_count,
  .lookup  = list_lookup,
  .insert  = list_insert,
  .remove  = list_remove,
  .replace = list_replace,
  .reverse = list_reverse,
  .sort    = list_sort,
};

/* List Iterator API */

public const iter_interface_t list_iter_interface = {
  .next = (iter_next_t)list_iter_next,
};

public int
list_iter_next(list_iter_t* iter) {
  validate_with_errno_return(iter != NULL);

  if (likely(iter->element != NULL)) {
    iter->current = iter->element->head;
    iter->element = iter->element->tail;
    return TRUE;
  }

  return FALSE;
}
