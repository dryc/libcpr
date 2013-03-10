/* This is free and unencumbered software released into the public domain. */

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include "cpr/list.h"
#include "cpr/error.h"

#include <list> /* for std::list */

struct cpr_list : public std::list<void*> {};

extern const size_t cpr_list_sizeof = sizeof(cpr_list);
