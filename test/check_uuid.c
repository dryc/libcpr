#include <assert.h> /* for assert() */
#include <stdio.h>  /* for printf() */
#include <stdlib.h> /* for EXIT_SUCCESS */

#include "build.h"

static void
check_uuid_is_null(void) {
  assert(uuid_is_null(&uuid_null));
}

static void
check_uuid_equal(void) {
  assert(uuid_equal(&uuid_null, &uuid_null));
}

static void
check_uuid_compare(void) {
  assert(uuid_compare(&uuid_null, &uuid_null) == COMPARE_EQ);
}

static void
check_uuid_serialize(void) {
  char buffer[UUID_LENGTH + 1];
  assert(uuid_serialize(&uuid_null, buffer, sizeof(buffer)) == UUID_LENGTH);
  assert(str_size(buffer) == UUID_LENGTH);
  assert(str_equal(buffer, "00000000-0000-0000-0000-000000000000"));
}

int
main(void) {
  check_uuid_is_null();
  check_uuid_equal();
  check_uuid_compare();
  check_uuid_serialize();
  return EXIT_SUCCESS;
}
