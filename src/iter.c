/* This is free and unencumbered software released into the public domain. */

#include "build.h"

iter_t*
iter_alloc() {
  iter_t* iter = malloc(sizeof(iter_t));
  iter_init(iter);
  return iter;
}

void
iter_free(iter_t* iter) {
  if (likely(iter != NULL)) {
    iter_dispose(iter);
    free(iter);
  }
}

int
iter_init(iter_t* iter) {
  validate_with_errno_return(iter != NULL);

  bzero(iter, sizeof(iter_t));

  return 0;
}

int
iter_init_with(iter_t* iter, const iter_interface_t* restrict methods, const void* restrict user_data) {
  validate_with_errno_return(methods != NULL);

  int result = iter_init(iter);

  if (succeeded(result)) {
    iter->methods   = (iter_interface_t*)methods;
    iter->user_data = (void*)user_data;

    if (likely(methods->init != NULL)) {
      result = methods->init(iter);
    }
  }

  return result;
}

int
iter_dispose(iter_t* iter) {
  validate_with_errno_return(iter != NULL && iter->methods != NULL);

  const iter_interface_t* const methods = iter->methods;

  const int result = likely(methods->dispose != NULL) ?
    methods->dispose(iter) : 0;

#ifndef NDEBUG
  bzero(iter, sizeof(iter_t));
#endif

  return result;
}

bool
iter_next(void* iter_) {
  iter_t* iter = iter_;
  validate_with_false_return(iter != NULL && iter->methods != NULL);

  const iter_interface_t* const methods = iter->methods;

  const int result = likely(methods->next != NULL) ?
    methods->next(iter) : FALSE;

  if (likely(result == TRUE)) {
    iter->position++;
  }

  return result;
}
