AM_CPPFLAGS = -I$(top_srcdir)/src -iquote $(srcdir)
AM_CFLAGS   = -Wall -Wextra -pipe
LDADD       = $(top_srcdir)/src/cpr/libcpr.la

check_PROGRAMS = \
  check_feature  \
  check_module   \
  check_unsafe   \
  check_version

if !DISABLE_LIST
  check_PROGRAMS += check_list
endif

if !DISABLE_MAP
  check_PROGRAMS += check_map
endif

if !DISABLE_SET
  check_PROGRAMS += check_set
endif

if !DISABLE_STRING
  check_PROGRAMS += check_string
endif

if !DISABLE_VECTOR
  check_PROGRAMS += check_vector
endif

TESTS = $(check_PROGRAMS)
