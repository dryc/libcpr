/* This is free and unencumbered software released into the public domain. */

#include <assert.h> /* for assert() */
#include <stdio.h>  /* for printf() */
#include <stdlib.h> /* for EXIT_SUCCESS */

#include <cpr/vector.h>

////////////////////////////////////////////////////////////////////////////////

static void
test_construct_empty(void) {
  cpr_vector_t* vector = cpr_vector(NULL);
  assert(vector != NULL);
  assert(cpr_vector_empty(vector));
}

static void
test_construct_nonempty(void) {
  cpr_vector_t* vector = cpr_vector((void*)1, (void*)2, (void*)3, NULL);
  assert(vector != NULL);
  assert(!cpr_vector_empty(vector));
  assert(cpr_vector_size(vector) == 3);
  assert(cpr_vector_at(vector, 0) == (void*)1);
  assert(cpr_vector_at(vector, 1) == (void*)2);
  assert(cpr_vector_at(vector, 2) == (void*)3);
}

static void
test_construct_from_strings(void) {
  cpr_vector_t* vector = cpr_vector_of_strings(NULL);
  assert(vector != NULL);
}

////////////////////////////////////////////////////////////////////////////////

int
main(void) {
  test_construct_empty();
  test_construct_from_strings();
  test_construct_nonempty();
  return EXIT_SUCCESS;
}
