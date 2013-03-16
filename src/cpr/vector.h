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
 * @error ENOMEM if the allocation of storage failed
 * @return a pointer to the beginning of the allocated heap space
 * @see cpr_vector_alloca()
 */
cpr_vector_t* cpr_vector_alloc(void);

/**
 * ...
 *
 * @param vector a pointer to the vector to deallocate, or a `NULL` pointer
 */
void cpr_vector_free(cpr_vector_t* vector);

/**
 * ...
 *
 * @param vector a pointer to the vector to initialize
 * @pre `vector` is not a `NULL` pointer
 */
void cpr_vector_init(cpr_vector_t* vector);

/**
 * ...
 *
 * @param vector a pointer to the vector to dispose of
 * @pre `vector` is not a `NULL` pointer
 */
void cpr_vector_dispose(cpr_vector_t* vector);

/**
 * Tests whether a vector is empty, i.e., whether its size is zero.
 *
 * @param vector a pointer to the vector to be accessed
 * @pre `vector` is not a `NULL` pointer
 * @retval true if `*vector` contains no elements
 * @retval false otherwise
 */
bool cpr_vector_empty(const cpr_vector_t* vector);

/**
 * Returns the number of elements in a vector.
 *
 * @param vector a pointer to the vector to be accessed
 * @pre `vector` is not a `NULL` pointer
 * @return the element count of `*vector`
 */
size_t cpr_vector_size(const cpr_vector_t* vector);

/**
 * Returns the number of elements that a vector has allocated space for.
 *
 * @param vector a pointer to the vector to be accessed
 * @pre `vector` is not a `NULL` pointer
 * @return the element capacity of `*vector`
 */
size_t cpr_vector_capacity(const cpr_vector_t* vector);

/**
 * Returns a direct pointer to a vector's internal memory array.
 *
 * @param vector a pointer to the vector to be accessed
 * @pre `vector` is not a `NULL` pointer
 * @return a pointer to the internal memory array of `*vector`
 */
void* cpr_vector_data(const cpr_vector_t* vector);

/**
 * Returns a pointer to the element at the given position in a vector.
 *
 * @param vector a pointer to the vector to be accessed
 * @param position the position of an element in the vector
 * @pre `vector` is not a `NULL` pointer
 * @error EDOM if `position` is out of bounds
 * @return a pointer to the element at `position` in `*vector`
 */
void* cpr_vector_at(const cpr_vector_t* vector,
  size_t position);

/**
 * Returns a pointer to the first element in a vector.
 *
 * @param vector a pointer to the vector to be accessed
 * @pre `vector` is not a `NULL` pointer
 * @error EFAULT if `*vector` is empty
 * @return a pointer to the first element in `*vector`
 */
void* cpr_vector_front(const cpr_vector_t* vector);

/**
 * Returns a pointer to the last element in a vector.
 *
 * @param vector a pointer to the vector to be accessed
 * @pre `vector` is not a `NULL` pointer
 * @error EFAULT if `*vector` is empty
 * @return a pointer to the last element in `*vector`
 */
void* cpr_vector_back(const cpr_vector_t* vector);

/**
 * Adjusts the minimum capacity of a vector, allocating storage if necessary.
 *
 * @param vector a pointer to the vector to be mutated
 * @param capacity the minimum capacity of the vector
 * @pre `vector` is not a `NULL` pointer
 * @error EINVAL if `capacity` is greater than `max_size()`
 * @error ENOMEM if the reallocation of storage failed
 * @post the capacity of `*vector` is equal or greater than `capacity`
 */
void cpr_vector_reserve(cpr_vector_t* vector,
  size_t capacity);

/**
 * Removes all elements from a vector, leaving its size zero.
 *
 * @param vector a pointer to the vector to be mutated
 * @pre `vector` is not a `NULL` pointer
 * @post the size `*vector` is zero
 */
void cpr_vector_clear(cpr_vector_t* vector);

/**
 * Adds a new element at the end of a vector, after its current last element.
 *
 * @param vector a pointer to the vector to be mutated
 * @param element a pointer to the element to be added
 * @pre `vector` is not a `NULL` pointer
 * @pre `element` is not a `NULL` pointer
 * @error ENOMEM if the reallocation of storage failed
 * @post the size of `*vector` is increased by one
 */
void cpr_vector_push_back(cpr_vector_t* vector,
  const void* element);

/**
 * Removes the last element in a vector, reducing the vector's size by one.
 *
 * @param vector a pointer to the vector to be mutated
 * @pre `vector` is not a `NULL` pointer
 * @error EFAULT if `*vector` is empty
 * @post if `*vector` was not empty, its size is reduced by one
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
