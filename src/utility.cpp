#include <ctype.h>
#include <stdbool.h>
#include <stddef.h> // size_t
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "mockstar/internal/utility.h"

// ----------------------------------------------------------------------
// heap allocation helpers
// ----------------------------------------------------------------------
size_t aligned8(size_t n) {
    size_t needs_align = (n & 0x7);
    if (! needs_align) {
        return n;
    }
    size_t aligned_n = ((n >> 3) + 1) << 3;
    return aligned_n;
}

const char *txtstart(const char *cp1, size_t *sz) {
    *sz = 0;
    if (!cp1) {
        return NULL;
    }

    unsigned char c;
    do {
        c = (unsigned char)*cp1;
        if (!isspace(c) || !c) {
            break;
        }
        cp1++;
    } while (c);

    if (!*cp1) {
        return cp1;
    }

    // s points to a non-null character
    const char *cp2 = strrchr(cp1, 0);

    do {
        cp2--;
        c = (unsigned char)*cp2;
    } while (isspace(c));

    *sz = 1 + (size_t)(cp2 - cp1);
    return cp1;
}


void txtfit(char *dest, const char *src, size_t max_chars) {
    if (!dest) {
        return;
    }
    if (!src) {
        max_chars = 0;
    }
    if (max_chars > 0) {
        strncpy(dest, src, max_chars);
    }
    *(dest + max_chars) = '\0';
}

uint32_t to_uint32(const char *s) {
    unsigned long ul_val = strtoul(s, NULL, 10);
    uint32_t val = 0;
    if (ul_val <= UINT32_MAX) {
        val = (uint32_t)ul_val;
    }
    return val;
}
