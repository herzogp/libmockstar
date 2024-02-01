// #include <stdio.h>
#include <cstdio>
#include <cstddef>
#include <cstdint>
#include <mockstar/fuzzer.h>

void
fuzz_json_data(const char *data, size_t size) {
  fwrite(data, 1, size, stdout);
  fwrite("\n", 1, 1, stdout);
}

uint64_t
fuzz_get_random() {
  static uint64_t i = 20;
  if (i > 79) {
    i = 20;
  }
  return i++;
}

void
fuzz_set_source_name(const char *name) {
  fwrite("SET SOURCE NAME: ", 17, 1, stdout);
  int lx = 0;
  const char *cp1 = name;
  while (*cp1++) lx++;
  fwrite(name, lx, 1, stdout);
  fwrite("\n", 1, 1, stdout);
  return;
}

void
fuzz_flush() {
  fwrite("FLUSH\n", 6, 1, stdout);
}
