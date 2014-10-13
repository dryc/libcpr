/* This is free and unencumbered software released into the public domain. */

#ifndef CPR_LIST_H
#define CPR_LIST_H

/**
 * @file
 *
 * @include list.c
 *
 * http://en.wikipedia.org/wiki/Linked_list#Doubly_linked_list
 *
 * @example list.c
 */

#include "types.h"

#include <stddef.h> /* for size_t */

#ifdef __cplusplus
extern "C" {
#endif

////////////////////////////////////////////////////////////////////////////////
/* Constants */

/**
 * The size of the `cpr_list_t` opaque type, i.e., `sizeof(cpr_list_t)`.
 */
extern const size_t cpr_list_sizeof;

////////////////////////////////////////////////////////////////////////////////
/* Constructors */

/**
 * Allocates heap memory for a new `cpr_list_t` structure.
 *
 * @error  ENOMEM if the allocation of storage failed
 * @return a pointer to the beginning of the allocated heap space,
 *         or a `NULL` pointer if an error occurred
 * @note   before use, the structure must first be initialized
 * @see    cpr_list_alloca()
 */
cpr_list_t* cpr_list_alloc(void);

////////////////////////////////////////////////////////////////////////////////
/* Destructor */

/**
 * Deallocates the heap memory used by a list.
 *
 * @param list a pointer to the list to deallocate, or a `NULL` pointer
 * @post  the `list` pointer is invalidated
 */
void cpr_list_free(cpr_list_t* list);

////////////////////////////////////////////////////////////////////////////////
/* Abbreviations */

/*
 * Abbreviated type, variable, and function names if the `CPR_ABBREV`
 * preprocessor symbol is defined:
 */
#ifdef CPR_ABBREV
  /** Alias for `::cpr_list_t` when `CPR_ABBREV` is defined. */
  #define list_t      cpr_list_t
  /** Alias for `#cpr_list_sizeof` when `CPR_ABBREV` is defined. */
  #define list_sizeof cpr_list_sizeof
  /** Alias for `cpr_list_alloc()` when `CPR_ABBREV` is defined. */
  #define list_alloc  cpr_list_alloc
  /** Alias for `cpr_list_free()` when `CPR_ABBREV` is defined. */
  #define list_free   cpr_list_free
#endif /* CPR_ABBREV */

////////////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* CPR_LIST_H */
