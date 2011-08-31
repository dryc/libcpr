/* This is free and unencumbered software released into the public domain. */

#ifndef _CPRIME_HASHSET_H
#define _CPRIME_HASHSET_H

#ifdef __cplusplus
extern "C" {
#endif

static int
hashset_init(set_t* const set, va_list args) {
  (void)set, (void)args;
  return -(errno = ENOTSUP); // TODO
}

static int
hashset_clear(set_t* const set) {
  (void)set;
  return -(errno = ENOTSUP); // TODO
}

static long
hashset_count(set_t* const restrict set, const void* const restrict elt) {
  (void)set, (void)elt;
  return (errno = ENOTSUP), 0; // TODO
}

static bool
hashset_lookup(set_t* const restrict set, const void* const restrict elt) {
  (void)set, (void)elt;
  return (errno = ENOTSUP), FALSE; // TODO
}

static int
hashset_insert(set_t* const restrict set, const void* const restrict elt) {
  (void)set, (void)elt;
  return -(errno = ENOTSUP); // TODO
}

static int
hashset_remove(set_t* const restrict set, const void* const restrict elt) {
  (void)set, (void)elt;
  return -(errno = ENOTSUP); // TODO
}

static int
hashset_replace(set_t* const restrict set, const void* const restrict elt1,
                                           const void* const restrict elt2) {
  (void)set, (void)elt1, (void)elt2;
  return -(errno = ENOTSUP); // TODO
}

const set_vtable_t hashset = {
  .super   = NULL,
  .name    = "hashset",
  .options = 0,
  .init    = hashset_init,
  .clear   = hashset_clear,
  .count   = hashset_count,
  .lookup  = hashset_lookup,
  .insert  = hashset_insert,
  .remove  = hashset_remove,
  .replace = hashset_replace,
};

#ifdef __cplusplus
}
#endif

#endif /* _CPRIME_HASHSET_H */
