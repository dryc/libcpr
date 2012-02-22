AM_CFLAGS   = -Wall -Wextra -pipe
AM_CPPFLAGS = -I$(top_srcdir)/src
LDADD       = $(top_srcdir)/src/libcprime.la

check_PROGRAMS = \
  check_ascii    \
  check_atom     \
  check_base64   \
  check_box      \
  check_char     \
  check_dir      \
  check_error    \
  check_file     \
  check_hash     \
  check_iter     \
  check_lock     \
  check_map      \
  check_once     \
  check_pair     \
  check_queue    \
  check_seq      \
  check_set      \
  check_str      \
  check_uri      \
  check_utf8     \
  check_uuid

TESTS = $(check_PROGRAMS)
