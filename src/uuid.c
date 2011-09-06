/* This is free and unencumbered software released into the public domain. */

#include "build.h"
#include <arpa/inet.h> /* for htonl(), htons(), ntohl(), ntohs() */
#include <stdio.h>     /* for FILE*, snprintf() */
#include <string.h>    /* for memcmp() */

const class_t uuid_class = {
  .name    = "uuid",
  .super   = NULL,
  .vtable  = NULL, // TODO
};

const uuid_t uuid_null = UUID_INIT;

uuid_t*
uuid_alloc() {
  uuid_t* uuid = malloc(sizeof(uuid_t));
  uuid_init(uuid);
  return uuid;
}

void
uuid_free(uuid_t* const uuid) {
  if (likely(uuid != NULL)) {
    uuid_dispose(uuid);
    free(uuid);
  }
}

uuid_t*
uuid_clone(const uuid_t* const uuid) {
  validate_with_null_return(uuid != NULL);

  uuid_t* copy = malloc(sizeof(uuid_t));
  if (likely(copy != NULL)) {
    uuid_copy(uuid, copy);
  }
  return copy;
}

int
uuid_init(uuid_t* const uuid) {
  return uuid_clear(uuid);
}

int
uuid_dispose(uuid_t* const uuid) {
  validate_with_errno_return(uuid != NULL);

#ifndef NDEBUG
  bzero(uuid, sizeof(uuid_t));
#endif

  return SUCCESS;
}

hash_t
uuid_hash(uuid_t* const uuid) {
  validate_with_zero_return(uuid != NULL);

  char buffer[UUID_LENGTH + 1];
  uuid_serialize(uuid, buffer, sizeof(buffer));
  return str_hash(buffer);
}

int
uuid_compare(const uuid_t* const uuid1, const uuid_t* const uuid2) {
  validate_with_errno_return(uuid1 != NULL && uuid2 != NULL);

  if (unlikely(uuid1 == uuid2))
    return COMPARE_EQ;

  if (uuid1->layout.time_low != uuid2->layout.time_low) {
    return (ntohl(uuid1->layout.time_low) < ntohl(uuid2->layout.time_low)) ?
      COMPARE_LT : COMPARE_GT;
  }

  if (uuid1->layout.time_mid != uuid2->layout.time_mid) {
    return (ntohs(uuid1->layout.time_mid) < ntohs(uuid2->layout.time_mid)) ?
      COMPARE_LT : COMPARE_GT;
  }

  if (uuid1->layout.time_hi_and_version != uuid2->layout.time_hi_and_version) {
    return (ntohs(uuid1->layout.time_hi_and_version) < ntohs(uuid2->layout.time_hi_and_version)) ?
      COMPARE_LT : COMPARE_GT;
  }

  if (uuid1->layout.clock_seq_hi_and_reserved != uuid2->layout.clock_seq_hi_and_reserved) {
    return (uuid1->layout.clock_seq_hi_and_reserved < uuid2->layout.clock_seq_hi_and_reserved) ?
      COMPARE_LT : COMPARE_GT;
  }

  if (uuid1->layout.clock_seq_low != uuid2->layout.clock_seq_low) {
    return (uuid1->layout.clock_seq_low < uuid2->layout.clock_seq_low) ?
      COMPARE_LT : COMPARE_GT;
  }

  return memcmp(uuid1->layout.node, uuid2->layout.node, 6);
}

bool
uuid_equal(const uuid_t* const uuid1, const uuid_t* const uuid2) {
  validate_with_false_return(uuid1 != NULL && uuid2 != NULL);

  if (unlikely(uuid1 == uuid2))
    return TRUE;

  return unlikely(bcmp(uuid1, uuid2, sizeof(uuid_t)) == 0) ? TRUE : FALSE;
}

int
uuid_is_null(const uuid_t* const uuid) {
  validate_with_errno_return(uuid != NULL);

  return unlikely(bcmp(uuid, &uuid_null, sizeof(uuid_t)) == 0) ? TRUE : FALSE;
}

int
uuid_version(const uuid_t* const uuid) {
  validate_with_errno_return(uuid != NULL);

  return ((uuid->layout.time_hi_and_version & 0xF000) >> 12);
}

int
uuid_clear(uuid_t* const uuid) {
  validate_with_errno_return(uuid != NULL);

  bzero(uuid, sizeof(uuid_t));

  return SUCCESS;
}

int
uuid_copy(const uuid_t* const restrict uuid, uuid_t* const restrict copy) {
  validate_with_errno_return(uuid != NULL && copy != NULL);

  bcopy(uuid, copy, sizeof(uuid_t));

  return SUCCESS;
}

int
uuid_serialize(const uuid_t* const restrict uuid, char* const restrict buffer, const size_t buffer_size) {
  validate_with_errno_return(uuid != NULL && buffer != NULL);

  if (unlikely(buffer_size < UUID_LENGTH + 1))
    return FAILURE(EOVERFLOW); // buffer overflow

  return snprintf(buffer, buffer_size, UUID_FORMAT,
    htonl(uuid->layout.time_low),
    htons(uuid->layout.time_mid),
    htons(uuid->layout.time_hi_and_version),
    uuid->layout.clock_seq_hi_and_reserved,
    uuid->layout.clock_seq_low,
    uuid->layout.node[0],
    uuid->layout.node[1],
    uuid->layout.node[2],
    uuid->layout.node[3],
    uuid->layout.node[4],
    uuid->layout.node[5]);
}

int
uuid_print(const uuid_t* const restrict uuid, FILE* const restrict stream) {
  validate_with_errno_return(uuid != NULL && stream != NULL);

  char buffer[UUID_LENGTH + 1];
  const int rc = uuid_serialize(uuid, buffer, sizeof(buffer));
  return unlikely(fputs(buffer, stream) == EOF) ? FAILURE(errno) : rc;
}
