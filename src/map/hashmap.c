/* This is free and unencumbered software released into the public domain. */

#include "build.h"
#include "map/hashmap.h"

static inline void
hashmap_entry_dispose(hashmap_entry_t* const restrict entry,
                      const free_func_t free_key_func,
                      const free_func_t free_value_func) {
  if (is_nonnull(entry->key)) {
    if (is_nonnull(free_key_func)) {
      free_key_func((void*)entry->key);
    }
    if (is_nonnull(free_value_func)) {
      free_value_func((void*)entry->value);
    }
    entry->hash  = 0;
    entry->key   = NULL;
    entry->value = NULL;
  }
}

static inline size_t
hashmap_table_size(const size_t capacity) {
  return sizeof(hashmap_table_t) + (capacity * sizeof(hashmap_entry_t));
}

static inline hashmap_table_t*
hashmap_table_alloc(const size_t capacity) {
  hashmap_table_t* const restrict table = calloc(1, hashmap_table_size(capacity));
  if (is_nonnull(table)) {
    table->capacity = capacity;
  }
  return table;
}

static inline void
hashmap_table_free(hashmap_table_t* const restrict table,
                   const free_func_t free_key_func,
                   const free_func_t free_value_func) {
  if (is_nonnull(table)) {
    if (is_nonnull(free_key_func) || is_nonnull(free_value_func)) {
      for (size_t index = 0; index < table->capacity; index++) {
        const hashmap_entry_t* const restrict entry = &table->entries[index];
        if (is_nonnull(entry->key)) {
          if (is_nonnull(free_key_func))
            free_key_func((void*)entry->key);
          if (is_nonnull(free_value_func))
            free_value_func((void*)entry->value);
        }
      }
    }
    free(table);
  }
}

static bool
hashmap_resize(hashmap_t* const restrict map,
               const size_t capacity) {
  hashmap_table_t* const restrict old_table = map->instance;
  hashmap_table_t* const restrict new_table = hashmap_table_alloc(capacity);
  assert(is_nonnull(new_table));

  new_table->count = old_table->count;

  for (size_t old_index = 0; old_index < old_table->capacity; old_index++) {
    const hashmap_entry_t* const restrict old_entry = &old_table->entries[old_index];
    if (is_null(old_entry->key))
      continue; /* skip unused entries */

    size_t new_index = old_entry->hash & (new_table->capacity - 1);
    for (; new_index < new_table->capacity; new_index++) {
      hashmap_entry_t* const restrict new_entry = &new_table->entries[new_index];
      if (is_null(new_entry->key)) {
        new_entry->hash  = old_entry->hash;
        new_entry->key   = old_entry->key;
        new_entry->value = old_entry->value;
        break;
      }
    }
    if (new_index == new_table->capacity) {
      goto fail;
    }
  }

#if 0
  fprintf(stderr, "hashmap_resize: grew table capacity from %zu to %zu entries (count=%zu)\n",
    old_table->capacity, new_table->capacity, old_table->count);
#endif
  map->instance = new_table;
  free(old_table);
  return TRUE;

fail:
#if 0
  fprintf(stderr, "hashmap_resize: failed to grow table capacity from %zu to %zu entries (count=%zu)\n",
    old_table->capacity, new_table->capacity, old_table->count);
#endif
  free(new_table);
  return FALSE;
}

static int
hashmap_init(hashmap_t* const restrict map, va_list args) {
  (void)args; /* no arguments supported at present */

  assert(is_nonnull(map->hash_func));
  assert(is_nonnull(map->compare_func));

  const size_t capacity = HASHMAP_CAPACITY_MIN;
  hashmap_table_t* const restrict table = hashmap_table_alloc(capacity);
  if (is_null(table)) {
    return FAILURE(ENOMEM);
  }

  map->instance = table;

  return SUCCESS;
}

static int
hashmap_dispose(hashmap_t* const restrict map) {
  hashmap_table_t* const restrict table = map->instance;

  if (is_nonnull(table)) {
    hashmap_table_free(table, map->free_key_func, map->free_value_func);
    map->instance = NULL;
  }

  return SUCCESS;
}

static int
hashmap_clear(hashmap_t* const restrict map) {
  hashmap_table_t* const restrict old_table = map->instance;
  hashmap_table_t* const restrict new_table = hashmap_table_alloc(HASHMAP_CAPACITY_MIN);

  map->instance = new_table;
  hashmap_table_free(old_table, map->free_key_func, map->free_value_func);

  return SUCCESS;
}

static bool
hashmap_lookup(hashmap_t* const restrict map,
               const void* const restrict key,
               void** const restrict value) {
  const hash_t hash = map->hash_func(key);
  const compare_func_t compare_func = map->compare_func;

  const hashmap_table_t* const restrict table = map->instance;
  assert(is_nonnull(table));

  for (size_t index = hash & (table->capacity - 1); index < table->capacity; index++) {
    const hashmap_entry_t* const restrict entry = &table->entries[index];

    if (is_null(entry->key)) {
      break;
    }

    if (entry->key == key || (entry->hash == hash && compare_func(entry->key, key) == COMPARE_EQ)) {
#if 0
      fprintf(stderr, "hashmap_lookup: element=%p found at index=%zu (hash=%lu)\n", key, index, (uint64_t)hash);
#endif
      if (is_nonnull(value)) {
        *value = (void*)entry->value;
      }
      return TRUE;  /* element found */
    }
  }

  if (is_nonnull(value)) {
    *value = NULL;
  }
  return FALSE; /* element not found in map */
}

