/* This is free and unencumbered software released into the public domain. */

#ifndef _CPRIME_MEMORY_H
#define _CPRIME_MEMORY_H

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __GNUC__
#
#  define bcmp    __builtin_bcmp
#  define bcopy   __builtin_bcopy
#  define bzero   __builtin_bzero
#  define strcmp  __builtin_strcmp
#  define strdup  __builtin_strdup
#  define strlen  __builtin_strlen
#  define strncmp __builtin_strncmp
#  define strndup __builtin_strndup
#
#else /* !__GNUC__ */
#
#  ifdef HAVE_STRINGS_H
#    include <strings.h> /* for bcmp(), bcopy(), bzero() */
#  endif /* HAVE_STRINGS_H */
#
#  ifndef bcmp
#    ifdef memcmp
#      define bcmp(s1, s2, n) memcmp(s1, s2, n)
#    else
#      error You must define a bcmp() macro for your compiler in src/memory.h.
#    endif /* memcmp */
#  endif /* bcmp */
#
#  ifndef bcopy
#    ifdef memmove
#      define bcopy(s1, s2, n) memmove(s2, s1, n)
#    else
#      error You must define a bcopy() macro for your compiler in src/memory.h.
#    endif /* memmove */
#  endif /* bcopy */
#
#  ifndef bzero
#    ifdef memset
#      define bzero(s, n) memset(s, '\0', n)
#    else
#      error You must define a bzero() macro for your compiler in src/memory.h.
#    endif /* memset */
#  endif /* bzero */
#
#  ifdef HAVE_STRING_H
#    include <string.h>  /* for strcmp(), strdup(), strlen(), strncmp(), strndup() */
#  endif /* HAVE_STRING_H */
#
#  ifndef strcmp
#    error You must define an strcmp() macro for your compiler in src/memory.h.
#  endif /* strcmp */
#
#  ifndef strdup
#    error You must define an strdup() macro for your compiler in src/memory.h.
#  endif /* strdup */
#
#  ifndef strlen
#    error You must define an strlen() macro for your compiler in src/memory.h.
#  endif /* strlen */
#
#  ifndef strncmp
#    error You must define an strncmp() macro for your compiler in src/memory.h.
#  endif /* strncmp */
#
#  ifndef strndup
#    error You must define an strndup() macro for your compiler in src/memory.h.
#  endif /* strndup */
#
#endif /* __GNUC__ */

#ifdef __cplusplus
}
#endif

#endif /* _CPRIME_MEMORY_H */
