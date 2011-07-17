/* This is free and unencumbered software released into the public domain. */

#include "build.h"

const char* const cprime_version_string = PACKAGE_VERSION;

const char* const cprime_feature_names[] = {
  "base",
#ifndef NDEBUG
  "debug",
#endif
#ifndef DISABLE_THREADS
  "threads",
#endif
#ifndef DISABLE_UNICODE
  "unicode",
#endif
};

const unsigned int cprime_feature_count =
  sizeof(cprime_feature_names) / sizeof(cprime_feature_names[0]);

const char* const cprime_module_names[] = {
  "atomic",
  "bool",
  "byte",
  "char",
  "closure",
  "decimal",
  "dir",
  "file",
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
};

const unsigned int cprime_module_count =
  sizeof(cprime_module_names) / sizeof(cprime_module_names[0]);