static long
hashmap_count(hashmap_t* const restrict map,
              const void* const restrict key) {
  const hashmap_table_t* const restrict table = map->instance;
  assert(is_nonnull(table));

  if (is_null(key)) {
    return table->count;
  }

  return hashmap_lookup(map, key, NULL) ? 1 : 0;
}

static int
hashmap_insert(hashmap_t* const restrict map,
               const void* const restrict key,
               const void* const restrict value) {
  const hash_t hash = map->hash_func(key);
  const compare_func_t compare_func = map->compare_func;

retry:;
  hashmap_table_t* const restrict table = map->instance;
  assert(is_nonnull(table));

  for (size_t index = hash & (table->capacity - 1); index < table->capacity; index++) {
    hashmap_entry_t* const restrict entry = &table->entries[index];

    if (is_null(entry->key)) {
      entry->hash  = hash;
      entry->key   = key;
      entry->value = value;
      table->count++;
#if 0
      fprintf(stderr, "hashmap_insert: element=%p inserted at index=%zu (hash=%lu)\n", key, index, (uint64_t)hash);
#endif
      return TRUE; /* element inserted into map */
    }

    if (entry->key == key || (entry->hash == hash && compare_func(entry->key, key) == COMPARE_EQ)) {
      return FALSE; /* element already in map */
    }
  }

  size_t new_capacity = table->capacity;
  while (!hashmap_resize(map, new_capacity *= 2))
    ; /* grow the capacity until the resize succeeds */
  goto retry;
  return FAILURE(ENOMEM);
}

static int
hashmap_remove(hashmap_t* const restrict map,
               const void* const restrict key) {
  const hash_t hash = map->hash_func(key);
  const compare_func_t compare_func = map->compare_func;

  hashmap_table_t* const restrict table = map->instance;
  assert(is_nonnull(table));

  for (size_t index = hash & (table->capacity - 1); index < table->capacity; index++) {
    hashmap_entry_t* const restrict entry = &table->entries[index];

    if (is_null(entry->key)) {
      break;
    }

    if (entry->key == key || (entry->hash == hash && compare_func(entry->key, key) == COMPARE_EQ)) {
      hashmap_entry_dispose(entry, map->free_key_func, map->free_value_func);
      table->count--;
#if 0
      fprintf(stderr, "hashmap_remove: element=%p removed at index=%zu (hash=%lu)\n", key, index, (uint64_t)hash);
#endif
      return TRUE; /* element removed from map */
    }
  }

  return FALSE; /* element not found in map */
}

public const class_t hashmap_class = {
  .name    = "hashmap",
  .super   = &map_class,
  .vtable  = &hashmap_vtable.base,
};

public const map_vtable_t hashmap_vtable = {
  .base    = {.klass = &hashmap_class},
  .init    = hashmap_init,
  .dispose = hashmap_dispose,
  .clear   = hashmap_clear,
  .count   = hashmap_count,
  .lookup  = hashmap_lookup,
  .insert  = hashmap_insert,
  .remove  = hashmap_remove,
};

public int
hashmap_iter_init(map_iter_t* const restrict iter,
                  map_t* const restrict map) {
  assert(is_nonnull(iter));
  assert(is_nonnull(map));

  bzero(iter, sizeof(*iter));

  iter->map  = map;
  iter->data = UINT_TO_PTR(0);

  return SUCCESS;
}

public int
hashmap_iter_dispose(map_iter_t* const restrict iter) {
  assert(is_nonnull(iter));

  return SUCCESS;
}

public bool
hashmap_iter_next(map_iter_t* const restrict iter,
                  void** key,
                  void** value) {
  assert(is_nonnull(iter));

  const hashmap_table_t* const restrict table = iter->map->instance;
  assert(is_nonnull(table));

  for (size_t index = PTR_TO_UINT(iter->data); index < table->capacity; index++) {
    const hashmap_entry_t* const restrict entry = &table->entries[index];
#if 0
    fprintf(stderr, "hashmap_iter_next: index=%zu/%zu entry->key=%p entry->hash=%lu\n",
      index, table->capacity - 1, entry->key, (uint64_t)entry->hash);
#endif
    if (is_nonnull(entry->key)) {
      iter->position++;
      iter->key   = (void*)entry->key;
      iter->value = (void*)entry->value;
      if (is_nonnull(key)) {
        *key = (void*)entry->key;
      }
      if (is_nonnull(value)) {
        *value = (void*)entry->value;
      }
      iter->data = UINT_TO_PTR(index + 1);
      return TRUE;
    }
  }

  iter->data = UINT_TO_PTR(table->capacity);
  return FALSE;
}

public int
hashmap_iter_remove(map_iter_t* const restrict iter) {
  assert(is_nonnull(iter));

  hashmap_table_t* const restrict table = iter->map->instance;
  assert(is_nonnull(table));

  const size_t index = PTR_TO_UINT(iter->data);

  if (is_zero(index)) {
    return FAILURE(EPERM); /* iteration not yet begun */
  }

  if (index > table->capacity) {
    return FAILURE(EPERM); /* iteration already ended */
  }

  hashmap_entry_t* const restrict entry = &table->entries[index - 1];
  assert(is_nonnull(entry->key));

  hashmap_entry_dispose(entry, iter->map->free_key_func, iter->map->free_value_func);
  table->count--;

  iter->key = NULL;

  return SUCCESS;
}
