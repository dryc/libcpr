/* This is free and unencumbered software released into the public domain. */

#ifndef CPR_LIST_H
#define CPR_LIST_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h> /* for size_t */

/**
 * An opaque type representing a doubly-linked list.
 */
typedef struct cpr_list cpr_list_t;

/**
 * The size of the cpr_list_t opaque type, i.e., sizeof(cpr_list_t).
 */
extern const size_t cpr_list_sizeof;

/**
 * ...
 */
cpr_list_t* cpr_list_alloc(void);

/**
 * ...
 */
void cpr_list_free(cpr_list_t* list);

/**
 * Abbreviated type and function names when CPR_ABBREV is defined.
 */
#ifdef CPR_ABBREV
  #define list_t      cpr_list_t
  #define list_sizeof cpr_list_sizeof
  #define list_alloc  cpr_list_alloc
  #define list_free   cpr_list_free
#endif /* CPR_ABBREV */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* CPR_LIST_H */
