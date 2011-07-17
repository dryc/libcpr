/* This is free and unencumbered software released into the public domain. */

#ifndef _CPRIME_BUILD_H
#define _CPRIME_BUILD_H

#ifdef __cplusplus
extern "C" {
#endif

/* private headers for the build process only */
#include "config.h"

/* public prelude included from <cprime.h> */
#include "prelude.h"

/* public headers included from <cprime.h> (specific order) */
#include "bool.h"
#include "byte.h"
#include "char.h"
#include "pair.h"
#include "list.h"

/* public headers included from <cprime.h> (alphabetic order) */
#include "atomic.h"
#include "closure.h"
#include "decimal.h"
#include "dir.h"
#include "file.h"
#include "integer.h"
#include "map.h"
#include "posix.h"
#include "process.h"
#include "queue.h"
#include "string.h"
#include "symbol.h"
#include "uri.h"
#include "uuid.h"
#include "vector.h"

/* public headers included from <cprime.h> (thread support) */
#ifndef DISABLE_THREADS
#include "mutex.h"
#include "once.h"
#include "rwlock.h"
#include "thread.h"
#endif

/* optional headers not included by <cprime.h> */
#include "memory.h"
#ifndef DISABLE_UNICODE
#include "utf8.h"
#endif

/* standard library headers */
#include <stdlib.h> /* for calloc(), free(), malloc() */

#ifdef __cplusplus
}
#endif

#endif /* _CPRIME_BUILD_H */
