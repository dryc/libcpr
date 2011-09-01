/* This is free and unencumbered software released into the public domain. */

#ifndef _CPRIME_VECTORSET_H
#define _CPRIME_VECTORSET_H

#ifdef __cplusplus
extern "C" {
#endif

static int
vectorset_init(vectorset_t* const restrict set,
               const hash_func_t hash_func,
               const compare_func_t compare_func,
               const free_func_t free_func,
               va_list args) {
  (void)set, (void)hash_func, (void)compare_func,
  (void)free_func, (void)args;
  return -(errno = ENOTSUP); // TODO
}

static int
vectorset_reset(vectorset_t* const set) {
  (void)set;
  return -(errno = ENOTSUP); // TODO
}

static int
vectorset_clear(vectorset_t* const set) {
  (void)set;
  return -(errno = ENOTSUP); // TODO
}

static long
vectorset_count(vectorset_t* const restrict set,
                const void* const restrict elt) {
  (void)set, (void)elt;
  return (errno = ENOTSUP), 0; // TODO
}

static bool
vectorset_lookup(vectorset_t* const restrict set,
                 const void* const restrict elt) {
  (void)set, (void)elt;
  return (errno = ENOTSUP), FALSE; // TODO
}

static int
vectorset_insert(vectorset_t* const restrict set,
                 const void* const restrict elt) {
  (void)set, (void)elt;
  return -(errno = ENOTSUP); // TODO
}

static int
vectorset_remove(vectorset_t* const restrict set,
                 const void* const restrict elt) {
  (void)set, (void)elt;
  return -(errno = ENOTSUP); // TODO
}

static int
vectorset_replace(vectorset_t* const restrict set,
                  const void* const restrict elt1,
                  const void* const restrict elt2) {
  (void)set, (void)elt1, (void)elt2;
  return -(errno = ENOTSUP); // TODO
}

const set_vtable_t vectorset = {
  .super   = NULL,
  .name    = "vectorset",
  .options = 0,
  .init    = vectorset_init,
  .reset   = vectorset_reset,
  .clear   = vectorset_clear,
  .count   = vectorset_count,
  .lookup  = vectorset_lookup,
  .insert  = vectorset_insert,
  .remove  = vectorset_remove,
  .replace = vectorset_replace,
};

#ifdef __cplusplus
}
#endif

#endif /* _CPRIME_VECTORSET_H */
