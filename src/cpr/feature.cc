/* This is free and unencumbered software released into the public domain. */

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include "cpr/feature.h"

#include <cstring> /* for std::strcmp() */

static const char* const cpr_feature_names[] = {
  "ascii",
#ifndef NDEBUG
  "debug",
#endif
  nullptr
};

static const unsigned int cpr_feature_count =
  (sizeof(cpr_feature_names) / sizeof(cpr_feature_names[0])) - 1;

bool
cpr_feature_exists(const char* const feature_name) {
  for (unsigned int index = 0; index < cpr_feature_count; index++) {
    if (std::strcmp(feature_name, cpr_feature_names[index]) == 0) {
      return true; /* found */
    }
  }
  return false; /* not found */
}
