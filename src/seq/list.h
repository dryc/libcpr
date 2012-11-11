/* This is free and unencumbered software released into the public domain. */

#ifndef CPRIME_LIST_H
#define CPRIME_LIST_H

#ifdef __cplusplus
extern "C" {
#endif

#define LIST (&list_class)

/**
 * The list class.
 */
extern const class_t list_class;

/**
 * The canonical end-of-list sentinel value.
 */
#define LIST_SENTINEL NULL

/**
 * Represents a singly-linked list sequence.
 */
typedef seq_t list_t;

extern const seq_vtable_t list_vtable;

/**
 * Checks whether a given object is a list.
 */
#define is_list(obj)  ((obj)->vtable == &list_vtable)

/**
 * Allocates heap memory for a new list.
 */
extern list_t* list_alloc();

/**
 * Releases the heap memory used by a list.
 */
extern void list_free(list_t* list);

/**
 * Initializes a stack-allocated list.
 */
#define LIST_INIT {             \
    .vtable    = &list_vtable,  \
    .data      = LIST_SENTINEL, \
    .length    = 0,             \
    .free_func = free           \
  }

/**
 * Initializes a heap-allocated list.
 */
extern int list_init(list_t* list);

/**
 * Initializes a heap-allocated list with the given options.
 */
extern int list_init_with(list_t* restrict list,
  compare_func_t compare_func,
  free_func_t free_func);

/**
 * Resets a list back to an uninitialized state.
 */
extern int list_dispose(list_t* list);

/**
 * Removes all elements from a list.
 */
extern int list_clear(list_t* list);

/**
 * Checks whether a list contains any elements.
 */
extern bool list_is_empty(const list_t* list);

/**
 * Returns the length of a list.
 */
extern long list_length(list_t* list);

/**
 * Counts occurrences of a given element in a list.
 */
extern long list_count(list_t* restrict list,
  const void* restrict elt);

/**
 * Checks whether a list contains a given element.
 */
extern bool list_lookup(list_t* restrict set,
  const void* restrict elt);

/**
 * Prepends a given element to a list.
 */
#define list_prepend(list, ptr) list_prepend_ptr(list, ptr)

extern int list_prepend_bool(list_t* list, bool_t value);
extern int list_prepend_byte(list_t* list, byte_t value);
extern int list_prepend_char(list_t* list, char_t value);
extern int list_prepend_ptr(list_t* restrict list, const void* restrict ptr);
extern int list_prepend_pair(list_t* restrict list, const pair_t* restrict pair);

/**
 * Reverses a list.
 */
extern int list_reverse(list_t* list);

/**
 * Represents a list iterator.
 */
typedef struct list_iter_t {
  iter_t iter;
  pair_t* element;
  void* current;
} list_iter_t;

extern const iter_interface_t list_iter_interface;

/**
 * Initializes a stack-allocated list iterator.
 */
#define LIST_ITER_INIT(list) {                        \
  .iter    = ITER_INIT(&list_iter_interface, (list)), \
  .element = (list)->data,                            \
  .current = NULL,                                    \
}

/**
 * Advances the iterator to the next list element.
 */
extern int list_iter_next(list_iter_t* iter);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* CPRIME_LIST_H */
