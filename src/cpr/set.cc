/* This is free and unencumbered software released into the public domain. */

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include "cpr/set.h"
#include "cpr/error.h"

#include <set> /* for std::set */

struct cpr_set : public std::set<void*> {};

extern const size_t cpr_set_sizeof = sizeof(cpr_set);
