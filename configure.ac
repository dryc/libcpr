AC_INIT([cprime], [0.0.0], [cprime@googlegroups.com])
AC_CONFIG_SRCDIR([src/cprime.h])
AC_CONFIG_AUX_DIR([etc/aclocal])
AC_CONFIG_MACRO_DIR([etc/aclocal])
AM_INIT_AUTOMAKE([foreign -Wall -Werror dist-bzip2])
AM_SILENT_RULES([yes])
LT_INIT
AC_PROG_CC
AC_CANONICAL_HOST
dnl C89 header files:
AC_CHECK_HEADERS_ONCE([assert.h ctype.h limits.h setjmp.h stdarg.h])
dnl C99 header files:
AC_CHECK_HEADERS_ONCE([complex.h ctype.h inttypes.h stdbool.h stdint.h tgmath.h])
dnl C1X header files:
AC_CHECK_HEADERS_ONCE([stdatomic.h threads.h uchar.h])
dnl POSIX header files:
AC_CHECK_HEADERS_ONCE([dirent.h errno.h iconv.h libgen.h mqueue.h poll.h
                       pthread.h sched.h syslog.h])
dnl Linux header files:
AC_CHECK_HEADERS_ONCE([execinfo.h])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([Makefile src/Makefile doc/Makefile])
AC_OUTPUT
