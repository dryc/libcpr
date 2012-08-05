/* This is free and unencumbered software released into the public domain. */

#ifndef CPRIME_VECTOR_H
#define CPRIME_VECTOR_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h> /* for size_t */

#define VECTOR_LENGTH_MIN       0
#define VECTOR_LENGTH_MAX       (LONG_MAX-1)
#define VECTOR_LENGTH_INIT      8

typedef struct vector {
  //class_t* element_class;
  //free_func_t free_func;
  size_t element_size;
  size_t element_count;
  size_t capacity;
  const void** element_data;
} vector_t;

/**
 * Allocates heap memory for a new vector.
 */
vector_t* vector_alloc();

/**
 * Releases the heap memory used by a vector.
 */
void vector_free(vector_t* vector);

/**
 * Initializes a vector.
 */
int vector_init_empty(vector_t* vector);
int vector_init(vector_t* vector,
  size_t capacity);
int vector_init_with(vector_t* vector,
  size_t capacity,
  size_t element_size);

/**
 * Disposes of a vector.
 */
int vector_dispose(vector_t* vector);

/**
 * Removes all elements from a vector.
 */
int vector_clear(vector_t* vector);

/**
 * Checks whether a vector contains any elements.
 */
bool vector_is_empty(const vector_t* vector);

/**
 * Returns the number of elements in a vector.
 */
size_t vector_length(const vector_t* vector);

/**
 * Counts occurrences of a given element in a vector.
 */
size_t vector_count(const vector_t* vector,
  const void* element);

/**
 * Checks whether a vector contains a given element.
 */
bool vector_lookup(const vector_t* vector,
  const void* element);

/**
 * Appends a given element to a vector.
 */
long vector_append(vector_t* vector,
  const void* element);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* CPRIME_VECTOR_H */
