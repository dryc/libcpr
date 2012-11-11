/* This is free and unencumbered software released into the public domain. */

#ifndef CPRIME_MAP_H
#define CPRIME_MAP_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h> /* for bool */

#define NULLMAP (&nullmap_class)
#define LISTMAP (&listmap_class)
#define TREEMAP (&treemap_class)
#define HASHMAP (&hashmap_class)

/**
 * The base class for map classes.
 */
extern const class_t map_class;
extern const class_t nullmap_class;
extern const class_t listmap_class;
extern const class_t treemap_class;
extern const class_t hashmap_class;

/**
 * Represents a key-value map.
 *
 * @see http://en.wikipedia.org/wiki/Associative_array
 */
typedef struct map_t {
  const struct map_vtable_t* restrict vtable;
  void* instance;
  hash_func_t hash_func;
  compare_func_t compare_func;
  free_func_t free_key_func;
  free_func_t free_value_func;
} map_t;

typedef map_t nullmap_t;
typedef map_t listmap_t;
typedef map_t treemap_t;
typedef map_t hashmap_t;

/**
 * Represents a map's virtual dispatch table.
 *
 * @see http://en.wikipedia.org/wiki/Virtual_method_table
 */
typedef struct map_vtable_t {
  const vtable_t base;
  const hashable_vtable_t hashable;
  const comparable_vtable_t comparable;
  const iterable_vtable_t iterable;
  int (*init)(map_t* map, va_list args);
  int (*dispose)(map_t* map);
  int (*clear)(map_t* map);
  long (*count)(map_t* restrict map,
    const void* restrict key);
  bool (*lookup)(map_t* restrict map,
    const void* restrict key,
    void** restrict value);
  int (*insert)(map_t* restrict map,
    const void* restrict key,
    const void* restrict value);
  int (*remove)(map_t* restrict map,
    const void* restrict key);
} map_vtable_t;

extern const map_vtable_t nullmap_vtable;
extern const map_vtable_t listmap_vtable;
extern const map_vtable_t treemap_vtable;
extern const map_vtable_t hashmap_vtable;

/**
 * Allocates heap memory for a new map.
 */
extern map_t* map_alloc();

/**
 * Releases the heap memory used by a map.
 */
extern void map_free(map_t* map);

/**
 * Initializes a map.
 */
extern int map_init(map_t* map,
  const class_t* klass,
  const hash_func_t hash_func,
  const compare_func_t compare_func,
  const free_func_t free_key_func,
  const free_func_t free_value_func, ...);

/**
 * Resets a map back to an uninitialized state.
 */
extern int map_dispose(map_t* map);

/**
 * Removes all key-value pairs from a map.
 */
extern int map_clear(map_t* map);

/**
 * Checks whether a map contains any key-value pairs.
 */
extern bool map_is_empty(map_t* map);

/**
 * Returns the number of key-value pairs in a map.
 */
extern long map_count(map_t* map,
  const void* key);

/**
 * Looks up a key-value pair in a map.
 */
extern bool map_lookup(map_t* map,
  const void* restrict key,
  void** restrict value);

/**
 * Inserts a given key-value pair into a map.
 */
extern int map_insert(map_t* map,
  const void* restrict key,
  const void* restrict value);

/**
 * Removes a given key-value pair from a map.
 */
extern int map_remove(map_t* map,
  const void* key);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* CPRIME_MAP_H */
