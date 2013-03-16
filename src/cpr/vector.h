/* This is free and unencumbered software released into the public domain. */

#ifndef CPR_VECTOR_H
#define CPR_VECTOR_H

/**
 * @file
 *
 * Vectors are sequence containers that represent dynamic arrays.
 *
 * @include vector.c
 * @example vector.c
 */

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h> /* for bool */
#include <stddef.h>  /* for size_t */

/**
 * An opaque type representing a contiguous vector of elements.
 */
typedef struct cpr_vector cpr_vector_t;

/**
 * The size of the `cpr_vector_t` opaque type, i.e., `sizeof(cpr_vector_t)`.
 */
extern const size_t cpr_vector_sizeof;

/**
 * Returns a pointer to a new heap-allocated `cpr_vector_t` structure.
 *
 * @see cpr_vector_alloca()
 */
cpr_vector_t* cpr_vector_alloc(void);

/**
 * ...
 */
void cpr_vector_free(cpr_vector_t* vector);

/**
 * ...
 *
 * @pre \a vector is not `NULL`
 */
void cpr_vector_init(cpr_vector_t* vector);

/**
 * ...
 *
 * @pre \a vector is not `NULL`
 */
void cpr_vector_dispose(cpr_vector_t* vector);

/**
 * Tests whether a vector is empty, i.e., whether its size is 0.
 *
 * @pre \a vector is not `NULL`
 */
bool cpr_vector_empty(const cpr_vector_t* vector);

/**
 * Returns the number of elements in a vector.
 *
 * @pre \a vector is not `NULL`
 */
size_t cpr_vector_size(const cpr_vector_t* vector);

/**
 * Returns the number of elements that a vector has allocated space for.
 *
 * @pre \a vector is not `NULL`
 */
size_t cpr_vector_capacity(const cpr_vector_t* vector);

/**
 * Returns a direct pointer to a vector's internal memory array.
 *
 * @pre \a vector is not `NULL`
 */
void* cpr_vector_data(const cpr_vector_t* vector);

/**
 * Returns a pointer to the element at the given position in a vector.
 *
 * @pre \a vector is not `NULL`
 */
void* cpr_vector_at(const cpr_vector_t* vector,
  size_t position);

/**
 * Returns a pointer to the first element in a vector.
 *
 * @pre \a vector is not `NULL`
 */
void* cpr_vector_front(const cpr_vector_t* vector);

/**
 * Returns a pointer to the last element in a vector.
 *
 * @pre \a vector is not `NULL`
 */
void* cpr_vector_back(const cpr_vector_t* vector);

/**
 * Adjusts the minimum capacity of a vector, allocating storage if necessary.
 *
 * @pre \a vector is not `NULL`
 */
void cpr_vector_reserve(cpr_vector_t* vector,
  size_t capacity);

/**
 * Removes all elements from a vector, leaving its size zero.
 *
 * @pre \a vector is not `NULL`
 */
void cpr_vector_clear(cpr_vector_t* vector);

/**
 * Adds a new element at the end of a vector, after its current last element.
 *
 * @pre \a vector is not `NULL`
 */
void cpr_vector_push_back(cpr_vector_t* vector,
  const void* element);

/**
 * Removes the last element in a vector, reducing the vector's size by one.
 *
 * @pre \a vector is not `NULL`
 */
void cpr_vector_pop_back(cpr_vector_t* vector);

/*
 * Abbreviated type, variable, and function names if the `CPR_ABBREV`
 * preprocessor symbol is defined:
 */
#ifdef CPR_ABBREV
  /** Alias for `::cpr_vector_t` when `CPR_ABBREV` is defined. */
  #define vector_t         cpr_vector_t
  /** Alias for `#cpr_vector_sizeof` when `CPR_ABBREV` is defined. */
  #define vector_sizeof    cpr_vector_sizeof
  /** Alias for `cpr_vector_alloc()` when `CPR_ABBREV` is defined. */
  #define vector_alloc     cpr_vector_alloc
  /** Alias for `cpr_vector_free()` when `CPR_ABBREV` is defined. */
  #define vector_free      cpr_vector_free
  /** Alias for `cpr_vector_init()` when `CPR_ABBREV` is defined. */
  #define vector_init      cpr_vector_init
  /** Alias for `cpr_vector_dispose()` when `CPR_ABBREV` is defined. */
  #define vector_dispose   cpr_vector_dispose
  /** Alias for `cpr_vector_empty()` when `CPR_ABBREV` is defined. */
  #define vector_empty     cpr_vector_empty
  /** Alias for `cpr_vector_size()` when `CPR_ABBREV` is defined. */
  #define vector_size      cpr_vector_size
  /** Alias for `cpr_vector_capacity()` when `CPR_ABBREV` is defined. */
  #define vector_capacity  cpr_vector_capacity
  /** Alias for `cpr_vector_data()` when `CPR_ABBREV` is defined. */
  #define vector_data      cpr_vector_data
  /** Alias for `cpr_vector_at()` when `CPR_ABBREV` is defined. */
  #define vector_at        cpr_vector_at
  /** Alias for `cpr_vector_front()` when `CPR_ABBREV` is defined. */
  #define vector_front     cpr_vector_front
  /** Alias for `cpr_vector_back()` when `CPR_ABBREV` is defined. */
  #define vector_back      cpr_vector_back
  /** Alias for `cpr_vector_reserve()` when `CPR_ABBREV` is defined. */
  #define vector_reserve   cpr_vector_reserve
  /** Alias for `cpr_vector_clear()` when `CPR_ABBREV` is defined. */
  #define vector_clear     cpr_vector_clear
  /** Alias for `cpr_vector_push_back()` when `CPR_ABBREV` is defined. */
  #define vector_push_back cpr_vector_push_back
  /** Alias for `cpr_vector_pop_back()` when `CPR_ABBREV` is defined. */
  #define vector_pop_back  cpr_vector_pop_back
#endif /* CPR_ABBREV */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* CPR_VECTOR_H */
