/* This is free and unencumbered software released into the public domain. */

#ifndef _CPRIME_HASHSET_H
#define _CPRIME_HASHSET_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h> /* for size_t */

typedef struct hashset_entry_t {
  hash_t hash;
  void* elt;
} hashset_entry_t;

typedef struct hashset_table_t {
  size_t capacity;
  size_t count;
  hashset_entry_t entries[];
} hashset_table_t;

static int
hashset_init(hashset_t* const set, va_list args) {
  (void)args;
  set->instance = calloc(1, sizeof(hashset_table_t));
  if (is_null(set->instance)) {
    return -errno;
  }
  return 0;
}

static int
hashset_reset(hashset_t* const set) {
  if (is_nonnull(set->instance)) {
    free(set->instance);
    set->instance = NULL;
  }
  return 0;
}

static int
hashset_clear(hashset_t* const set) {
  hashset_table_t* const old_table = set->instance;
  hashset_table_t* const new_table = calloc(1, sizeof(hashset_table_t));
  set->instance = new_table;
  free(old_table);
  return 0;
}

static long
hashset_count(hashset_t* const restrict set,
              const void* const restrict elt) {
  (void)set, (void)elt;
  return (errno = ENOTSUP), 0; // TODO
}

static bool
hashset_lookup(hashset_t* const restrict set,
               const void* const restrict elt) {
  (void)set, (void)elt;
  return (errno = ENOTSUP), FALSE; // TODO
}

static int
hashset_insert(hashset_t* const restrict set,
               const void* const restrict elt) {
  (void)set, (void)elt;
  return -(errno = ENOTSUP); // TODO
}

static int
hashset_remove(hashset_t* const restrict set,
               const void* const restrict elt) {
  (void)set, (void)elt;
  return -(errno = ENOTSUP); // TODO
}

static int
hashset_replace(hashset_t* const restrict set,
                const void* const restrict elt1,
                const void* const restrict elt2) {
  (void)set, (void)elt1, (void)elt2;
  return -(errno = ENOTSUP); // TODO
}

const set_vtable_t hashset = {
  .super   = NULL,
  .name    = "hashset",
  .options = 0,
  .init    = hashset_init,
  .reset   = hashset_reset,
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
