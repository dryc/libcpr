lib_LTLIBRARIES = libcpr.la

libcpr_la_SOURCES =       \
  error.cc                \
  feature.cc              \
  module.cc               \
  version.cc

base_pkgincludedir = $(includedir)/cpr

base_pkginclude_HEADERS = \
  error.h                 \
  feature.h               \
  generic.h               \
  module.h                \
  types.h                 \
  unsafe.h                \
  version.h

if !DISABLE_LIST
  libcpr_la_SOURCES       += list.cc
  base_pkginclude_HEADERS += list.h
endif

if !DISABLE_MAP
  libcpr_la_SOURCES       += map.cc
  base_pkginclude_HEADERS += map.h
endif

if !DISABLE_SET
  libcpr_la_SOURCES       += set.cc
  base_pkginclude_HEADERS += set.h
endif

if !DISABLE_STRING
  libcpr_la_SOURCES       += string.cc
  base_pkginclude_HEADERS += string.h
endif

if !DISABLE_VECTOR
  libcpr_la_SOURCES       += vector.cc
  base_pkginclude_HEADERS += vector.h
endif
