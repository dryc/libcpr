/* This is free and unencumbered software released into the public domain. */

#ifndef CPRIME_BUILD_H
#define CPRIME_BUILD_H

#ifdef __cplusplus
extern "C" {
#endif

/* private headers for the build process only */
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

/* public prelude included from <cprime.h> */
#include "prelude.h"

/* public headers included from <cprime.h> (specific order) */
#include "hash.h"
#include "bool.h"
#include "byte.h"
#include "char.h"
#include "pair.h"
#include "iter.h"
#include "seq.h"
#include "seq/list.h"

/* public headers included from <cprime.h> (alphabetic order) */
#include "atom.h"
#include "box.h"
#include "dir.h"
#include "file.h"
#include "map.h"
#include "posix.h"
#include "process.h"
#include "queue.h"
#include "set.h"
#include "sort.h"
#include "str.h"
#include "string.h"
#include "uri.h"
#include "uuid.h"
#include "seq/vector.h"

/* public headers included from <cprime.h> (thread support) */
#ifndef DISABLE_THREADS
#include "lock/mutex.h"
#include "lock/rwlock.h"
#include "lock/spinlock.h"
#include "once.h"
#include "thread.h"
#endif

/* optional headers not included by <cprime.h> */
#include "ascii.h"
#include "base64.h"
#include "memory.h"
#ifndef DISABLE_UNICODE
#include "utf8.h"
#endif

/* standard library headers */
#include <assert.h> /* for assert() */

/* linking visibility specifiers */
#ifdef __GNUC__
#  define public  __attribute__((visibility("default")))
#  define private __attribute__((visibility("hidden")))
#else
#  define public
#  define private
#endif

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* CPRIME_BUILD_H */
