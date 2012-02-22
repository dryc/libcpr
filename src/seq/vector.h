/* This is free and unencumbered software released into the public domain. */

#ifndef CPRIME_VECTOR_H
#define CPRIME_VECTOR_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h> /* for size_t */

#define VECTOR_LENGTH_MAX (SIZE_MAX-1)
#define VECTOR_LENGTH_MIN 0

typedef struct vector_t {
  size_t element_size;
  size_t capacity;
  size_t count;
  byte_t* data;
} vector_t;

/**
 * Allocates heap memory for a new vector.
 */
extern vector_t* vector_alloc();

/**
 * Releases the heap memory used by a vector.
 */
extern void vector_free(vector_t* vector);

/**
 * Initializes a vector.
 */
extern int vector_init_empty(vector_t* vector);
extern int vector_init_with(vector_t* vector,
  const size_t element_size,
  const size_t capacity);

/**
 * Disposes of a vector.
 */
extern int vector_dispose(vector_t* vector);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* CPRIME_VECTOR_H */
