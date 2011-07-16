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
#include "mutex.h"
#include "posix.h"
#include "process.h"
#include "queue.h"
#include "string.h"
#include "symbol.h"
#include "thread.h"
#include "uri.h"
#include "uuid.h"
#include "vector.h"

/* optional headers not included by <cprime.h> */
#include "memory.h"
#include "utf8.h"

/* standardy library headers */
#include <stdlib.h> /* for calloc(), free(), malloc() */

#ifdef __cplusplus
}
#endif

#endif /* _CPRIME_BUILD_H */
