/* This is free and unencumbered software released into the public domain. */

#ifndef _CPRIME_NULLSEQ_H
#define _CPRIME_NULLSEQ_H

#ifdef __cplusplus
extern "C" {
#endif

static int
nullseq_init(nullseq_t* const seq, va_list args) {
  (void)seq, (void)args;
  return SUCCESS;
}

static int
nullseq_reset(nullseq_t* const seq) {
  (void)seq;
  return SUCCESS;
}

static int
nullseq_clear(nullseq_t* const seq) {
  (void)seq;
  return SUCCESS;
}

static long
nullseq_count(nullseq_t* const restrict seq,
              const void* const restrict elt) {
  (void)seq, (void)elt;
  return 0; // the sequence is empty
}

static bool
nullseq_lookup(nullseq_t* const restrict seq,
               const void* const restrict elt) {
  (void)seq, (void)elt;
  return FALSE; // element not found
}

static int
nullseq_insert(nullseq_t* const restrict seq,
               const void* const restrict elt) {
  (void)seq, (void)elt;
  return FAILURE(ENOTSUP); // operation not supported
}

static int
nullseq_remove(nullseq_t* const restrict seq,
               const void* const restrict elt) {
  (void)seq, (void)elt;
  return FAILURE(ENOTSUP); // operation not supported
}

static int
nullseq_replace(nullseq_t* const restrict seq,
                const void* const restrict elt1,
                const void* const restrict elt2) {
  (void)seq, (void)elt1, (void)elt2;
  return FAILURE(ENOTSUP); // operation not supported
}

/**
 * The canonical immutable empty sequence.
 */
const seq_vtable_t nullseq_vtable = {
  .super   = NULL,
  .name    = "nullseq",
  .init    = nullseq_init,
  .reset   = nullseq_reset,
  .clear   = nullseq_clear,
  .length  = NULL,
  .count   = nullseq_count,
  .lookup  = nullseq_lookup,
  .insert  = nullseq_insert,
  .remove  = nullseq_remove,
  .replace = nullseq_replace,
  .reverse = NULL,
  .sort    = NULL,
};

#ifdef __cplusplus
}
#endif

#endif /* _CPRIME_NULLSEQ_H */
