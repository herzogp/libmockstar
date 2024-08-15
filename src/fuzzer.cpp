#include <cstdbool>
#include <cstdint>
#include <cstdio>
#include <cstddef>
#include <cstdlib>
#include <cstdint>
#include <cstring>
#include <mockstar/fuzzer.h>
#include <mockstar/internal/utility.h>

void
fuzz_json_data(const char *data, size_t size) {
  char payload[1000];
  txtfit(payload, data, sizeof(payload));
  size_t payload_len = strlen(payload);

  char message_prefix[100];
  bool did_truncate = (size > payload_len) ? true : false;
  if (did_truncate) {
      snprintf(message_prefix, sizeof(message_prefix), "FUZZ_JSON_DATA(%lld of %lld bytes): ", (unsigned long long)payload_len, (unsigned long long)size);
  } else {
      snprintf(message_prefix, sizeof(message_prefix), "FUZZ_JSON_DATA(%lld bytes): ", (unsigned long long)payload_len);
  }
  size_t lx = strlen(message_prefix);
  fwrite(message_prefix, 1, lx, stdout);
  fwrite(payload, 1, payload_len, stdout);

  if (did_truncate) {
      fwrite(" ...", 1, 4, stdout);
  }
  fwrite("\n", 1, 1, stdout);
  return;
}

uint64_t
fuzz_get_random() {
  return (uint64_t)std::rand();
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
