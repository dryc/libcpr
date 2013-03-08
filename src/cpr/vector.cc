/* This is free and unencumbered software released into the public domain. */

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include "cpr/vector.h"

#include <vector> /* for std::vector */

struct cpr_vector : public std::vector<void*> {
  // TODO
};

extern const size_t cpr_vector_sizeof = sizeof(cpr_vector);
