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

////////////////////////////////////////////////////////////////////////////////
/* Constants */

/**
 * The size of the `cpr_string_t` opaque type, i.e., `sizeof(cpr_string_t)`.
 */
extern const size_t cpr_string_sizeof;

/**
 * The largest possible string length; equal to `(size_t)-1`.
 */
extern const size_t cpr_string_npos;

////////////////////////////////////////////////////////////////////////////////
/* Constructors */

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

////////////////////////////////////////////////////////////////////////////////
/* Destructor */

/**
 * Deallocates the heap memory used by a string.
 *
 * @param  string a pointer to the string to deallocate, or a `NULL` pointer
 * @post   the `string` pointer is invalidated
 */
void cpr_string_free(cpr_string_t* string);

////////////////////////////////////////////////////////////////////////////////
/* Methods */

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
 * @param  string a pointer to the string to be mutated
 * @param  str a pointer to a NUL-terminated C string
 * @param  length the number of characters to append,
 *         or `cpr_string_npos` to append all characters
 * @pre    `string` is not a `NULL` pointer
 * @pre    `str` is not a `NULL` pointer
 * @error  EOVERFLOW if the length would exceed `max_size()`
 * @error  ENOMEM if the allocation of storage failed
 */
void cpr_string_append_str(cpr_string_t* string,
  const char* str,
  size_t length);

/**
 * Appends a copy of `suffix` to a string.
 *
 * @param  string a pointer to the string to be mutated
 * @param  suffix a pointer to the string to append
 * @pre    `string` is not a `NULL` pointer
 * @pre    `suffix` is not a `NULL` pointer
 * @error  EOVERFLOW if the length would exceed `max_size()`
 * @error  ENOMEM if the allocation of storage failed
 */
void cpr_string_append_string(cpr_string_t* string,
  const cpr_string_t* suffix);

/**
 * Replaces a string's value by `count` consecutive copies of `character`.
 *
 * @param  string a pointer to the string to be mutated
 * @param  count the number of times to repeat `character`
 * @param  character the character to insert
 * @pre    `string` is not a `NULL` pointer
 * @error  EOVERFLOW if the length would exceed `max_size()`
 * @error  ENOMEM if the allocation of storage failed
 */
void cpr_string_assign_char(cpr_string_t* string,
  size_t count,
  char character);

/**
 * Replaces a string's value using the first `length` characters of `str`.
 *
 * @param  string a pointer to the string to be mutated
 * @param  str a pointer to a NUL-terminated C string
 * @param  length the number of characters to copy,
 *         or `cpr_string_npos` to copy all characters
 * @pre    `string` is not a `NULL` pointer
 * @pre    `str` is not a `NULL` pointer
 * @error  EOVERFLOW if the length would exceed `max_size()`
 * @error  ENOMEM if the allocation of storage failed
 */
void cpr_string_assign_str(cpr_string_t* string,
  const char* str,
  size_t length);

/**
 * Replaces a string's value using the first `length` characters of `other`.
 *
 * @param  string a pointer to the string to be mutated
 * @param  other a pointer to another string
 * @param  length the number of characters to copy,
 *         or `cpr_string_npos` to copy all characters
 * @pre    `string` is not a `NULL` pointer
 * @pre    `other` is not a `NULL` pointer
 * @error  EOVERFLOW if the length would exceed `max_size()`
 * @error  ENOMEM if the allocation of storage failed
 */
