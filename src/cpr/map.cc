/* This is free and unencumbered software released into the public domain. */

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include "cpr/map.h"

#include <map> /* for std::map */

struct cpr_map : public std::map<void*, void*> {
  // TODO
};

extern const size_t cpr_map_sizeof = sizeof(cpr_map);