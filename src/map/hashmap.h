/* This is free and unencumbered software released into the public domain. */

#ifndef CPRIME_HASHMAP_H
#define CPRIME_HASHMAP_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h> /* for size_t */

#define HASHMAP_CAPACITY_MIN 4

typedef struct hashmap_entry_t {
  const void* key;
  hash_t hash;
  const void* value;
} hashmap_entry_t;

typedef struct hashmap_table_t {
  size_t capacity;
  size_t count;
  hashmap_entry_t entries[];
} hashmap_table_t;

int hashmap_iter_init(map_iter_t* iter, map_t* map);
int hashmap_iter_dispose(map_iter_t* iter);
bool hashmap_iter_next(map_iter_t* iter, void** key, void** value);
int hashmap_iter_remove(map_iter_t* iter);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* CPRIME_HASHMAP_H */
