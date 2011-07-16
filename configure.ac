AC_INIT([C′], [0.0.0], [libcprime@googlegroups.com], [cprime],
  [https://github.com/bendiken/libcprime])
AC_PREREQ([2.60])

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

dnl Checks for libraries:
# POSIX threads support:
AC_CHECK_HEADERS([pthread.h],
  AC_SEARCH_LIBS([pthread_create], [pthread], [],
    AC_MSG_ERROR([*** POSIX thread support library libpthread not found ***])),
  AC_MSG_ERROR([*** POSIX thread support header file pthread.h not found ***]))

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

dnl Checks for library functions:
AC_FUNC_ALLOCA
AC_FUNC_FORK
AC_FUNC_FSEEKO
AC_FUNC_MALLOC
AC_FUNC_MMAP
AC_FUNC_REALLOC
AC_FUNC_STRERROR_R

dnl Checks for system services:
AC_SYS_LARGEFILE
AC_SYS_LONG_FILE_NAMES

AC_CONFIG_FILES([Makefile src/Makefile doc/Makefile])
AC_CONFIG_FILES([src/cprime.h])
AC_OUTPUT
