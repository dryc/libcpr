/* This is free and unencumbered software released into the public domain. */

#ifndef _CPRIME_HASHSET_H
#define _CPRIME_HASHSET_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h> /* for size_t */

#define HASHSET_CAPACITY_MIN 4

typedef struct hashset_entry_t {
  const void* elt;
  hash_t hash;
} hashset_entry_t;

typedef struct hashset_table_t {
  size_t capacity;
  size_t count;
  hashset_entry_t entries[];
} hashset_table_t;

static inline long
hashset_size(size_t capacity) {
  return sizeof(hashset_table_t) + (capacity * sizeof(hashset_entry_t));
}

static int
hashset_init(hashset_t* const set, va_list args) {
  (void)args;
  hashset_table_t* const table = calloc(1, hashset_size(HASHSET_CAPACITY_MIN));
  if (is_null(table)) {
    return FAILURE(errno);
  }
  table->capacity = HASHSET_CAPACITY_MIN;
  set->instance = table;
  return SUCCESS;
}

static int
hashset_reset(hashset_t* const set) {
  if (is_nonnull(set->instance)) {
    free(set->instance);
    set->instance = NULL;
  }
  return SUCCESS;
}

static int
hashset_clear(hashset_t* const set) {
  hashset_table_t* const old_table = set->instance;

  hashset_table_t* const new_table = calloc(1, hashset_size(HASHSET_CAPACITY_MIN));
  new_table->capacity = HASHSET_CAPACITY_MIN;

  set->instance = new_table;
  free(old_table);

  return SUCCESS;
}

static bool
hashset_lookup(hashset_t* const restrict set,
               const void* const restrict elt) {
  hashset_table_t* const table = set->instance;
  assert(table != NULL);

  const hash_t hash = set->hash_func(elt);
  const compare_func_t compare = set->compare_func;
  assert(compare != NULL);

  hash_t index = hash & (table->capacity - 1);
  while (index < table->capacity) {
    const hashset_entry_t* const entry = &table->entries[index];

    if (is_null(entry->elt)) {
      return FALSE; // element not found in set
    }

    if (entry->elt == elt || (entry->hash == hash && compare(entry->elt, elt) == 0)) {
      return TRUE;  // element found
    }

    index++; // reprobe linearly
  }

  return FALSE; // element not found in set
}

static long
hashset_count(hashset_t* const restrict set,
              const void* const restrict elt) {
  hashset_table_t* const table = set->instance;
  assert(table != NULL);

  if (is_null(elt)) {
    return table->count;
  }

  return (hashset_lookup(set, elt) == TRUE) ? 1 : 0;
}

static int
hashset_insert(hashset_t* const restrict set,
               const void* const restrict elt) {
  hashset_table_t* const table = set->instance;
  assert(table != NULL);

  (void)table, (void)set, (void)elt;
  return FAILURE(ENOTSUP); // TODO
}

static int
hashset_remove(hashset_t* const restrict set,
               const void* const restrict elt) {
  hashset_table_t* const table = set->instance;
  assert(table != NULL);

  (void)table, (void)set, (void)elt;
  return FAILURE(ENOTSUP); // TODO
}

static int
hashset_replace(hashset_t* const restrict set,
                const void* const restrict elt1,
                const void* const restrict elt2) {
  hashset_table_t* const table = set->instance;
  assert(table != NULL);

  (void)table, (void)set, (void)elt1, (void)elt2;
  return FAILURE(ENOTSUP); // TODO
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
