dnl configure.ac                                        -*- Autoconf -*-
dnl
dnl Process this file with `autoconf` to produce a configure script.
dnl
dnl This is free and unencumbered software released into the public domain.
AC_PREREQ([2.60])

dnl Define version information:
m4_define([VERSION_MAJOR], 0)
m4_define([VERSION_MINOR], 0)
m4_define([VERSION_PATCH], 0)
m4_define([VERSION_STRING], [VERSION_MAJOR.VERSION_MINOR.VERSION_PATCH])

dnl Define package information:
AC_INIT([C′], [VERSION_STRING],
  [libcprime@googlegroups.com], [cprime],
  [https://github.com/bendiken/libcprime])

dnl Configure Autoconf:
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_SRCDIR([src/cprime.h.in])
AC_CONFIG_AUX_DIR([etc/aclocal])
AC_CONFIG_MACRO_DIR([etc/aclocal])

dnl Configure Automake:
AM_INIT_AUTOMAKE([foreign -Wall -Werror dist-bzip2 subdir-objects])
AM_SILENT_RULES([yes])

dnl Check for programs:
LT_INIT
AC_PROG_CC
AC_PROG_CC_C99
AM_PROG_CC_C_O

dnl Check for configuration options:
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

dnl Check for libraries:
AS_IF([test "x$enable_threads" != "xno"], [
# POSIX threads support:
  AC_CHECK_HEADERS([pthread.h],
    AC_SEARCH_LIBS([pthread_create], [pthread], [],
      AC_MSG_ERROR([*** POSIX thread support library libpthread not found ***])),
    AC_MSG_ERROR([*** POSIX thread support header file pthread.h not found ***]))
])
# POSIX message queues:
AC_CHECK_HEADERS([mqueue.h], AC_SEARCH_LIBS([mq_send], [rt]))

dnl Check for header files:
# C89 header files:
AC_CHECK_HEADERS_ONCE([assert.h ctype.h limits.h setjmp.h stdarg.h])
# C99 header files:
AC_CHECK_HEADERS_ONCE([complex.h ctype.h inttypes.h stdbool.h stdint.h tgmath.h])
AC_HEADER_STDBOOL
# C1X header files:
AC_CHECK_HEADERS_ONCE([stdatomic.h threads.h uchar.h])
# POSIX header files:
AC_CHECK_HEADERS_ONCE([dirent.h errno.h iconv.h libgen.h mqueue.h poll.h
                       sched.h signal.h syslog.h sys/resource.h sys/wait.h])
# GNU header files:
AC_CHECK_HEADERS_ONCE([execinfo.h])

dnl Check for types:
AC_CHECK_TYPES([cpu_set_t], [], [], [[#include <sched.h>]])
AS_IF([test "x$enable_threads" != "xno"], [
# POSIX threads support:
  AC_CHECK_TYPES([pthread_t, pthread_attr_t],
    [], [], [[#include <pthread.h>]])
  AC_CHECK_TYPES([pthread_mutex_t, pthread_once_t, pthread_rwlock_t],
    [], [], [[#include <pthread.h>]])
])

dnl Check for structures:

dnl Check for compiler characteristics:
AC_CANONICAL_HOST
AC_C_BIGENDIAN
AC_C_INLINE
AC_C_RESTRICT

dnl Check for library functions:
AC_FUNC_ALLOCA
AC_FUNC_FORK
AC_FUNC_FSEEKO
AC_FUNC_MALLOC
AC_FUNC_MMAP
AC_FUNC_REALLOC
AC_FUNC_STRERROR_R
AC_CHECK_FUNCS_ONCE([backtrace])
# POSIX directory access:
AC_CHECK_FUNCS_ONCE([
  closedir
  opendir
  readdir_r
])
# POSIX process control:
AC_CHECK_FUNCS_ONCE([
  getpid
  kill
  sched_setaffinity
  setpriority
  waitpid
])
AS_IF([test "x$enable_threads" != "xno"], [
# POSIX threads support:
  AC_CHECK_FUNCS_ONCE([
    pthread_attr_destroy
    pthread_attr_init
    pthread_cancel
    pthread_create
    pthread_detach
    pthread_equal
    pthread_join
    pthread_kill
    pthread_mutex_destroy
    pthread_mutex_init
    pthread_mutex_lock
    pthread_mutex_trylock
    pthread_mutex_unlock
    pthread_once
    pthread_rwlock_destroy
    pthread_rwlock_init
    pthread_rwlock_rdlock
    pthread_rwlock_tryrdlock
    pthread_rwlock_trywrlock
    pthread_rwlock_unlock
    pthread_rwlock_wrlock
    pthread_self
  ])
# POSIX threads support (Linux only):
  AC_CHECK_FUNCS_ONCE([
    pthread_getattr_np
    pthread_setaffinity_np
  ])
])

dnl Check for system services:
AC_SYS_LARGEFILE
AC_SYS_LONG_FILE_NAMES

dnl Generate output:
AC_CONFIG_FILES([Makefile src/Makefile doc/Makefile])
AC_SUBST([PACKAGE_VERSION_MAJOR], ["VERSION_MAJOR"])
AC_SUBST([PACKAGE_VERSION_MINOR], ["VERSION_MINOR"])
AC_SUBST([PACKAGE_VERSION_PATCH], ["VERSION_PATCH"])
AC_CONFIG_FILES([src/cprime.h])
AC_OUTPUT
