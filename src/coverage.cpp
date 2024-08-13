#include <cstdint>
#include <cstdio>
#include <cstddef>
#include <cstdlib>
#include <cstdint>
#include <cstring>
#include <mockstar/coverage.h>

uint64_t
init_coverage_module(uint64_t edge_count, const char *symtable) {
  char result[100];
  snprintf(result, sizeof(result), "INIT_COVERAGE_MODULE(%llu, %s)\n", (unsigned long long)edge_count, symtable);
  size_t lx = strlen(result);
  fwrite(result, 1, lx, stdout);
  return 0;
}

void
notify_coverage(uint64_t edge) {
  char result[100];
  snprintf(result, sizeof(result), "NOTIFY_COVERAGE(%llu)\n", (unsigned long long)edge);
  size_t lx = strlen(result);
  fwrite(result, 1, lx, stdout);
}
