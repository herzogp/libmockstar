#ifndef MOCKSTAR_INTERNAL_UTILITY_H
#define MOCKSTAR_INTERNAL_UTILITY_H

#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

size_t aligned8(size_t n);
const char *txtstart(const char *cp1, size_t *sz);
void txtfit(char *dest, const char *src, size_t max_chars);
uint32_t to_uint32(const char *s);

#ifdef __cplusplus
}
#endif

#endif
