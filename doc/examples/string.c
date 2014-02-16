#include <stdio.h>
#include <stdlib.h>

#include <cpr/string.h>

int main(void) {
  cpr_string_t* string = cpr_string("Numbers 0 to 9:\n");

  for (int i = 0; i <= 9; i++) {
    cpr_string_push_back(string, '0' + i);
    cpr_string_push_back(string, '\n');
  }

  puts(cpr_string_data(string));

  cpr_string_free(string);

  return EXIT_SUCCESS;
}
