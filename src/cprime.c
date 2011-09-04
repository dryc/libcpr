/* This is free and unencumbered software released into the public domain. */

#include "build.h"

const char* const cprime_version_string = PACKAGE_VERSION;

const char* const cprime_feature_names[] = {
  "ascii",
#ifndef NDEBUG
  "debug",
#endif
#ifndef DISABLE_THREADS
  "threads",
#endif
#ifndef DISABLE_UNICODE
  "unicode",
#endif
  NULL
};

const unsigned int cprime_feature_count =
  (sizeof(cprime_feature_names) / sizeof(cprime_feature_names[0])) - 1;

const char* const cprime_module_names[] = {
  "ascii",
  "atomic",
  "bool",
  "box",
  "byte",
  "char",
  "closure",
  "decimal",
  "dir",
  "error",
  "file",
  "hash",
  "integer",
  "iter",
  "list",
  "map",
#ifndef DISABLE_THREADS
  "mutex",
  "once",
#endif
  "pair",
  "posix",
  "process",
  "queue",
#ifndef DISABLE_THREADS
  "rwlock",
#endif
  "seq",
  "set",
  "str",
  "string",
  "symbol",
#ifndef DISABLE_THREADS
  "thread",
#endif
  "uri",
#ifndef DISABLE_UNICODE
  "utf8",
#endif
  "uuid",
  "vector",
  NULL
};

const unsigned int cprime_module_count =
  (sizeof(cprime_module_names) / sizeof(cprime_module_names[0])) - 1;

bool
cprime_has_feature(const char* const restrict name) {
  validate_with_false_return(name != NULL);

  for (unsigned int i = 0; i < cprime_feature_count; i++) {
    if (unlikely(str_equal(cprime_feature_names[i], name))) {
      return TRUE;
    }
  }
  return FALSE;
}

bool
cprime_has_module(const char* const restrict name) {
  validate_with_false_return(name != NULL);

  for (unsigned int i = 0; i < cprime_module_count; i++) {
    if (unlikely(str_equal(cprime_module_names[i], name))) {
      return TRUE;
    }
  }
  return FALSE;
}
