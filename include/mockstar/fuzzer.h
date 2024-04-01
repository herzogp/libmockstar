#ifndef MOCKSTAR_FUZZER_H
#define MOCKSTAR_FUZZER_H

#ifdef __cplusplus
extern "C" {
#endif
void fuzz_json_data(const char *data, size_t size);
uint64_t fuzz_get_random();
#ifdef __cplusplus
}
#endif

#endif
