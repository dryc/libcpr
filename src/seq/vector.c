/* This is free and unencumbered software released into the public domain. */

#include "build.h"

public const class_t vector_class = {
  .name    = "vector",
  .super   = NULL,
  .vtable  = NULL, // TODO
};

public vector_t*
vector_alloc() {
  return calloc(1, sizeof(vector_t));
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
vector_init(vector_t* const restrict vector,
            const size_t capacity) {
  validate_with_errno_return(is_nonnull(vector));

  vector->element_size  = sizeof(void*);
  vector->element_count = 0;
  vector->capacity      = capacity;
  vector->element_data  = NULL;

  if (is_nonzero(capacity)) {
    vector->element_data = calloc(vector->capacity, vector->element_size);
    if (is_null(vector->element_data)) {
      return FAILURE(ENOMEM); /* out of memory */
    }
  }

  return SUCCESS;
}

public int
vector_init_with(vector_t* const restrict vector,
                 const size_t capacity,
                 const size_t element_size) {
  validate_with_errno_return(is_nonnull(vector));
  validate_with_errno_return(is_nonzero(element_size));

  vector->element_size  = element_size;
  vector->element_count = 0;
  vector->capacity      = capacity;
  vector->element_data  = NULL;

  if (is_nonzero(capacity)) {
    vector->element_data = calloc(vector->capacity, vector->element_size);
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

public int
vector_clear(vector_t* const restrict vector) {
  validate_with_errno_return(is_nonnull(vector));

  vector->element_count = 0;

  return SUCCESS;
}

public bool
vector_is_empty(const vector_t* const restrict vector) {
  validate_with_true_return(is_nonnull(vector));

  return is_zero(vector->element_count);
}

public size_t
vector_length(const vector_t* const restrict vector) {
  validate_with_zero_return(is_nonnull(vector));

  return vector->element_count;
}

public size_t
vector_count(const vector_t* const restrict vector,
             const void* const restrict element) {
  validate_with_zero_return(is_nonnull(vector));

  size_t count = 0;

  for (size_t index = 0; index < vector->element_count; index++) {
    if (vector->element_data[index] == element) { // TODO: use vector->compare_func
      count++;
    }
  }

  return count;
}

public bool
vector_lookup(const vector_t* const restrict vector,
              const void* const restrict element) {
  validate_with_false_return(is_nonnull(vector));

  for (size_t index = 0; index < vector->element_count; index++) {
    if (vector->element_data[index] == element) { // TODO: use vector->compare_func
      return TRUE;
    }
  }

  return FALSE;
}

public long
vector_append(vector_t* const restrict vector,
              const void* const restrict element) {
  validate_with_errno_return(is_nonnull(vector));

#if 0
  if (vector->element_count == VECTOR_LENGTH_MAX) {
    return FAILURE(ENOMEM); /* out of memory */
  }
#endif

  if (vector->element_count == vector->capacity) {
    const size_t new_capacity = is_zero(vector->capacity) ? VECTOR_LENGTH_INIT : vector->capacity * 2;
    const void** new_element_data = realloc(vector->element_data, new_capacity * vector->element_size);
    if (is_null(new_element_data)) {
      return FAILURE(ENOMEM); /* out of memory */
    }
    vector->element_data = new_element_data;
    vector->capacity     = new_capacity;
  }

  const size_t index = vector->element_count++;
  vector->element_data[index] = element;

  return index;
}

public int
vector_sort(vector_t* const restrict vector,
            const unsigned int flags) {
  validate_with_errno_return(is_nonnull(vector));
  (void)flags; /* unused for now */

  uint64_sort((uint64_t*)vector->element_data, vector->element_count); // TODO: use vector->compare_func

  return SUCCESS;
}
