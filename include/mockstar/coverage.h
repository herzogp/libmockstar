#ifndef MOCKSTAR_COVERAGE_H
#define MOCKSTAR_COVERAGE_H

#include <cstdint>

#ifdef __cplusplus
extern "C" {
#endif
uint64_t init_coverage_module(uint64_t size, const char *data);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void notify_coverage(uint64_t edge);
#ifdef __cplusplus
}
#endif

#endif
