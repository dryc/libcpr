/* This is free and unencumbered software released into the public domain. */

#include "build.h"

const char* const cprime_version_string = PACKAGE_VERSION;

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
