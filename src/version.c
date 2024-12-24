#include <stdint.h>
#include "config.h"
#include "mockstar/version.h"
#include "mockstar/internal/utility.h"

const char *version() {
    return PROJECT_VER;
}

uint32_t ver_major() {
    return to_uint32(PROJECT_VER_MAJOR);
}

uint32_t ver_minor() {
    return to_uint32(PROJECT_VER_MINOR);
}

uint32_t ver_patch() {
    return to_uint32(PROJECT_VER_PATCH);
}
