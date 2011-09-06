/* This is free and unencumbered software released into the public domain. */

#include "build.h"

const class_t vector_class = {
  .name    = "vector",
  .super   = NULL,
  .vtable  = NULL, // TODO
};

vector_t*
vector_alloc() {
  vector_t* vector = malloc(sizeof(vector_t));
  vector_init_empty(vector);
  return vector;
}

void
vector_free(vector_t* vector) {
  if (likely(vector != NULL)) {
    vector_dispose(vector);
    free(vector);
  }
}

int
vector_init_empty(vector_t* vector) {
  validate_with_errno_return(vector != NULL);

  bzero(vector, sizeof(vector_t));

  return SUCCESS;
}

int
vector_init_with(vector_t* vector, const size_t element_size, const size_t capacity) {
  int result = vector_init_empty(vector);

  if (likely(succeeded(result) && element_size > 0 && capacity > 0)) {
    vector->data = calloc(capacity, element_size);
  }
  vector->element_size = element_size;
  vector->capacity     = capacity;
  vector->count        = 0;

  return result;
}

int
vector_dispose(vector_t* vector) {
  validate_with_errno_return(vector != NULL);

  if (likely(vector->data != NULL)) {
    free(vector->data);
    vector->data = NULL;
  }
  vector->element_size = 0;
  vector->capacity     = 0;
  vector->count        = 0;

  return SUCCESS;
}
