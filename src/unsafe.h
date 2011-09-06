/* This is free and unencumbered software released into the public domain. */

#ifndef _CPRIME_UNSAFE_H
#define _CPRIME_UNSAFE_H

#ifdef __cplusplus
extern "C" {
#endif

/* <cprime/box.h> */
#define box_size(b)             (((box_t*)b)->vtable->klass.size)
#define box_clear(b)            (((box_t*)b)->vtable->clear(b))
#define box_hash(b)             (((box_t*)b)->vtable->hashable.hash(b))
#define box_compare(b1, b2)     (((box_t*)b1)->vtable->comparable.compare(b1, b2))
#define box_equal(b1, b2)       (((box_t*)b1)->vtable->comparable.compare(b1, b2) == 0)

/* <cprime/map.h> */
#define map_clear(s)            (((map_t*)s)->vtable->clear(s))
#define map_count(s, k)         (((map_t*)s)->vtable->count(s, k))
#define map_lookup(s, k, v)     (((map_t*)s)->vtable->lookup(s, k, v))
#define map_insert(s, k, v)     (((map_t*)s)->vtable->insert(s, k, v))
#define map_remove(s, k)        (((map_t*)s)->vtable->remove(s, k))

/* <cprime/seq.h> */
#define seq_clear(s)            (((seq_t*)s)->vtable->clear(s))
#define seq_length(s)           (((seq_t*)s)->vtable->length(s))
#define seq_count(s, e)         (((seq_t*)s)->vtable->count(s, e))
#define seq_lookup(s, e)        (((seq_t*)s)->vtable->lookup(s, e))
#define seq_insert(s, e)        (((seq_t*)s)->vtable->insert(s, e))
#define seq_remove(s, e)        (((seq_t*)s)->vtable->remove(s, e))
#define seq_replace(s, e1, e2)  (((seq_t*)s)->vtable->replace(s, e1, e2))
#define seq_reverse(s)          (((seq_t*)s)->vtable->reverse(s))
#define seq_sort(s, h)          (((seq_t*)s)->vtable->sort(s, h))

/* <cprime/set.h> */
#define set_clear(s)            (((set_t*)s)->vtable->clear(s))
#define set_count(s, e)         (((set_t*)s)->vtable->count(s, e))
#define set_lookup(s, e)        (((set_t*)s)->vtable->lookup(s, e))
#define set_insert(s, e)        (((set_t*)s)->vtable->insert(s, e))
#define set_remove(s, e)        (((set_t*)s)->vtable->remove(s, e))
#define set_replace(s, e1, e2)  (((set_t*)s)->vtable->replace(s, e1, e2))

#ifdef __cplusplus
}
#endif

#endif /* _CPRIME_UNSAFE_H */
