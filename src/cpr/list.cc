/* This is free and unencumbered software released into the public domain. */

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include "cpr/list.h"

#include <list> /* for std::list */

struct cpr_list : public std::list<void*> {
  // TODO
};
