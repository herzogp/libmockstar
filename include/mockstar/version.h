#ifndef MOCKSTAR_VERSION_H
#define MOCKSTAR_VERSION_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif
const char* version();
uint32_t ver_major();
uint32_t ver_minor();
uint32_t ver_patch();

#ifdef __cplusplus
}
#endif

#endif
