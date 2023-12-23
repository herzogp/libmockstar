// #include <stdio.h>
#include <cstdio>
#include <cstddef>
#include <mockstar/fuzzer.h>

void
fuzz_json_data(const char *data, size_t size) {
  fwrite(data, 1, size, stdout);
  fwrite("\n", 1, 1, stdout);
}
