/* This is free and unencumbered software released into the public domain. */

#ifndef CPR_STRING_H
#define CPR_STRING_H

/**
 * @file
 *
 * @include string.c
 * @example string.c
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

/*
 * Abbreviated type, variable, and function names if the `CPR_ABBREV`
 * preprocessor symbol is defined:
 */
#ifdef CPR_ABBREV
  /** Alias for `::cpr_string_t` when `CPR_ABBREV` is defined. */
  #define string_t      cpr_string_t
  /** Alias for `#cpr_string_sizeof` when `CPR_ABBREV` is defined. */
  #define string_sizeof cpr_string_sizeof
  /** Alias for `cpr_string_alloc()` when `CPR_ABBREV` is defined. */
  #define string_alloc  cpr_string_alloc
  /** Alias for `cpr_string_free()` when `CPR_ABBREV` is defined. */
  #define string_free   cpr_string_free
#endif /* CPR_ABBREV */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* CPR_STRING_H */
