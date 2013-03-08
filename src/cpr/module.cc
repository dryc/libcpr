/* This is free and unencumbered software released into the public domain. */

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include "cpr/module.h"

#include <cstring> /* for std::strcmp() */

static const char* const cpr_module_names[] = {
  nullptr
};

static const unsigned int cpr_module_count =
  (sizeof(cpr_module_names) / sizeof(cpr_module_names[0])) - 1;

bool
cpr_module_exists(const char* const module_name) {
  for (unsigned int index = 0; index < cpr_module_count; index++) {
    if (std::strcmp(module_name, cpr_module_names[index]) == 0) {
      return true; /* found */
    }
  }
  return false; /* not found */
}
