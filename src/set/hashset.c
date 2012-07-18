/* This is free and unencumbered software released into the public domain. */

#include "build.h"
#include "set/hashset.h"

static inline void
hashset_entry_dispose(hashset_entry_t* const restrict entry,
                      const free_func_t free_elt_func) {
  if (is_nonnull(entry->elt)) {
    if (is_nonnull(free_elt_func)) {
      free_elt_func((void*)entry->elt);
    }
    entry->hash = 0;
    entry->elt  = NULL;
  }
}

static inline size_t
hashset_table_size(const size_t capacity) {
  return sizeof(hashset_table_t) + (capacity * sizeof(hashset_entry_t));
}

static inline hashset_table_t*
hashset_table_alloc(const size_t capacity) {
  hashset_table_t* const restrict table = calloc(1, hashset_table_size(capacity));
  if (is_nonnull(table)) {
    table->capacity = capacity;
  }
  return table;
}

static inline void
hashset_table_free(hashset_table_t* const restrict table,
                   const free_func_t free_elt_func) {
  if (is_nonnull(table)) {
    if (is_nonnull(free_elt_func)) {
      for (size_t index = 0; index < table->capacity; index++) {
        const hashset_entry_t* const restrict entry = &table->entries[index];
        if (is_nonnull(entry->elt)) {
          free_elt_func((void*)entry->elt);
        }
      }
    }
    free(table);
  }
}

static bool
hashset_resize(hashset_t* const restrict set,
               const size_t capacity) {
  hashset_table_t* const restrict old_table = set->instance;
  hashset_table_t* const restrict new_table = hashset_table_alloc(capacity);
  assert(is_nonnull(new_table));

  new_table->count = old_table->count;

  for (size_t old_index = 0; old_index < old_table->capacity; old_index++) {
    const hashset_entry_t* const restrict old_entry = &old_table->entries[old_index];
    if (is_null(old_entry->elt))
      continue; /* skip unused entries */

    size_t new_index = old_entry->hash & (new_table->capacity - 1);
    for (; new_index < new_table->capacity; new_index++) {
      hashset_entry_t* const restrict new_entry = &new_table->entries[new_index];
      if (is_null(new_entry->elt)) {
        new_entry->elt  = old_entry->elt;
        new_entry->hash = old_entry->hash;
        break;
      }
    }
    if (new_index == new_table->capacity) {
      goto fail;
    }
  }

#if 0
  fprintf(stderr, "hashset_resize: grew table capacity from %zu to %zu entries (count=%zu)\n",
    old_table->capacity, new_table->capacity, old_table->count);
#endif
  set->instance = new_table;
  free(old_table);
  return TRUE;

fail:
#if 0
  fprintf(stderr, "hashset_resize: failed to grow table capacity from %zu to %zu entries (count=%zu)\n",
    old_table->capacity, new_table->capacity, old_table->count);
#endif
  free(new_table);
  return FALSE;
}

static int
hashset_init(hashset_t* const restrict set, va_list args) {
  (void)args; /* no arguments supported at present */

  assert(is_nonnull(set->hash_func));
  assert(is_nonnull(set->compare_func));

  const size_t capacity = HASHSET_CAPACITY_MIN;
  hashset_table_t* const restrict table = hashset_table_alloc(capacity);
  if (is_null(table)) {
    return FAILURE(ENOMEM);
  }

  set->instance = table;

  return SUCCESS;
}

static int
hashset_dispose(hashset_t* const restrict set) {
  hashset_table_t* const restrict table = set->instance;

  if (is_nonnull(table)) {
    hashset_table_free(table, set->free_func);
    set->instance = NULL;
  }

  return SUCCESS;
}

static int
hashset_clear(hashset_t* const restrict set) {
  hashset_table_t* const restrict old_table = set->instance;
  hashset_table_t* const restrict new_table = hashset_table_alloc(HASHSET_CAPACITY_MIN);

  set->instance = new_table;
  hashset_table_free(old_table, set->free_func);

  return SUCCESS;
}

static bool
hashset_lookup(hashset_t* const restrict set,
               const void* const restrict elt) {
  const hash_t hash = set->hash_func(elt);
  const compare_func_t compare_func = set->compare_func;

  const hashset_table_t* const restrict table = set->instance;
  assert(is_nonnull(table));

  for (size_t index = hash & (table->capacity - 1); index < table->capacity; index++) {
    const hashset_entry_t* const restrict entry = &table->entries[index];

    if (is_null(entry->elt)) {
      break;
    }

    if (entry->elt == elt || (entry->hash == hash && compare_func(entry->elt, elt) == COMPARE_EQ)) {
#if 0
      fprintf(stderr, "hashset_lookup: element=%p found at index=%zu (hash=%lu)\n", elt, index, (uint64_t)hash);
#endif
      return TRUE;  /* element found */
    }
  }

  return FALSE; /* element not found in set */
}

