/* This is free and unencumbered software released into the public domain. */

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include "module.h"

#include <cassert> /* for assert() */
#include <cstring> /* for std::strcmp() */

////////////////////////////////////////////////////////////////////////////////
/* Constants */

static const char* const cpr_module_names[] = {
/*
#ifndef DISABLE_LIST
  "list",
#endif
#ifndef DISABLE_MAP
  "map",
#endif
#ifndef DISABLE_SET
  "set",
#endif
*/
#ifndef DISABLE_STRING
  "string",
#endif
#ifndef DISABLE_VECTOR
  "vector",
#endif
};

////////////////////////////////////////////////////////////////////////////////
/* Functions */

bool
cpr_module_exists(const char* const module_name) {
  assert(module_name != nullptr);

  if (module_name != nullptr) {
    for (const char* cpr_module_name : cpr_module_names) {
      if (std::strcmp(cpr_module_name, module_name) == 0) {
        return true; /* found */
      }
    }
  }

  return false; /* not found */
}
