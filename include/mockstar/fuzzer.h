#ifndef MOCKSTAR_FUZZER_H
#define MOCKSTAR_FUZZER_H

#ifdef __cplusplus
extern "C" {
#endif
void fuzz_json_data(const char *data, size_t size);
#ifdef __cplusplus
}
#endif

#endif
