/* This is free and unencumbered software released into the public domain. */

#include <assert.h> /* for assert() */
#include <stdio.h>  /* for printf() */
#include <stdlib.h> /* for EXIT_SUCCESS */

#include <cpr/string.h>

static void
test_construct_empty(void) {
  {
    cpr_string_t* string = cpr_string(NULL);
    assert(string);
    assert(cpr_string_empty(string));
    assert(cpr_string_size(string) == 0);
  }
  {
    cpr_string_t* string = cpr_string("");
    assert(string);
    assert(cpr_string_empty(string));
    assert(cpr_string_size(string) == 0);
  }
}

static void
test_construct_nonempty(void) {
  cpr_string_t* string = cpr_string("Hello, world!");
  assert(string);
  assert(!cpr_string_empty(string));
  assert(cpr_string_size(string) == 13);
}

static void
test_capacity(void) {
  cpr_string_t* string = cpr_string("foobar");
  assert(string);
  assert(cpr_string_capacity(string) >= 6);
}

static void
test_clear(void) {
  cpr_string_t* string = cpr_string("foobar");
  assert(string);
  assert(!cpr_string_empty(string));
  cpr_string_clear(string);
  assert(cpr_string_empty(string));
}

static void
test_empty(void) {
  // TODO
}

static void
test_length(void) {
  // TODO
}

static void
test_max_size(void) {
  cpr_string_t* string = cpr_string(NULL);
  assert(string);
  assert(cpr_string_max_size(string) > 0);
}

static void
test_pop_back(void) {
  cpr_string_t* string = cpr_string("foo");
  assert(string);
  assert(cpr_string_size(string) == 3);
  cpr_string_pop_back(string);
  assert(cpr_string_size(string) == 2);
  cpr_string_pop_back(string);
  assert(cpr_string_size(string) == 1);
  cpr_string_pop_back(string);
  assert(cpr_string_size(string) == 0);
}

static void
test_push_back(void) {
  cpr_string_t* string = cpr_string(NULL);
  assert(string);
  assert(cpr_string_size(string) == 0);
  cpr_string_push_back(string, 'f');
  assert(cpr_string_size(string) == 1);
  cpr_string_push_back(string, 'o');
  assert(cpr_string_size(string) == 2);
  cpr_string_push_back(string, 'o');
  assert(cpr_string_size(string) == 3);
}

static void
test_size(void) {
  // TODO
}

int
main(void) {
  test_construct_empty();
  test_construct_nonempty();
  test_capacity();
  test_clear();
  test_empty();
  test_length();
  test_max_size();
  test_pop_back();
  test_push_back();
  test_size();
  return EXIT_SUCCESS;
}
