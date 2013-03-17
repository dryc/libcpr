/* This is free and unencumbered software released into the public domain. */

#ifndef CPR_STRING_H
#define CPR_STRING_H

/**
 * @file
 *
 * @include string.c
 *
 * @see http://en.wikipedia.org/wiki/String_(computer_science)
 *
 * @example string.c
 */

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h> /* for bool */
#include <stddef.h>  /* for size_t */

/**
 * An opaque type representing a dynamic string.
 */
typedef struct cpr_string cpr_string_t;

/**
 * The size of the `cpr_string_t` opaque type, i.e., `sizeof(cpr_string_t)`.
 */
extern const size_t cpr_string_sizeof;

/**
 * Constructs a new string from the given NUL-terminated input.
 *
 * @param  str a NUL-terminated character string
 * @error  EINVAL if the length would exceed `max_size()`
 * @error  ENOMEM if the allocation of storage failed
 * @return a pointer to a new heap-allocated string,
 *         or a `NULL` pointer if an error occurred
 */
cpr_string_t* cpr_string(const char* str);

/**
 * Allocates heap memory for a new `cpr_string_t` structure.
 *
 * @error  ENOMEM if the allocation of storage failed
 * @return a pointer to the beginning of the allocated heap space,
 *         or a `NULL` pointer if an error occurred
 * @note   before use, the structure must first be initialized
 * @see    cpr_string_alloca()
 */
cpr_string_t* cpr_string_alloc(void);

/**
 * Deallocates the heap memory used by a string.
 *
 * @param string a pointer to the string to deallocate, or a `NULL` pointer
 * @post  the `string` pointer is invalidated
 */
void cpr_string_free(cpr_string_t* string);

/**
 * Tests whether a string is empty, i.e., whether its size is zero.
 *
 * @param  string a pointer to the string to be accessed
 * @pre    `string` is not a `NULL` pointer
 * @retval true if `*string` contains no characters
 * @retval false otherwise
 */
bool cpr_string_empty(const cpr_string_t* string);

/**
 * Returns the byte length of a string.
 *
 * @param  string a pointer to the string to be accessed
 * @pre    `string` is not a `NULL` pointer
 * @return the byte length of `*string`
 */
size_t cpr_string_size(const cpr_string_t* string);

/**
 * Alias for `cpr_string_size()`.
 *
 * @param  string a pointer to the string to be accessed
 * @pre    `string` is not a `NULL` pointer
 * @return the byte length of `*string`
 */
size_t cpr_string_length(const cpr_string_t* string);

/*
 * Abbreviated type, variable, and function names if the `CPR_ABBREV`
 * preprocessor symbol is defined:
 */
#ifdef CPR_ABBREV
  /** Alias for `::cpr_string_t` when `CPR_ABBREV` is defined. */
  #define string_t      cpr_string_t
  /** Alias for `#cpr_string_sizeof` when `CPR_ABBREV` is defined. */
  #define string_sizeof cpr_string_sizeof
  /** Alias for `cpr_string()` when `CPR_ABBREV` is defined. */
  #define string        cpr_string
  /** Alias for `cpr_string_alloc()` when `CPR_ABBREV` is defined. */
  #define string_alloc  cpr_string_alloc
  /** Alias for `cpr_string_free()` when `CPR_ABBREV` is defined. */
  #define string_free   cpr_string_free
  /** Alias for `cpr_string_empty()` when `CPR_ABBREV` is defined. */
  #define string_empty  cpr_string_empty
  /** Alias for `cpr_string_size()` when `CPR_ABBREV` is defined. */
  #define string_size   cpr_string_size
  /** Alias for `cpr_string_length()` when `CPR_ABBREV` is defined. */
  #define string_length cpr_string_length
#endif /* CPR_ABBREV */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* CPR_STRING_H */
