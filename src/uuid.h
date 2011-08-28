/* This is free and unencumbered software released into the public domain. */

#ifndef _CPRIME_UUID_H
#define _CPRIME_UUID_H

#ifdef __cplusplus
extern "C" {
#endif

#ifdef HAVE_UNISTD_H
#include <unistd.h> /* for uuid_t on Darwin */
#endif /* HAVE_UNISTD_H */

#define UUID_SIZE    16 /* bytes */
#define UUID_LENGTH  36 /* characters */

#ifndef _UUID_T
#define _UUID_T
#include <stdint.h> /* for uint8_t */
typedef struct uuid_t {
  uint8_t data[UUID_SIZE];
} uuid_t;
#endif /* _UUID_T */

/* @see http://en.wikipedia.org/wiki/Universally_unique_identifier */
#define UUID_FORMAT  "%08x-%04x-%04x-%02x%02x-%02x%02x%02x%02x%02x%02x"
#define UUID_PATTERN "^([0-9A-Fa-f]{8})-([0-9A-Fa-f]{4})-([0-9A-Fa-f]{4})-([0-9A-Fa-f]{4})-([0-9A-Fa-f]{12})$"

/**
 * The canonical all-zeroes UUID.
 */
extern const uuid_t uuid_null;

/**
 * Allocates heap memory for a new UUID.
 */
extern uuid_t* uuid_alloc();

/**
 * Releases the heap memory used by a UUID.
 */
extern void uuid_free(uuid_t* uuid);

/**
 * Constructs a heap copy of a UUID.
 */
extern uuid_t* uuid_clone(const uuid_t* uuid);

/**
 * Initializes a stack-allocated UUID.
 */
#define UUID_INIT {.data = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}

/**
 * Initializes a UUID.
 */
extern int uuid_init(uuid_t* uuid);

/**
 * Disposes of a UUID.
 */
extern int uuid_dispose(uuid_t* uuid);

extern bool uuid_equal(const uuid_t* uuid1, const uuid_t* uuid2);

/**
 * Returns `TRUE` if a UUID contains all zeroes.
 */
extern int uuid_is_null(const uuid_t* uuid);

extern int uuid_clear(uuid_t* uuid);

extern int uuid_copy(const uuid_t* restrict uuid,
  uuid_t* restrict copy);

#ifdef __cplusplus
}
#endif

#endif /* _CPRIME_UUID_H */
