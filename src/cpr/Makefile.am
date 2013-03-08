AM_CPPFLAGS = -I$(top_srcdir)/src -iquote $(srcdir)
AM_CXXFLAGS = -Wall -Wextra -pipe
LDADD       = $(top_srcdir)/src/cpr/libcpr.la

lib_LTLIBRARIES = libcpr.la

libcpr_la_SOURCES =       \
  feature.cc              \
  module.cc               \
  version.cc

base_pkgincludedir = $(includedir)/cpr

base_pkginclude_HEADERS = \
  feature.h               \
  module.h                \
  prelude.h               \
  unsafe.h                \
  version.h
