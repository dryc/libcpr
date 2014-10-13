/* This is free and unencumbered software released into the public domain. */

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include "feature.h"

#include <cassert> /* for assert() */
#include <cstring> /* for std::strcmp() */

////////////////////////////////////////////////////////////////////////////////
/* Constants */

static const char* const cpr_feature_names[] = {
  "ascii",
#ifndef NDEBUG
  "debug",
#endif
};

////////////////////////////////////////////////////////////////////////////////
/* Functions */

bool
cpr_feature_exists(const char* const feature_name) {
  assert(feature_name != nullptr);

  if (feature_name != nullptr) {
    for (const char* cpr_feature_name : cpr_feature_names) {
      if (std::strcmp(cpr_feature_name, feature_name) == 0) {
        return true; /* found */
      }
    }
  }

  return false; /* not found */
}
