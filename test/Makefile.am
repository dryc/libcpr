AM_CPPFLAGS = -I$(top_srcdir)/src -iquote $(srcdir)
AM_CFLAGS   = -Wall -Wextra -pipe
LDADD       = $(top_srcdir)/src/cpr/libcpr.la

check_PROGRAMS = \
  check_feature  \
  check_module   \
  check_prelude  \
  check_version

TESTS = $(check_PROGRAMS)
