#include <cstdint>
#include <cstdio>
#include <cstddef>
#include <cstdlib>
#include <mockstar/fuzzer.h>

void
fuzz_json_data(const char *data, size_t size) {
  fwrite(data, 1, size, stdout);
  fwrite("\n", 1, 1, stdout);
}

uint64_t
fuzz_get_random() {
  return (uint64_t)std::rand();
}
