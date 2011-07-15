AM_CFLAGS       = -std=gnu99 -pedantic -fPIC -DPIC -pipe
AM_CPPFLAGS     = -D_GNU_SOURCE -D_REENTRANT -DMT
AM_LDFLAGS      = -rdynamic
LDADD           = libcprime.la
lib_LTLIBRARIES = libcprime.la

libcprime_la_LIBADD  = -lrt
libcprime_la_SOURCES = cprime.c \
  atomic.c \
  bool.c \
  char.c \
  closure.c \
  decimal.c \
  dir.c \
  file.c \
  integer.c \
  list.c \
  map.c \
  mutex.c \
  pair.c \
  posix.c \
  queue.c \
  string.c \
  symbol.c \
  thread.c \
  uri.c \
  uuid.c \
  vector.c

include_HEADERS = cprime.h

pkginclude_HEADERS = \
  atomic.h \
  bool.h \
  byte.h \
  char.h \
  closure.h \
  decimal.h \
  dir.h \
  file.h \
  integer.h \
  list.h \
  map.h \
  memory.h \
  mutex.h \
  pair.h \
  posix.h \
  prelude.h \
  queue.h \
  string.h \
  symbol.h \
  thread.h \
  uri.h \
  uuid.h \
  vector.h
