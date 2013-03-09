/* This is free and unencumbered software released into the public domain. */

#ifndef CPR_VECTOR_H
#define CPR_VECTOR_H

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
 * The size of the cpr_vector_t opaque type, i.e., sizeof(cpr_vector_t).
 */
extern const size_t cpr_vector_sizeof;

/**
 * ...
 */
cpr_vector_t* cpr_vector_alloc(void);

/**
 * ...
 */
void cpr_vector_free(cpr_vector_t* vector);

/**
 * ...
 */
void cpr_vector_init(cpr_vector_t* vector);

/**
 * ...
 */
void cpr_vector_dispose(cpr_vector_t* vector);

/**
 * Tests whether a vector is empty, i.e., whether its size is 0.
 */
bool cpr_vector_empty(const cpr_vector_t* vector);

/**
 * Returns the number of elements in a vector.
 */
size_t cpr_vector_size(const cpr_vector_t* vector);

/**
 * Returns the number of elements that a vector has allocated space for.
 */
size_t cpr_vector_capacity(const cpr_vector_t* vector);

/**
 * Returns a direct pointer to a vector's internal memory array.
 */
void* cpr_vector_data(const cpr_vector_t* vector);

/**
 * Returns a pointer to the element at the given position in a vector.
 */
void* cpr_vector_at(const cpr_vector_t* vector,
  size_t position);

/**
 * Returns a pointer to the first element in a vector.
 */
void* cpr_vector_front(const cpr_vector_t* vector);

/**
 * Returns a pointer to the last element in a vector.
 */
void* cpr_vector_back(const cpr_vector_t* vector);

/**
 * Adjusts the minimum capacity of a vector, allocating storage if necessary.
 */
void cpr_vector_reserve(cpr_vector_t* vector,
  size_t capacity);

/**
 * Removes all elements from a vector, leaving its size zero.
 */
void cpr_vector_clear(cpr_vector_t* vector);

/**
 * Adds a new element at the end of a vector, after its current last element.
 */
void cpr_vector_push_back(cpr_vector_t* vector,
  const void* element);

/**
 * Removes the last element in a vector, reducing the vector's size by one.
 */
void cpr_vector_pop_back(cpr_vector_t* vector);

/**
 * Abbreviated type and function names if CPR_ABBREV is defined.
 */
#ifdef CPR_ABBREV
  #define vector_t         cpr_vector_t
  #define vector_sizeof    cpr_vector_sizeof
  #define vector_alloc     cpr_vector_alloc
  #define vector_free      cpr_vector_free
  #define vector_init      cpr_vector_init
  #define vector_dispose   cpr_vector_dispose
  #define vector_empty     cpr_vector_empty
  #define vector_size      cpr_vector_size
  #define vector_capacity  cpr_vector_capacity
  #define vector_data      cpr_vector_data
  #define vector_at        cpr_vector_at
  #define vector_front     cpr_vector_front
  #define vector_back      cpr_vector_back
  #define vector_reserve   cpr_vector_reserve
  #define vector_clear     cpr_vector_clear
  #define vector_push_back cpr_vector_push_back
  #define vector_pop_back  cpr_vector_pop_back
#endif /* CPR_ABBREV */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* CPR_VECTOR_H */
