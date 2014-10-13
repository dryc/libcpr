/* This is free and unencumbered software released into the public domain. */

#include <assert.h> /* for assert() */
#include <stdio.h>  /* for printf() */
#include <stdlib.h> /* for EXIT_SUCCESS */
#include <string.h> /* for strcmp(), strlen() */

#include <cpr/string.h>

////////////////////////////////////////////////////////////////////////////////

static void
test_construct_with_null(void) {
  cpr_string_t* string = cpr_string(NULL);
  assert(string);
  assert(cpr_string_empty(string));
  assert(cpr_string_size(string) == 0);
}

static void
test_construct_with_empty_string(void) {
  cpr_string_t* string = cpr_string("");
  assert(string);
  assert(cpr_string_empty(string));
  assert(cpr_string_size(string) == 0);
}

static void
test_construct_with_nonempty_string(void) {
  cpr_string_t* string = cpr_string("Hello, world!");
  assert(string);
  assert(!cpr_string_empty(string));
  assert(cpr_string_size(string) == 13);
}

static void
test_append_char(void) {
  cpr_string_t* string = cpr_string(NULL);
  assert(string);
  assert(cpr_string_size(string) == 0);
  cpr_string_append_char(string, 1, 'f');
  assert(cpr_string_size(string) == 1);
  cpr_string_append_char(string, 2, 'o');
  assert(cpr_string_size(string) == 3);
}

static void
test_at(void) {
  cpr_string_t* string = cpr_string("0123456789");
  assert(string);
  for (int i = 0; i < 9; i++) {
    char* const char_at = cpr_string_at(string, i);
    assert(char_at);
    assert(*char_at == '0' + i);
  }
  assert(!cpr_string_at(string, 10));
}

static void
test_back(void) {
  cpr_string_t* string = cpr_string("foobar");
  assert(string);
  char* string_back = cpr_string_back(string);
  assert(string_back);
  assert(*string_back == 'r');
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
test_compare(void) {
  cpr_string_t* string1 = cpr_string("foo");
  cpr_string_t* string2 = cpr_string("bar");
  assert(string1);
  assert(string2);
  assert(cpr_string_compare(string1, string1) == 0);
  assert(cpr_string_compare(string2, string2) == 0);
  assert(cpr_string_compare(string1, string2) > 0);
  assert(cpr_string_compare(string2, string1) < 0);
}

static void
test_data(void) {
  cpr_string_t* string = cpr_string("foobar");
  assert(string);
  char* string_data = cpr_string_data(string);
  assert(string_data);
  assert(string_data[0] == 'f');
  assert(string_data[6] == '\0');
  assert(strlen(string_data) == 6);
  assert(strcmp(string_data, "foobar") == 0);
}

static void
test_empty(void) {
  // TODO
}

static void
test_free(void) {
  cpr_string_t* string = cpr_string("foobar");
  assert(string);
  cpr_string_free(string);
}

static void
test_front(void) {
  cpr_string_t* string = cpr_string("foobar");
  assert(string);
  char* string_front = cpr_string_front(string);
  assert(string_front);
  assert(*string_front == 'f');
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
test_reserve(void) {
  cpr_string_t* string = cpr_string(NULL);
  assert(string);
  cpr_string_reserve(string, 4096);
  assert(cpr_string_capacity(string) >= 4096);
}

static void
test_resize(void) {
  cpr_string_t* string = cpr_string(NULL);
  assert(string);
  assert(cpr_string_size(string) == 0);
  cpr_string_resize(string, 1, '\0');
  assert(cpr_string_size(string) == 1);
  cpr_string_resize(string, 10, '\0');
  assert(cpr_string_size(string) == 10);
  cpr_string_resize(string, 0, '\0');
  assert(cpr_string_size(string) == 0);
}

static void
test_size(void) {
  // TODO
}

////////////////////////////////////////////////////////////////////////////////

int
main(void) {
  test_construct_with_null();
  test_construct_with_empty_string();
  test_construct_with_nonempty_string();
  test_append_char();
  test_at();
  test_back();
  test_capacity();
  test_clear();
  test_compare();
  test_data();
  test_empty();
  test_free();
  test_front();
  test_length();
  test_max_size();
  test_pop_back();
  test_push_back();
  test_reserve();
  test_resize();
  test_size();
  return EXIT_SUCCESS;
}
