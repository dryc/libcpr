dnl configure.ac                                        -*- Autoconf -*-
dnl
dnl Process this file with `autoconf` to produce a configure script.
dnl
dnl This is free and unencumbered software released into the public domain.
AC_PREREQ([2.60])

dnl Define version information:
m4_define([VERSION_MAJOR],
  m4_esyscmd([cut -d'.' -f1 VERSION | tr -d '\n']))
m4_define([VERSION_MINOR],
  m4_esyscmd([cut -d'.' -f2 VERSION | tr -d '\n']))
m4_define([VERSION_PATCH],
  m4_esyscmd([cut -d'.' -f3 VERSION | tr -d '\n']))
m4_define([VERSION_STRING],
  m4_esyscmd([git describe --dirty --always | tr -d '\n']))

dnl Define package information:
AC_INIT([libcpr], [VERSION_STRING],
  [arto@bendiken.net], [libcpr],
  [http://libcpr.org/])

dnl Configure Autoconf:
AC_CONFIG_HEADERS([src/config.h])
AC_CONFIG_SRCDIR([src/cpr.h])
AC_CONFIG_AUX_DIR([etc/aclocal])
AC_CONFIG_MACRO_DIR([etc/aclocal])
AC_USE_SYSTEM_EXTENSIONS

dnl Configure Automake:
AM_INIT_AUTOMAKE([foreign -Wall -Werror dist-bzip2 subdir-objects nostdinc])
AM_SILENT_RULES([yes])

dnl Check for programs:
AC_PROG_CC
AC_PROG_CC_C99
AM_PROG_CC_C_O
AC_PROG_CXX
m4_ifdef([AM_PROG_AR], [AM_PROG_AR])
LT_INIT
AC_LANG([C++])

dnl Check for configuration options:
# --enable-debug/--disable-debug
AC_ARG_ENABLE([debug],
  [AS_HELP_STRING([--enable-debug], [build with debugging support [default=no]])],
  [], [enable_debug=no])
AS_IF([test "x$enable_debug" != "xno"],
  [AC_DEFINE([DEBUG], [1], [Enable debugging support.])],
  [AC_DEFINE([NDEBUG], [1], [Disable assertions.])])
AM_CONDITIONAL([ENABLE_DEBUG], [test "x$enable_debug" != "xno"])
# --enable-list/--disable-list
AC_ARG_ENABLE([list],
  [AS_HELP_STRING([--disable-list], [do not include the list module])])
AS_IF([test "x$enable_list" == "xno"], [
  AC_DEFINE([DISABLE_LIST], 1, [Define to omit the <cpr/list.h> module.])
])
AM_CONDITIONAL([DISABLE_LIST], [test "x$enable_list" == "xno"])
# --enable-map/--disable-map
AC_ARG_ENABLE([map],
  [AS_HELP_STRING([--disable-map], [do not include the map module])])
AS_IF([test "x$enable_map" == "xno"], [
  AC_DEFINE([DISABLE_MAP], 1, [Define to omit the <cpr/map.h> module.])
])
AM_CONDITIONAL([DISABLE_MAP], [test "x$enable_map" == "xno"])
# --enable-set/--disable-set
AC_ARG_ENABLE([set],
  [AS_HELP_STRING([--disable-set], [do not include the set module])])
AS_IF([test "x$enable_set" == "xno"], [
  AC_DEFINE([DISABLE_SET], 1, [Define to omit the <cpr/set.h> module.])
])
AM_CONDITIONAL([DISABLE_SET], [test "x$enable_set" == "xno"])
# --enable-string/--disable-string
AC_ARG_ENABLE([string],
  [AS_HELP_STRING([--disable-string], [do not include the string module])])
AS_IF([test "x$enable_string" == "xno"], [
  AC_DEFINE([DISABLE_STRING], 1, [Define to omit the <cpr/string.h> module.])
])
AM_CONDITIONAL([DISABLE_STRING], [test "x$enable_string" == "xno"])
# --enable-vector/--disable-vector
AC_ARG_ENABLE([vector],
  [AS_HELP_STRING([--disable-vector], [do not include the vector module])])
AS_IF([test "x$enable_vector" == "xno"], [
  AC_DEFINE([DISABLE_VECTOR], 1, [Define to omit the <cpr/vector.h> module.])
])
AM_CONDITIONAL([DISABLE_VECTOR], [test "x$enable_vector" == "xno"])

dnl Check for libraries:

dnl Check for header files:

dnl Check for types:

dnl Check for structures:

dnl Check for compiler characteristics:
AC_CANONICAL_HOST
AC_C_BIGENDIAN
AC_C_INLINE
AC_C_RESTRICT
AX_CXX_COMPILE_STDCXX_11([noext])

dnl Check for library functions:
AC_FUNC_ALLOCA

dnl Check for system services:

dnl Generate output:
AC_CONFIG_FILES([Makefile src/Makefile src/cpr/Makefile test/Makefile])
AC_SUBST([PACKAGE_VERSION_MAJOR], ["VERSION_MAJOR"])
AC_SUBST([PACKAGE_VERSION_MINOR], ["VERSION_MINOR"])
AC_SUBST([PACKAGE_VERSION_PATCH], ["VERSION_PATCH"])
AC_CONFIG_FILES([src/cpr/version.h])
AH_BOTTOM([#include "cpr/prelude.h"])
AC_OUTPUT
