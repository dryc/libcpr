/* This is free and unencumbered software released into the public domain. */

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include "error.h"
#include "list.h"

#include <list> /* for std::list */

////////////////////////////////////////////////////////////////////////////////
/* Internals */

struct cpr_list : public std::list<void*> {};

////////////////////////////////////////////////////////////////////////////////
/* Constants */

extern const size_t cpr_list_sizeof = sizeof(cpr_list);
