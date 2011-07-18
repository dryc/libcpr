/* This is free and unencumbered software released into the public domain. */
/* Build this with: `gcc -std=c99 -o list_iter list_iter.c -lcprime` */

#include <cprime.h>
#include <stdio.h>  /* for fputs() */

int
main(int argc, char* argv[]) {
  list_t list = LIST_INIT;
  for (int i = 1; i < argc; i++) {
    list_prepend(&list, string_construct_with_data(argv[i]));
  }
  list_reverse(&list);

  fputs("(", stdout);
  {
    list_iter_t list_iter = LIST_ITER_INIT(&list);
    while (iter_next(&list_iter)) {
      string_t* string = list_iter.current;

      if (list_iter.iter.position > 1)
        fputs(" ", stdout);
      fputs(string->data, stdout);
    }
  }
  fputs(")\n", stdout);
}
