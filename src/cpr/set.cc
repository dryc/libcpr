/* This is free and unencumbered software released into the public domain. */

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include "error.h"
#include "set.h"

#include <set> /* for std::set */

////////////////////////////////////////////////////////////////////////////////
/* Internals */

struct cpr_set : public std::set<void*> {};

////////////////////////////////////////////////////////////////////////////////
/* Constants */

extern const size_t cpr_set_sizeof = sizeof(cpr_set);
