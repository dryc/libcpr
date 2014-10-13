/* This is free and unencumbered software released into the public domain. */

#ifndef CPR_GENERIC_H
#define CPR_GENERIC_H

/**
 * @file
 *
 * Experimental type-generic operations.
 *
 * These macros rely on the `_Generic()` type-dispatch feature introduced
 * in the C11 standard. This header should not be included when using a
 * compiler that lacks C11 support.
 *
 * @see http://en.wikipedia.org/wiki/C11_(C_standard_revision)
 */

#ifdef __cplusplus
extern "C" {
#endif

////////////////////////////////////////////////////////////////////////////////
/* Macros */

////////////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* CPR_GENERIC_H */
