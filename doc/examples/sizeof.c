/**
 * Example program that prints out the libcpr data structure sizes.
 *
 * Compile with: `cc -std=c11 -o sizeof sizeof.c -lcpr`
 */

#include <stdio.h>
#include <stdlib.h>

#include <cpr/error.h>
#include <cpr/list.h>
#include <cpr/map.h>
#include <cpr/set.h>
#include <cpr/string.h>
#include <cpr/vector.h>

int main(void) {
  printf("sizeof(cpr_error_t):\t%zu bytes\n",  cpr_error_sizeof);
  printf("sizeof(cpr_list_t):\t%zu bytes\n",   cpr_list_sizeof);
  printf("sizeof(cpr_map_t):\t%zu bytes\n",    cpr_map_sizeof);
  printf("sizeof(cpr_set_t):\t%zu bytes\n",    cpr_set_sizeof);
  printf("sizeof(cpr_string_t):\t%zu bytes\n", cpr_string_sizeof);
  printf("sizeof(cpr_vector_t):\t%zu bytes\n", cpr_vector_sizeof);
  return EXIT_SUCCESS;
}
