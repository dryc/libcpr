/* This is free and unencumbered software released into the public domain. */

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include "cpr/vector.h"

#include <cstdlib> /* for std::calloc(), std::free() */
#include <vector>  /* for std::vector */

struct cpr_vector : public std::vector<void*> {
  // TODO
};

extern const size_t cpr_vector_sizeof = sizeof(cpr_vector);

cpr_vector*
cpr_vector_alloc(void) {
  return reinterpret_cast<cpr_vector*>(std::calloc(1, sizeof(cpr_vector)));
}

void
cpr_vector_free(cpr_vector* const vector) {
  std::free(vector);
}

void
cpr_vector_init(cpr_vector* const vector) {
  new(vector) cpr_vector();
}

void
cpr_vector_dispose(cpr_vector* const vector) {
  vector->~cpr_vector(); /* guaranteed to never throw an exception */
}

bool
cpr_vector_empty(const cpr_vector* const vector) {
  return vector->empty(); /* guaranteed to never throw an exception */
}

size_t
cpr_vector_size(const cpr_vector* const vector) {
  return vector->size(); /* guaranteed to never throw an exception */
}

void
cpr_vector_clear(cpr_vector* const vector) {
  vector->clear(); /* guaranteed to never throw an exception */
}