static long
hashset_count(hashset_t* const restrict set,
              const void* const restrict elt) {
  const hashset_table_t* const restrict table = set->instance;
  assert(is_nonnull(table));

  if (is_null(elt)) {
    return table->count;
  }

  return hashset_lookup(set, elt) ? 1 : 0;
}

static int
hashset_insert(hashset_t* const restrict set,
               const void* const restrict elt) {
  const hash_t hash = set->hash_func(elt);
  const compare_func_t compare_func = set->compare_func;

retry:;
  hashset_table_t* const restrict table = set->instance;
  assert(is_nonnull(table));

  for (size_t index = hash & (table->capacity - 1); index < table->capacity; index++) {
    hashset_entry_t* const restrict entry = &table->entries[index];

    if (is_null(entry->elt)) {
      entry->elt  = elt;
      entry->hash = hash;
      table->count++;
#if 0
      fprintf(stderr, "hashset_insert: element=%p inserted at index=%zu (hash=%lu)\n", elt, index, (uint64_t)hash);
#endif
      return TRUE; /* element inserted into set */
    }

    if (entry->elt == elt || (entry->hash == hash && compare_func(entry->elt, elt) == COMPARE_EQ)) {
      return FALSE; /* element already in set */
    }
  }

  size_t new_capacity = table->capacity;
  while (!hashset_resize(set, new_capacity *= 2))
    ; /* grow the capacity until the resize succeeds */
  goto retry;
  return FAILURE(ENOMEM);
}

static int
hashset_remove(hashset_t* const restrict set,
               const void* const restrict elt) {
  const hash_t hash = set->hash_func(elt);
  const compare_func_t compare_func = set->compare_func;

  hashset_table_t* const restrict table = set->instance;
  assert(is_nonnull(table));

  for (size_t index = hash & (table->capacity - 1); index < table->capacity; index++) {
    hashset_entry_t* const restrict entry = &table->entries[index];

    if (is_null(entry->elt)) {
      break;
    }

    if (entry->elt == elt || (entry->hash == hash && compare_func(entry->elt, elt) == COMPARE_EQ)) {
      hashset_entry_dispose(entry, set->free_func);
      table->count--;
#if 0
      fprintf(stderr, "hashset_remove: element=%p removed at index=%zu (hash=%lu)\n", elt, index, (uint64_t)hash);
#endif
      return TRUE; /* element removed from set */
    }
  }

  return FALSE; /* element not found in set */
}

public const class_t hashset_class = {
  .name    = "hashset",
  .super   = &set_class,
  .vtable  = &hashset_vtable.base,
};

public const set_vtable_t hashset_vtable = {
  .base    = {.klass = &hashset_class},
  .init    = hashset_init,
  .dispose = hashset_dispose,
  .clear   = hashset_clear,
  .count   = hashset_count,
  .lookup  = hashset_lookup,
  .insert  = hashset_insert,
  .remove  = hashset_remove,
  .replace = NULL,
};

public int
hashset_iter_init(set_iter_t* const restrict iter,
                  set_t* const restrict set) {
  assert(is_nonnull(iter));
  assert(is_nonnull(set));

  bzero(iter, sizeof(*iter));

  iter->set  = set;
  iter->data = UINT_TO_PTR(0);

  return SUCCESS;
}

public int
hashset_iter_dispose(set_iter_t* const restrict iter) {
  assert(is_nonnull(iter));

  return SUCCESS;
}

public bool
hashset_iter_next(set_iter_t* const restrict iter,
                  void** elt) {
  assert(is_nonnull(iter));

  const hashset_table_t* const restrict table = iter->set->instance;
  assert(is_nonnull(table));

  for (size_t index = PTR_TO_UINT(iter->data); index < table->capacity; index++) {
    const hashset_entry_t* const restrict entry = &table->entries[index];
#if 0
    fprintf(stderr, "hashset_iter_next: index=%zu/%zu entry->elt=%p entry->hash=%lu\n",
      index, table->capacity - 1, entry->elt, (uint64_t)entry->hash);
#endif
    if (is_nonnull(entry->elt)) {
      iter->position++;
      iter->elt = (void*)entry->elt;
      if (is_nonnull(elt)) {
        *elt = (void*)entry->elt;
      }
      iter->data = UINT_TO_PTR(index + 1);
      return TRUE;
    }
  }

  iter->data = UINT_TO_PTR(table->capacity);
  return FALSE;
}

public int
hashset_iter_remove(set_iter_t* const restrict iter) {
  assert(is_nonnull(iter));

  hashset_table_t* const restrict table = iter->set->instance;
  assert(is_nonnull(table));

  const size_t index = PTR_TO_UINT(iter->data);

  if (is_zero(index)) {
    return FAILURE(EPERM); /* iteration not yet begun */
  }

  if (index >= table->capacity) {
    return FAILURE(EPERM); /* iteration already ended */
  }

  hashset_entry_t* const restrict entry = &table->entries[index - 1];
  assert(is_nonnull(entry->elt));

  hashset_entry_dispose(entry, iter->set->free_func);
  table->count--;

  iter->elt = NULL;

  return SUCCESS;
}
