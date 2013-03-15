/* This is free and unencumbered software released into the public domain. */

#ifndef CPR_STRING_H
#define CPR_STRING_H

/**
 * @file
 */

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h> /* for size_t */

/**
 * An opaque type representing a dynamic string.
 */
typedef struct cpr_string cpr_string_t;

/**
 * The size of the `cpr_string_t` opaque type, i.e., `sizeof(cpr_string_t)`.
 */
extern const size_t cpr_string_sizeof;

/**
 * Returns a pointer to a new heap-allocated `cpr_string_t` structure.
 */
cpr_string_t* cpr_string_alloc(void);

/**
 * ...
 */
void cpr_string_free(cpr_string_t* string);

/**
 * Abbreviated type and function names when `CPR_ABBREV` is defined:
 */
#ifdef CPR_ABBREV
  #define string_t      cpr_string_t
  #define string_sizeof cpr_string_sizeof
  #define string_alloc  cpr_string_alloc
  #define string_free   cpr_string_free
#endif /* CPR_ABBREV */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* CPR_STRING_H */
