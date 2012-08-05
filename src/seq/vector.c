/* This is free and unencumbered software released into the public domain. */

#include "build.h"

public const class_t vector_class = {
  .name    = "vector",
  .super   = NULL,
  .vtable  = NULL, // TODO
};

public vector_t*
vector_alloc() {
  vector_t* const restrict vector = malloc(sizeof(vector_t));
  if (is_nonnull(vector)) {
    vector_init_empty(vector);
  }
  return vector;
}

public void
vector_free(vector_t* const restrict vector) {
  if (is_nonnull(vector)) {
    vector_dispose(vector);
    free(vector);
  }
}

public int
vector_init_empty(vector_t* const restrict vector) {
  validate_with_errno_return(is_nonnull(vector));

  bzero(vector, sizeof(*vector));

  return SUCCESS;
}

public int
vector_init_with(vector_t* const restrict vector,
                 const size_t element_size,
                 const size_t capacity) {
  validate_with_errno_return(is_nonnull(vector));
  validate_with_errno_return(is_nonzero(element_size));

  vector->element_size  = element_size;
  vector->element_count = 0;
  vector->capacity      = capacity;

  if (is_nonzero(capacity)) {
    vector->element_data = calloc(capacity, element_size);
    if (is_null(vector->element_data)) {
      return FAILURE(ENOMEM); /* out of memory */
    }
  }

  return SUCCESS;
}

public int
vector_dispose(vector_t* const restrict vector) {
  validate_with_errno_return(is_nonnull(vector));

  vector->element_size  = 0;
  vector->element_count = 0;
  vector->capacity      = 0;

  if (is_nonnull(vector->element_data)) {
    free(vector->element_data);
    vector->element_data = NULL;
  }

  return SUCCESS;
}
