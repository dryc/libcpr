dnl configure.ac                                        -*- Autoconf -*-
dnl
dnl Process this file with autoconf to produce a configure script.
dnl
dnl This is free and unencumbered software released into the public domain.
AC_PREREQ([2.60])

m4_define([VERSION_MAJOR], 0)
m4_define([VERSION_MINOR], 0)
m4_define([VERSION_PATCH], 0)
m4_define([VERSION_STRING], [VERSION_MAJOR.VERSION_MINOR.VERSION_PATCH])

AC_INIT([C′], [VERSION_STRING],
  [libcprime@googlegroups.com], [cprime],
  [https://github.com/bendiken/libcprime])

AC_CONFIG_HEADERS([config.h])
AC_CONFIG_SRCDIR([src/cprime.h.in])
AC_CONFIG_AUX_DIR([etc/aclocal])
AC_CONFIG_MACRO_DIR([etc/aclocal])

AM_INIT_AUTOMAKE([foreign -Wall -Werror dist-bzip2])
AM_SILENT_RULES([yes])

dnl Checks for programs:
LT_INIT
AC_PROG_CC
AC_PROG_CC_C99

dnl Checks for configuration options:
AC_ARG_ENABLE([threads],
  [AS_HELP_STRING([--disable-threads], [omit support for threads])])
AS_IF([test "x$enable_threads" == "xno"], [
  AC_DEFINE([DISABLE_THREADS], 1, [Define to disable POSIX threads support.])
])
AC_ARG_ENABLE([unicode],
  [AS_HELP_STRING([--disable-unicode], [omit support for Unicode strings])])
AS_IF([test "x$enable_unicode" == "xno"], [
  AC_DEFINE([DISABLE_UNICODE], 1, [Define to disable Unicode string support.])
])

dnl Checks for libraries:
AS_IF([test "x$enable_threads" != "xno"], [
# POSIX threads support:
  AC_CHECK_HEADERS([pthread.h],
    AC_SEARCH_LIBS([pthread_create], [pthread], [],
      AC_MSG_ERROR([*** POSIX thread support library libpthread not found ***])),
    AC_MSG_ERROR([*** POSIX thread support header file pthread.h not found ***]))
])

dnl Checks for header files:
# C89 header files:
AC_CHECK_HEADERS_ONCE([assert.h ctype.h limits.h setjmp.h stdarg.h])
# C99 header files:
AC_CHECK_HEADERS_ONCE([complex.h ctype.h inttypes.h stdbool.h stdint.h tgmath.h])
AC_HEADER_STDBOOL
# C1X header files:
AC_CHECK_HEADERS_ONCE([stdatomic.h threads.h uchar.h])
# POSIX header files:
AC_CHECK_HEADERS_ONCE([dirent.h errno.h iconv.h libgen.h mqueue.h poll.h
                       pthread.h sched.h syslog.h])
# GNU header files:
AC_CHECK_HEADERS_ONCE([execinfo.h])

dnl Checks for types:

dnl Checks for structures:

dnl Checks for compiler characteristics:
AC_CANONICAL_HOST
AC_C_BIGENDIAN
AC_C_INLINE
AC_C_RESTRICT

dnl Checks for library functions:
AC_FUNC_ALLOCA
AC_FUNC_FORK
AC_FUNC_FSEEKO
AC_FUNC_MALLOC
AC_FUNC_MMAP
AC_FUNC_REALLOC
AC_FUNC_STRERROR_R
AC_CHECK_FUNCS([backtrace])

dnl Checks for system services:
AC_SYS_LARGEFILE
AC_SYS_LONG_FILE_NAMES

AC_CONFIG_FILES([Makefile src/Makefile doc/Makefile])
AC_SUBST([PACKAGE_VERSION_MAJOR], ["VERSION_MAJOR"])
AC_SUBST([PACKAGE_VERSION_MINOR], ["VERSION_MINOR"])
AC_SUBST([PACKAGE_VERSION_PATCH], ["VERSION_PATCH"])
AC_CONFIG_FILES([src/cprime.h])
AC_OUTPUT
