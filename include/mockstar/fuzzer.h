#ifndef MOCKSTAR_FUZZER_H
#define MOCKSTAR_FUZZER_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif
void fuzz_json_data(const char *data, size_t size);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
uint64_t fuzz_get_random();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void fuzz_set_source_name(const char *name);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void fuzz_flush();
#ifdef __cplusplus
}
#endif

#endif
