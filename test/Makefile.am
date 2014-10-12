AM_CPPFLAGS += $(TEST_CPPFLAGS)
AM_CFLAGS   += $(TEST_CFLAGS)
AM_LDFLAGS  += $(TEST_LDFLAGS)

LDADD = $(top_srcdir)/src/cpr/libcpr.la

check_PROGRAMS = \
  check-error    \
  check-feature  \
  check-module   \
  check-unsafe   \
  check-version

#if 1
  check_PROGRAMS += check-generic
#endif

if !DISABLE_LIST
  check_PROGRAMS += check-list
endif

if !DISABLE_MAP
  check_PROGRAMS += check-map
endif

if !DISABLE_SET
  check_PROGRAMS += check-set
endif

if !DISABLE_STRING
  check_PROGRAMS += check-string
endif

if !DISABLE_VECTOR
  check_PROGRAMS += check-vector
endif

TESTS = $(check_PROGRAMS)
