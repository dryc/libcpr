/* This is free and unencumbered software released into the public domain. */

#ifndef CPR_MODULE_H
#define CPR_MODULE_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h> /* for bool */

/**
 * Determines whether libcpr includes a given module.
 */
bool cpr_module_exists(const char* module_name);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* CPR_MODULE_H */
