#include <assert.h> /* for assert() */
#include <stdio.h>  /* for printf() */
#include <stdlib.h> /* for EXIT_SUCCESS */

#include "build.h"
#include "set/hashset.h"

static void
test_int_set(void) {
  /* Test initialization: */
  set_t set;
  assert(succeeded(set_init(&set, HASHSET, NULL, NULL, NULL)));

  /* Test post-initialization state: */
  assert(is_equal(0, set_count(&set, NULL)));
  assert(is_equal(0, set_count(&set, UINT_TO_PTR(42))));
  assert(is_false(set_lookup(&set, UINT_TO_PTR(42))));

  /* Test element insertion: */
  assert(is_true(set_insert(&set, UINT_TO_PTR(42))));
  assert(is_equal(1, set_count(&set, NULL)));
  assert(is_equal(1, set_count(&set, UINT_TO_PTR(42))));
  assert(is_true(set_lookup(&set, UINT_TO_PTR(42))));

  /* Test duplicate element insertion: */
  assert(is_false(set_insert(&set, UINT_TO_PTR(42))));
  assert(is_equal(1, set_count(&set, NULL)));
  assert(is_equal(1, set_count(&set, UINT_TO_PTR(42))));
  assert(is_true(set_lookup(&set, UINT_TO_PTR(42))));

  /* Test element removal: */
  assert(succeeded(set_remove(&set, UINT_TO_PTR(42))));
  assert(is_equal(0, set_count(&set, NULL)));
  assert(is_equal(0, set_count(&set, UINT_TO_PTR(42))));
  assert(is_false(set_lookup(&set, UINT_TO_PTR(42))));

  /* Test multiple element insertion: */
  for (unsigned int i = 1; i <= 10; i++) {
    assert(is_true(set_insert(&set, UINT_TO_PTR(i))));
    assert(is_false(set_insert(&set, UINT_TO_PTR(i)))); /* duplicate */
    assert(is_equal(i, set_count(&set, NULL)));
    assert(is_equal(1, set_count(&set, UINT_TO_PTR(i))));
    assert(is_true(set_lookup(&set, UINT_TO_PTR(i))));
    assert(is_false(set_lookup(&set, UINT_TO_PTR(i + 1))));
  }
  assert(is_equal(10, set_count(&set, NULL)));

  /* Test every-element removal: */
  assert(succeeded(set_clear(&set)));
  assert(is_equal(0, set_count(&set, NULL)));

  /* Test disposal: */
  assert(succeeded(set_dispose(&set)));
}

static void
test_hashset(void) {
  assert(sizeof(hashset_entry_t) <= sizeof(void*) * 2);
  test_int_set();
}

int
main(void) {
  test_hashset();
  return EXIT_SUCCESS;
}
