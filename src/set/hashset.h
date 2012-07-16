/* This is free and unencumbered software released into the public domain. */

#ifndef CPRIME_HASHSET_H
#define CPRIME_HASHSET_H

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

int hashset_iter_init(set_iter_t* iter, set_t* set);
int hashset_iter_dispose(set_iter_t* iter);
bool hashset_iter_next(set_iter_t* iter, void** elt);
int hashset_iter_remove(set_iter_t* iter);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* CPRIME_HASHSET_H */
