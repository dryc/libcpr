/* This is free and unencumbered software released into the public domain. */

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include "error.h"
#include "map.h"

#include <map> /* for std::map */

////////////////////////////////////////////////////////////////////////////////
/* Internals */

struct cpr_map : public std::map<void*, void*> {};

////////////////////////////////////////////////////////////////////////////////
/* Constants */

extern const size_t cpr_map_sizeof = sizeof(cpr_map);
