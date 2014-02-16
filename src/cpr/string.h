/* This is free and unencumbered software released into the public domain. */

#ifndef CPR_STRING_H
#define CPR_STRING_H

/**
 * @file
 *
 * Dynamic string library.
 *
 * @include string.c
 *
 * @see http://en.wikipedia.org/wiki/String_(computer_science)
 *
 * @example string.c
 */

#include "types.h"

#include <stdbool.h> /* for bool */
#include <stddef.h>  /* for size_t */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * The size of the `cpr_string_t` opaque type, i.e., `sizeof(cpr_string_t)`.
 */
extern const size_t cpr_string_sizeof;

/**
 * The largest possible string length; equal to `(size_t)-1`.
 */
extern const size_t cpr_string_npos;

/**
 * Constructs a new string from the given NUL-terminated input.
 *
 * @param  str a NUL-terminated character string
 * @error  EOVERFLOW if the length would exceed `max_size()`
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
 * Appends `count` consecutive copies of `character` to a string.
 *
 * @param  string a pointer to the string to be mutated
 * @param  count the repeat count
 * @param  character the character to append
 * @pre    `string` is not a `NULL` pointer
 * @error  EOVERFLOW if the length would exceed `max_size()`
 * @error  ENOMEM if the allocation of storage failed
 */
void cpr_string_append_char(cpr_string_t* string,
  size_t count,
  char character);

/**
 * Appends a copy of the first `length` characters of `str` to a string.
 *
 * ...
 */
void cpr_string_append_str(cpr_string_t* string,
  const char* str,
  size_t length);

/**
 * Appends a copy of `suffix` to a string.
 *
 * ...
 */
void cpr_string_append_string(cpr_string_t* string,
  const cpr_string_t* suffix);

/**
 * ...
 */
void cpr_string_assign_char(cpr_string_t* string,
  size_t count,
  char character);

/**
 * ...
 */
void cpr_string_assign_str(cpr_string_t* string,
  const char* str,
  size_t length);

/**
 * Returns a pointer to the character at the given position in a string.
 *
 * @param  string a pointer to the string to be accessed
 * @param  position the position of a character in the string
 * @pre    `string` is not a `NULL` pointer
 * @error  EDOM if `position` is out of bounds
 * @return a pointer to the character at `position` in `*string`
 */
char* cpr_string_at(cpr_string_t* string,
  size_t position);

/**
 * Returns a pointer to the last character in a string.
 *
 * @param  string a pointer to the string to be accessed
 * @pre    `string` is not a `NULL` pointer
 * @error  EFAULT if `*string` is empty
 * @return a pointer to the last character in `*string`
 */
char* cpr_string_back(cpr_string_t* string);

/**
 * Returns the size of allocated storage for a string.
 *
 * @param  string a pointer to the string to be accessed
 * @pre    `string` is not a `NULL` pointer
 * @return the current storage capacity of `*string`
 */
size_t cpr_string_capacity(const cpr_string_t* string);

/**
 * Removes all elements from a string, leaving its size zero.
 *
 * @param  string a pointer to the string to be mutated
 * @pre    `string` is not a `NULL` pointer
 * @post   the size of `*string` is zero
 */
void cpr_string_clear(cpr_string_t* string);

/**
 * Compares two strings lexicographically.
 *
 * @param  string1 the first string to be compared
 * @param  string2 the second string to be compared
 * @pre    `string1` is not a `NULL` pointer
 * @pre    `string2` is not a `NULL` pointer
 * @return 0, < 0, or > 0
 */
int cpr_string_compare(const cpr_string_t* string1,
  const cpr_string_t* string2);

/**
 * ...
 */
size_t cpr_string_copy(const cpr_string_t* string, ...);

/**
 * Returns a direct pointer to a string's internal memory array.
 *
 * The returned pointer may be invalidated by further calls to other
 * functions that mutate the string.
 *
 * @param  string a pointer to the string to be accessed
 * @pre    `string` is not a `NULL` pointer
 * @return a pointer to the C string representation of `*string`
 */
char* cpr_string_data(cpr_string_t* string);

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
 * ...
 */
void cpr_string_erase(cpr_string_t* string,
  size_t position,
  size_t length);

/**
 * ...
 */
size_t cpr_string_find_char(const cpr_string_t* string,
  char character,
  size_t position);

/**
 * ...
 */
size_t cpr_string_find_str(const cpr_string_t* string,
  const char* str,
  size_t position);

/**
 * Deallocates the heap memory used by a string.
 *
 * @param  string a pointer to the string to deallocate, or a `NULL` pointer
 * @post   the `string` pointer is invalidated
 */
void cpr_string_free(cpr_string_t* string);

/**
 * Returns a pointer to the first character in a string.
 *
 * @param  string a pointer to the string to be accessed
 * @pre    `string` is not a `NULL` pointer
 * @error  EFAULT if `*string` is empty
 * @return a pointer to the first character in `*string`
 */
char* cpr_string_front(cpr_string_t* string);

