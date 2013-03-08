AM_CPPFLAGS = -I$(top_srcdir)/src -iquote $(srcdir)
AM_CXXFLAGS = -Wall -Wextra -pipe
LDADD       = $(top_srcdir)/src/cpr/libcpr.la

lib_LTLIBRARIES = libcpr.la

libcpr_la_SOURCES =       \
  feature.cc              \
  list.cc                 \
  map.cc                  \
  module.cc               \
  set.cc                  \
  string.cc               \
  vector.cc               \
  version.cc

base_pkgincludedir = $(includedir)/cpr

base_pkginclude_HEADERS = \
  feature.h               \
  list.h                  \
  map.h                   \
  module.h                \
  prelude.h               \
  set.h                   \
  string.h                \
  unsafe.h                \
  vector.h                \
  version.h
