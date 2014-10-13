/* This is free and unencumbered software released into the public domain. */

#include <assert.h> /* for assert() */
#include <stdio.h>  /* for printf() */
#include <stdlib.h> /* for EXIT_SUCCESS */

#include <cpr/unsafe.h>
#include <cpr/vector.h>

////////////////////////////////////////////////////////////////////////////////

static void
test_unsafe_vector(void) {
  cpr_vector_t* vector = cpr_vector_alloca();
  cpr_vector_init(vector, NULL);
  cpr_vector_clear(vector);
  cpr_vector_dispose(vector);
}

////////////////////////////////////////////////////////////////////////////////

int
main(void) {
  test_unsafe_vector();
  return EXIT_SUCCESS;
}
