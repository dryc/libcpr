/* This is free and unencumbered software released into the public domain. */

#ifndef _CPRIME_NULLSET_H
#define _CPRIME_NULLSET_H

#ifdef __cplusplus
extern "C" {
#endif

static int
nullset_init(nullset_t* const set, va_list args) {
  (void)set, (void)args;
  return SUCCESS;
}

static int
nullset_reset(nullset_t* const set) {
  (void)set;
  return SUCCESS;
}

static int
nullset_clear(nullset_t* const set) {
  (void)set;
  return SUCCESS;
}

static long
nullset_count(nullset_t* const restrict set,
              const void* const restrict elt) {
  (void)set, (void)elt;
  return 0; // set is empty
}

static bool
nullset_lookup(nullset_t* const restrict set,
               const void* const restrict elt) {
  (void)set, (void)elt;
  return FALSE; // element not found
}

static int
nullset_insert(nullset_t* const restrict set,
               const void* const restrict elt) {
  (void)set, (void)elt;
  return -(errno = ENOTSUP); // operation not supported
}

static int
nullset_remove(nullset_t* const restrict set,
               const void* const restrict elt) {
  (void)set, (void)elt;
  return -(errno = ENOTSUP); // operation not supported
}

static int
nullset_replace(nullset_t* const restrict set,
                const void* const restrict elt1,
                const void* const restrict elt2) {
  (void)set, (void)elt1, (void)elt2;
  return -(errno = ENOTSUP); // operation not supported
}

/**
 * The canonical immutable empty set.
 */
const set_vtable_t nullset = {
  .super   = NULL,
  .name    = "nullset",
  .init    = nullset_init,
  .reset   = nullset_reset,
  .clear   = nullset_clear,
  .count   = nullset_count,
  .lookup  = nullset_lookup,
  .insert  = nullset_insert,
  .remove  = nullset_remove,
  .replace = nullset_replace,
};

#ifdef __cplusplus
}
#endif

#endif /* _CPRIME_NULLSET_H */
