/* This is free and unencumbered software released into the public domain. */

#ifndef CPRIME_VECTOR_H
#define CPRIME_VECTOR_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h> /* for size_t */

#define VECTOR_LENGTH_MAX       (SIZE_MAX-1)
#define VECTOR_LENGTH_MIN       0

typedef struct vector {
  size_t element_size;
  size_t element_count;
  size_t capacity;
  void* element_data;
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
int vector_init_with(vector_t* vector,
  size_t element_size,
  size_t capacity);

/**
 * Disposes of a vector.
 */
int vector_dispose(vector_t* vector);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* CPRIME_VECTOR_H */
