#ifndef FT_SSL_MD5_H

#define FT_SSL_MD5_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>

#define eprintf(...) fprintf (stderr, __VA_ARGS__)

typedef enum {
    MD5_HASH,
    SHA256_HASH
} hashing_type;

typedef struct {
    hashing_type type;
    bool echo_mode;
    bool quiet_mode;
    bool reverse_format;
    bool print_sum;

    char *str;
} hashing_data;

#endif