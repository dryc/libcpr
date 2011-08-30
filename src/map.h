/* This is free and unencumbered software released into the public domain. */

#ifndef _CPRIME_MAP_H
#define _CPRIME_MAP_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct map_t {
  void* root;
  hash_func_t hash_func;
  compare_func_t compare_func;
  free_func_t free_key_func;
  free_func_t free_value_func;
} map_t;

#ifdef __cplusplus
}
#endif

#endif /* _CPRIME_MAP_H */
