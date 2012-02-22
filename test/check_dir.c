#include <assert.h> /* for assert() */
#include <libgen.h> /* for dirname() */
#include <stdio.h>  /* for printf() */
#include <stdlib.h> /* for EXIT_SUCCESS */

#include "build.h"

static void
check_dir_exists(void) {
  char path[PATH_MAX];
  strcpy(path, __FILE__);
  assert(dir_exists(dirname(path)));
}

int
main(void) {
  check_dir_exists();
  return EXIT_SUCCESS;
}
