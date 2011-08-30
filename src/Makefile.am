AM_CFLAGS       = -Wall -Wextra -Werror -pedantic -fPIC -DPIC -pipe
AM_CPPFLAGS     = -D_GNU_SOURCE -D_REENTRANT
AM_LDFLAGS      = -rdynamic
LDADD           = libcprime.la
lib_LTLIBRARIES = libcprime.la

libcprime_la_SOURCES = cprime.c \
  ascii.c \
  atomic.c \
  bool.c \
  char.c \
  closure.c \
  decimal.c \
  dir.c \
  file.c \
  hash.c \
  integer.c \
  iter.c \
  list.c \
  map.c \
  mutex.c \
  once.c \
  pair.c \
  posix.c \
  process.c \
  queue.c \
  rwlock.c \
  str.c \
  string.c \
  symbol.c \
  thread.c \
  uri.c \
  utf8.c \
  uuid.c \
  vector.c

include_HEADERS = cprime.h

pkginclude_HEADERS = \
  ascii.h \
  atomic.h \
  bool.h \
  byte.h \
  char.h \
  closure.h \
  decimal.h \
  dir.h \
  file.h \
  hash.h \
  integer.h \
  iter.h \
  list.h \
  map.h \
  memory.h \
  mutex.h \
  once.h \
  pair.h \
  posix.h \
  prelude.h \
  process.h \
  queue.h \
  rwlock.h \
  str.h \
  string.h \
  symbol.h \
  thread.h \
  uri.h \
  utf8.h \
  uuid.h \
  vector.h