void cpr_string_assign_string(cpr_string_t* string,
  const cpr_string_t* other,
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
 * Removes all characters from a string, leaving its size zero.
 *
 * @param  string a pointer to the string to be mutated
 * @pre    `string` is not a `NULL` pointer
 * @post   the size of `*string` is zero
 */
void cpr_string_clear(cpr_string_t* string);

/**
 * Compares two strings lexicographically.
 *
 * @param  string1 a pointer to the the first string to be compared
 * @param  string2 a pointer to the the second string to be compared
 * @pre    `string1` is not a `NULL` pointer
 * @pre    `string2` is not a `NULL` pointer
 * @return 0, < 0, or > 0
 */
int cpr_string_compare(const cpr_string_t* string1,
  const cpr_string_t* string2);

/**
 * Copies a sequence of characters from a string.
 *
 * @param[in]  string a pointer to the string to be accessed
 * @param[out] buffer a pointer to an output array of characters
 * @param[in]  position the position of the first character to be copied
 * @param[in]  length the number of characters to copy
 * @pre    `string` is not a `NULL` pointer
 * @pre    `buffer` is sufficiently large
 * @error  EDOM if `position` is out of bounds
 * @return the number of characters written to `buffer`
 */
size_t cpr_string_copy(const cpr_string_t* string,
  char* buffer,
  size_t position,
  size_t length);

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
 * Erases part of a string, reducing its length.
 *
 * @param  string a pointer to the string to be mutated
 * @param  position the position of the first character to be erased
 * @param  length the number of characters to erase,
 *         or `cpr_string_npos` to erase all characters after `position`
 * @pre    `string` is not a `NULL` pointer
 */
void cpr_string_erase(cpr_string_t* string,
  size_t position,
  size_t length);

/**
 * Searches a string for the first occurrence of a character.
 *
 * @param  string a pointer to the string to be searched
 * @param  character the character to search for
 * @param  position the position of the first character to be considered
 *         as the beginning of a successful match
 * @param  length the number of characters to match,
 *         or `cpr_string_npos` to match all characters
 * @pre    `string` is not a `NULL` pointer
 * @return the position of the first character of the first match,
 *         or `cpr_string_npos` if no matches were found
 */
size_t cpr_string_find_char(const cpr_string_t* string,
  char character,
  size_t position);

/**
 * Searches a string for the first occurrence of a substring.
 *
 * @param  string a pointer to the string to be searched
 * @param  substr a pointer to the C substring to search for
 * @param  position the position of the first character to be considered
 *         as the beginning of a successful match
 * @param  length the number of characters to match,
 *         or `cpr_string_npos` to match all characters
 * @pre    `string` is not a `NULL` pointer
 * @pre    `substr` is not a `NULL` pointer
 * @return the position of the first character of the first match,
 *         or `cpr_string_npos` if no matches were found
 */
size_t cpr_string_find_str(const cpr_string_t* string,
  const char* substr,
  size_t position,
  size_t length);

/**
 * Searches a string for the first occurrence of a substring.
 *
 * @param  string a pointer to the string to be searched
 * @param  substr a pointer to the substring to search for
 * @param  position the position of the first character to be considered
 *         as the beginning of a successful match
 * @param  length the number of characters to match,
 *         or `cpr_string_npos` to match all characters
 * @pre    `string` is not a `NULL` pointer
 * @pre    `substring` is not a `NULL` pointer
 * @return the position of the first character of the first match,
 *         or `cpr_string_npos` if no matches were found
 */
size_t cpr_string_find_string(const cpr_string_t* string,
  const cpr_string_t* substring,
  size_t position,
  size_t length);

/**
 * Returns a pointer to the first character in a string.
 *
 * @param  string a pointer to the string to be accessed
 * @pre    `string` is not a `NULL` pointer
 * @error  EFAULT if `*string` is empty
 * @return a pointer to the first character in `*string`,
 *         or a `NULL` pointer if an error occurred
 */
char* cpr_string_front(cpr_string_t* string);

/**
 * Inserts a character into a string at the given position.
 *
 * @param  string a pointer to the string to be mutated
 * @param  position the position where to insert the character
 * @param  character the character to insert
 * @param  length the number of characters to insert,
 *         or `cpr_string_npos` to insert all characters
 */
void cpr_string_insert_char(cpr_string_t* string,
  size_t position,
  char character,
  size_t count);

/**
 * Inserts a substring into a string at the given position.
 *
 * @param  string a pointer to the string to be mutated
 * @param  position the position where to insert the substring
 * @param  substr a pointer to the C substring to insert
 * @param  length the number of characters to insert,
 *         or `cpr_string_npos` to insert all characters
 */
void cpr_string_insert_str(cpr_string_t* string,
  size_t position,
  const char* substr,
  size_t length);

/**
 * Inserts a substring into a string at the given position.
 *
 * @param  string a pointer to the string to be mutated
 * @param  position the position where to insert the substring
 * @param  substring a pointer to the substring to insert
 * @param  length the number of characters to insert,
 *         or `cpr_string_npos` to insert all characters
 */
void cpr_string_insert_string(cpr_string_t* string,
  size_t position,
  const cpr_string_t* substring,
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
 * @post   the size of `*string` is increased by one
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
 * @param  character the fill character used when extending
 * @pre    `string` is not a `NULL` pointer
 * @error  EOVERFLOW if the length would exceed `max_size()`
 * @error  ENOMEM if the allocation of storage failed
 * @post   the size of `*string` is equal to `size`
 */
void cpr_string_resize(cpr_string_t* string,
  size_t size,
  char character);

/**
 * Searches a string for the last occurrence of a character.
 *
 * @param  string a pointer to the string to be searched
 * @param  character the character to search for
 * @param  position the position of the last character to be considered
 *         as the beginning of a successful match
 * @param  length the number of characters to match,
 *         or `cpr_string_npos` to match all characters
 * @pre    `string` is not a `NULL` pointer
 * @return the position of the first character of the last match,
 *         or `cpr_string_npos` if no matches were found
 */
size_t cpr_string_rfind_char(const cpr_string_t* string,
  char character,
  size_t position);

/**
 * Searches a string for the last occurrence of a substring.
 *
 * @param  string a pointer to the string to be searched
 * @param  substr a pointer to the C substring to search for
 * @param  position the position of the last character to be considered
 *         as the beginning of a successful match
 * @param  length the number of characters to match,
 *         or `cpr_string_npos` to match all characters
 * @pre    `string` is not a `NULL` pointer
 * @pre    `substr` is not a `NULL` pointer
 * @return the position of the first character of the last match,
 *         or `cpr_string_npos` if no matches were found
 */
size_t cpr_string_rfind_str(const cpr_string_t* string,
  const char* substr,
  size_t position,
  size_t length);

/**
 * Searches a string for the last occurrence of a substring.
 *
 * @param  string a pointer to the string to be searched
 * @param  substr a pointer to the substring to search for
 * @param  position the position of the last character to be considered
 *         as the beginning of a successful match
 * @param  length the number of characters to match,
 *         or `cpr_string_npos` to match all characters
 * @pre    `string` is not a `NULL` pointer
 * @pre    `substring` is not a `NULL` pointer
 * @return the position of the first character of the last match,
 *         or `cpr_string_npos` if no matches were found
 */
size_t cpr_string_rfind_string(const cpr_string_t* string,
  const cpr_string_t* substring,
  size_t position,
  size_t length);

/**
 * Requests that a string reduce its capacity to fit its size.
 *
 * @param  string a pointer to the string to be mutated
 * @pre    `string` is not a `NULL` pointer
 * @error  ENOMEM if the allocation of storage failed
 */
void cpr_string_shrink_to_fit(cpr_string_t* string);

/**
 * Returns the byte length of a string.
 *
 * @param  string a pointer to the string to be accessed
 * @pre    `string` is not a `NULL` pointer
 * @return the byte length of `*string`
 */
size_t cpr_string_size(const cpr_string_t* string);

/**
 * Returns a newly-constructed substring of a string.
 *
 * @param  string a pointer to the string to be accessed
 * @param  position the position of the first character to be copied
 * @param  length the number of characters to copy,
 *         or `cpr_string_npos` to copy all characters
 * @pre    `string` is not a `NULL` pointer
 * @return a pointer to a new heap-allocated string,
 *         or a `NULL` pointer if an error occurred
 * @error  EDOM if `position` is out of bounds
 * @error  ENOMEM if the allocation of storage failed
 */
cpr_string_t* cpr_string_substr(const cpr_string_t* string,
  size_t position,
  size_t length);

/**
 * Exchanges the contents of two strings.
 *
 * @param  string1 a pointer to the first string to be mutated
 * @param  string2 a pointer to the second string to be mutated
 * @pre    `string1` is not a `NULL` pointer
 * @pre    `string2` is not a `NULL` pointer
 */
void cpr_string_swap(cpr_string_t* string1, cpr_string_t* string2);

////////////////////////////////////////////////////////////////////////////////
/* Abbreviations */

/*
 * Abbreviated type, variable, and function names if the `CPR_ABBREV`
 * preprocessor symbol is defined:
 */
#ifdef CPR_ABBREV
  /** Alias for `::cpr_string_t` when `CPR_ABBREV` is defined. */
  #define string_t             cpr_string_t
  /** Alias for `cpr_string()` when `CPR_ABBREV` is defined. */
  #define string               cpr_string
  /** Alias for `cpr_string_alloc()` when `CPR_ABBREV` is defined. */
  #define string_alloc         cpr_string_alloc
  /** Alias for `cpr_string_append_char()` when `CPR_ABBREV` is defined. */
  #define string_append_char   cpr_string_append_char
  /** Alias for `cpr_string_append_str()` when `CPR_ABBREV` is defined. */
  #define string_append_str    cpr_string_append_str
  /** Alias for `cpr_string_append_string()` when `CPR_ABBREV` is defined. */
  #define string_append_string cpr_string_append_string
  /** Alias for `cpr_string_assign_char()` when `CPR_ABBREV` is defined. */
  #define string_assign_char   cpr_string_assign_char
  /** Alias for `cpr_string_assign_str()` when `CPR_ABBREV` is defined. */
  #define string_assign_str    cpr_string_assign_str
  /** Alias for `cpr_string_assign_string()` when `CPR_ABBREV` is defined. */
  #define string_assign_string cpr_string_assign_string
  /** Alias for `cpr_string_at()` when `CPR_ABBREV` is defined. */
  #define string_at            cpr_string_at
  /** Alias for `cpr_string_back()` when `CPR_ABBREV` is defined. */
  #define string_back          cpr_string_back
  /** Alias for `cpr_string_capacity()` when `CPR_ABBREV` is defined. */
  #define string_capacity      cpr_string_capacity
  /** Alias for `cpr_string_clear()` when `CPR_ABBREV` is defined. */
  #define string_clear         cpr_string_clear
  /** Alias for `cpr_string_compare()` when `CPR_ABBREV` is defined. */
  #define string_compare       cpr_string_compare
  /** Alias for `cpr_string_copy()` when `CPR_ABBREV` is defined. */
  #define string_copy          cpr_string_copy
  /** Alias for `cpr_string_data()` when `CPR_ABBREV` is defined. */
  #define string_data          cpr_string_data
  /** Alias for `cpr_string_empty()` when `CPR_ABBREV` is defined. */
  #define string_empty         cpr_string_empty
  /** Alias for `cpr_string_erase()` when `CPR_ABBREV` is defined. */
  #define string_erase         cpr_string_erase
  /** Alias for `cpr_string_find_char()` when `CPR_ABBREV` is defined. */
  #define string_find_char     cpr_string_find_char
  /** Alias for `cpr_string_find_str()` when `CPR_ABBREV` is defined. */
  #define string_find_str      cpr_string_find_str
  /** Alias for `cpr_string_find_string()` when `CPR_ABBREV` is defined. */
  #define string_find_string   cpr_string_find_string
  /** Alias for `cpr_string_free()` when `CPR_ABBREV` is defined. */
  #define string_free          cpr_string_free
  /** Alias for `cpr_string_front()` when `CPR_ABBREV` is defined. */
  #define string_front         cpr_string_front
  /** Alias for `cpr_string_insert_char()` when `CPR_ABBREV` is defined. */
  #define string_insert_char   cpr_string_insert_char
  /** Alias for `cpr_string_insert_str()` when `CPR_ABBREV` is defined. */
  #define string_insert_str    cpr_string_insert_str
  /** Alias for `cpr_string_insert_string()` when `CPR_ABBREV` is defined. */
  #define string_insert_string cpr_string_insert_string
  /** Alias for `cpr_string_length()` when `CPR_ABBREV` is defined. */
  #define string_length        cpr_string_length
  /** Alias for `cpr_string_max_size()` when `CPR_ABBREV` is defined. */
  #define string_max_size      cpr_string_max_size
  /** Alias for `cpr_string_npos` when `CPR_ABBREV` is defined. */
  #define string_npos          cpr_string_npos
  /** Alias for `cpr_string_pop_back()` when `CPR_ABBREV` is defined. */
  #define string_pop_back      cpr_string_pop_back
  /** Alias for `cpr_string_push_back()` when `CPR_ABBREV` is defined. */
  #define string_push_back     cpr_string_push_back
  /** Alias for `cpr_string_reserve()` when `CPR_ABBREV` is defined. */
  #define string_reserve       cpr_string_reserve
  /** Alias for `cpr_string_resize()` when `CPR_ABBREV` is defined. */
  #define string_resize        cpr_string_resize
  /** Alias for `cpr_string_rfind_char()` when `CPR_ABBREV` is defined. */
  #define string_rfind_char    cpr_string_rfind_char
  /** Alias for `cpr_string_rfind_str()` when `CPR_ABBREV` is defined. */
  #define string_rfind_str     cpr_string_rfind_str
  /** Alias for `cpr_string_rfind_string()` when `CPR_ABBREV` is defined. */
  #define string_rfind_string  cpr_string_rfind_string
  /** Alias for `cpr_string_shrink_to_fit()` when `CPR_ABBREV` is defined. */
  #define string_shrink_to_fit cpr_string_shrink_to_fit
  /** Alias for `cpr_string_size()` when `CPR_ABBREV` is defined. */
  #define string_size          cpr_string_size
  /** Alias for `cpr_string_sizeof` when `CPR_ABBREV` is defined. */
  #define string_sizeof        cpr_string_sizeof
  /** Alias for `cpr_string_substr()` when `CPR_ABBREV` is defined. */
  #define string_substr        cpr_string_substr
  /** Alias for `cpr_string_swap()` when `CPR_ABBREV` is defined. */
  #define string_swap          cpr_string_swap
#endif /* CPR_ABBREV */

////////////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* CPR_STRING_H */
