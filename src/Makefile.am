AM_CFLAGS       = -Wall -Wextra -Werror -pedantic -fPIC -DPIC -pipe
AM_CPPFLAGS     = -D_GNU_SOURCE -D_REENTRANT
AM_LDFLAGS      = -rdynamic
LDADD           = libcprime.la
lib_LTLIBRARIES = libcprime.la

libcprime_la_SOURCES =      \
  cprime.c                  \
  ascii.c                   \
  base64.c                  \
  box.c                     \
  char.c                    \
  dir.c                     \
  file.c                    \
  hash.c                    \
  iter.c                    \
  lock/mutex.c              \
  lock/rwlock.c             \
  lock/spinlock.c           \
  map.c                     \
  once.c                    \
  pair.c                    \
  posix.c                   \
  process.c                 \
  queue.c                   \
  seq.c                     \
  seq/list.c                \
  seq/vector.c              \
  set.c                     \
  str.c                     \
  string.c                  \
  thread.c                  \
  uri.c                     \
  utf8.c                    \
  uuid.c

include_HEADERS = cprime.h

nobase_pkginclude_HEADERS = \
  ascii.h                   \
  atom.h                    \
  base64.h                  \
  bool.h                    \
  box.h                     \
  byte.h                    \
  char.h                    \
  dir.h                     \
  file.h                    \
  hash.h                    \
  iter.h                    \
  lock/mutex.h              \
  lock/rwlock.h             \
  lock/spinlock.h           \
  map.h                     \
  memory.h                  \
  once.h                    \
  pair.h                    \
  posix.h                   \
  prelude.h                 \
  process.h                 \
  queue.h                   \
  seq.h                     \
  seq/list.h                \
  seq/vector.h              \
  set.h                     \
  str.h                     \
  string.h                  \
  thread.h                  \
  unsafe.h                  \
  uri.h                     \
  utf8.h                    \
  uuid.h
