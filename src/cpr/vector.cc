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

extern const size_t cpr_vector_sizeof = sizeof(cpr_vector_t);

cpr_vector_t*
cpr_vector_alloc(void) {
  return reinterpret_cast<cpr_vector_t*>(std::calloc(1, sizeof(cpr_vector_t)));
}

void
cpr_vector_free(cpr_vector_t* const vector) {
  std::free(vector);
}
