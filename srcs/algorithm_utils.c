#include "../includes/ft_ssl.h"

uint32_t    rotl(uint32_t x, int s) {
    return (x << s) | (x >> (32 - s));
}

uint32_t    rotr(uint32_t x, int s) {
    return (x >> s) | (x << (32 - s));
}

uint32_t    *get_words(unsigned char *message, int nb_bloc, hashing_type type) {
    uint32_t    *words = NULL;
    int         x = 0;

    if (type == MD5_HASH)
        words = malloc(sizeof(uint32_t) * 16);
    else if (type == SHA256_HASH)
        words = malloc(sizeof(uint32_t) * 64);

    for (int i = 0; i < 64; i += 4) {
        if (type == MD5_HASH)
            words[x] = TO_I32_LITTLE_ENDIAN(message, i + nb_bloc);
        else if (type == SHA256_HASH)
            words[x] = TO_I32_BIG_ENDIAN(message, i + nb_bloc);
        x++;
    }

    return (words);
}

unsigned char   *md5_sha256_pad(const char *msg, size_t len, size_t *out_len, hashing_type type) { // a revoir
    size_t          total;
    uint64_t        bits;
    unsigned char   *buf;

    total = ((len + 8) / 64 + 1) * 64;

    buf = ft_calloc(total, 1);
    if (!buf)
        return (NULL);

    ft_memcpy(buf, msg, len);
    buf[len] = 0x80;
    bits = (uint64_t)len * 8;

    for (int i = 0; i < 8; i++) {
        if (type == MD5_HASH)
            buf[total - 8 + i] = (unsigned char)(bits >> (8 * i));
        else if (type == SHA256_HASH)
            buf[total - 8 + i] = (unsigned char)(bits >> (8 *(7 - i)));
    }
    *out_len = total;

    return (buf);
}
