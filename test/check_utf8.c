#include <assert.h> /* for assert() */
#include <locale.h> /* for LC_ALL, setlocale() */
#include <stdio.h>  /* for perror(), printf() */
#include <stdlib.h> /* for EXIT_SUCCESS */
#include <wchar.h>  /* for wchar_t, wcstombs() */

#include "build.h"

static int
wchar_encode(const wchar_t c,
             char* const restrict buffer,
             const size_t buffer_size) {
  const wchar_t input[2] = {c, L'\0'};
  const size_t rc = wcstombs(buffer, input, buffer_size);
  return (rc != (size_t)-1) ? (int)rc : FAILURE(errno);
}

static bool
equals_utf8(const int u, const char* const restrict utf8) {
  char buffer[8];
  bzero(buffer, sizeof(buffer));
  const int rc = wchar_encode(u, buffer, sizeof(buffer));
  if (failed(rc)) {
    perror("wcstombs");
    return FALSE;
  }
  return strncmp(utf8, buffer, sizeof(buffer)) == COMPARE_EQ;
}

static void
check_utf8_encode(void) {
  char buffer[8];

  /* Check the ASCII range (U+0000..U+007F): */
  for (int c = 0x00; c <= 0x7F; c++) {
    bzero(buffer, sizeof(buffer));
    assert(utf8_encode(c, buffer) == 1);
    assert(buffer[1] == '\0');
    assert(buffer[0] == c);
  }

  /* Check the ISO-8859-1 range (U+0080..U+00FF): */
  for (int c = 0x80; c <= 0xFF; c++) {
    bzero(buffer, sizeof(buffer));
    assert(utf8_encode(c, buffer) == 2);
    assert(buffer[2] == '\0');
    assert(equals_utf8(c, buffer));
  }

  /* Check the euro sign (U+20AC): */
  bzero(buffer, sizeof(buffer));
  assert(utf8_encode(0x20AC, buffer) == 3);
  assert(buffer[3] == '\0');
  assert(strncmp(buffer, "\xE2\x82\xAC", 3) == COMPARE_EQ);
}

static void
check_utf8_decode(void) {
  // TODO
}

int
main(void) {
  const char* locale = setlocale(LC_ALL, "");
  if (!str_contains(locale, ".UTF-8")) {
    locale = setlocale(LC_ALL, "en_US.UTF-8");
    assert(is_nonnull(locale));
  }
  check_utf8_encode();
  check_utf8_decode();
  return EXIT_SUCCESS;
}
