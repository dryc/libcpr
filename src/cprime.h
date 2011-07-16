/* This is free and unencumbered software released into the public domain. */

#ifndef _CPRIME_H
#define _CPRIME_H

#ifdef __cplusplus
extern "C" {
#endif

#include <cprime/prelude.h>

#include <cprime/bool.h>
#include <cprime/byte.h>
#include <cprime/char.h>
#include <cprime/pair.h>
#include <cprime/list.h>

#include <cprime/atomic.h>
#include <cprime/closure.h>
#include <cprime/decimal.h>
#include <cprime/dir.h>
#include <cprime/file.h>
#include <cprime/integer.h>
#include <cprime/map.h>
#include <cprime/mutex.h>
#include <cprime/posix.h>
#include <cprime/process.h>
#include <cprime/queue.h>
#include <cprime/string.h>
#include <cprime/symbol.h>
#include <cprime/thread.h>
#include <cprime/uri.h>
#include <cprime/uuid.h>
#include <cprime/vector.h>

extern const char* const cprime_version_string;

#define __cprime 1

#ifdef __cplusplus
}
#endif

#endif /* _CPRIME_H */
