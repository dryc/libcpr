/* This is free and unencumbered software released into the public domain. */

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include "cpr/string.h"

#include <string> /* for std::string */

struct cpr_string : public std::string {};

extern const size_t cpr_string_sizeof = sizeof(cpr_string);