/**
 * ...
 */
size_t cpr_string_insert_char(cpr_string_t* string,
  size_t position,
  char character,
  size_t count);

/**
 * ...
 */
size_t cpr_string_insert_str(cpr_string_t* string,
  size_t position,
  const char* str,
  size_t length);

/**
 * Alias for `cpr_string_size()`.
 *
 * @param  string a pointer to the string to be accessed
 * @pre    `string` is not a `NULL` pointer
 * @return the byte length of `*string`
 */
size_t cpr_string_length(const cpr_string_t* string);

/**
 * Returns the maximum size a string can reach.
 *
 * @param  string a pointer to the string to be accessed
 * @pre    `string` is not a `NULL` pointer
 * @return the maximum size `*string` can reach
 */
size_t cpr_string_max_size(const cpr_string_t* string);

/**
 * Removes the last character of a string, reducing its size by one.
 *
 * @param  string a pointer to the string to be mutated
 * @pre    `string` is not a `NULL` pointer
 * @error  EFAULT if `*string` is empty
 * @post   if `*string` was not empty, its size is reduced by one
 */
void cpr_string_pop_back(cpr_string_t* string);

/**
 * Appends a character to the end of a string, increasing its size by one.
 *
 * @param  string a pointer to the string to be mutated
 * @param  character the character to append
 * @pre    `string` is not a `NULL` pointer
 * @error  EOVERFLOW if the length would exceed `max_size()`
 * @error  ENOMEM if the allocation of storage failed
 */
void cpr_string_push_back(cpr_string_t* string,
  char character);

/**
 * Adjusts the minimum capacity of a string, allocating storage if necessary.
 *
 * @param  string a pointer to the string to be mutated
 * @param  capacity the new minimum capacity of the string
 * @pre    `string` is not a `NULL` pointer
 * @error  EOVERFLOW if the capacity would exceed `max_size()`
 * @error  ENOMEM if the allocation of storage failed
 * @post   the capacity of `*string` may be mutated
 */
void cpr_string_reserve(cpr_string_t* string,
  size_t capacity);

/**
 * Resizes a string, increasing or reducing its size.
 *
 * @param  string a pointer to the string to be mutated
 * @param  size the new size of the string
 * @param  character the fill character used when extended
 * @pre    `string` is not a `NULL` pointer
 * @error  EOVERFLOW if the length would exceed `max_size()`
 * @error  ENOMEM if the allocation of storage failed
 * @post   the size of `*string` is equal to `size`
 */
void cpr_string_resize(cpr_string_t* string,
  size_t size,
  char character);

/**
 * ...
 */
size_t cpr_string_rfind_char(const cpr_string_t* string,
  char character,
  size_t position);

/**
 * ...
 */
size_t cpr_string_rfind_str(const cpr_string_t* string,
  const char* str,
  size_t position);

/**
 * Returns the byte length of a string.
 *
 * @param  string a pointer to the string to be accessed
 * @pre    `string` is not a `NULL` pointer
 * @return the byte length of `*string`
 */
size_t cpr_string_size(const cpr_string_t* string);

/**
 * ...
 */
cpr_string_t* cpr_string_substr(const char* str,
  size_t position,
  size_t length);

/**
 * ...
 */
void cpr_string_swap(cpr_string_t* string1,
  cpr_string_t* string2);

/*
 * Abbreviated type, variable, and function names if the `CPR_ABBREV`
 * preprocessor symbol is defined:
 */
#ifdef CPR_ABBREV
  /** Alias for `::cpr_string_t` when `CPR_ABBREV` is defined. */
  #define string_t        cpr_string_t
  /** Alias for `#cpr_string_sizeof` when `CPR_ABBREV` is defined. */
  #define string_sizeof   cpr_string_sizeof
  /** Alias for `#cpr_string_npos` when `CPR_ABBREV` is defined. */
  #define string_npos     cpr_string_npos
  /** Alias for `cpr_string()` when `CPR_ABBREV` is defined. */
  #define string          cpr_string
  /** Alias for `cpr_string_alloc()` when `CPR_ABBREV` is defined. */
  #define string_alloc    cpr_string_alloc
  /** Alias for `cpr_string_free()` when `CPR_ABBREV` is defined. */
  #define string_free     cpr_string_free
  /** Alias for `cpr_string_empty()` when `CPR_ABBREV` is defined. */
  #define string_empty    cpr_string_empty
  /** Alias for `cpr_string_size()` when `CPR_ABBREV` is defined. */
  #define string_size     cpr_string_size
  /** Alias for `cpr_string_length()` when `CPR_ABBREV` is defined. */
  #define string_length   cpr_string_length
  /** Alias for `cpr_string_max_size()` when `CPR_ABBREV` is defined. */
  #define string_max_size cpr_string_max_size
  /** Alias for `cpr_string_capacity()` when `CPR_ABBREV` is defined. */
  #define string_capacity cpr_string_capacity
#endif /* CPR_ABBREV */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* CPR_STRING_H */
