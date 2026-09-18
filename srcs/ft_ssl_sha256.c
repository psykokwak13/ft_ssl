#include "../includes/ft_ssl.h"

#define CH(E, F, G) (((E) & (F)) ^ (~(E) & (G)))
#define MAJ(A, B, C) (((A) & (B)) ^ ((A) & (C)) ^ ((B) & (C)))
#define SHR(x, s) ((x) >> (s))

char *sha256_to_hex(sha256_context value) // !!! printf
{
    uint32_t    regs[8] = {value.a, value.b, value.c, value.d, value.e, value.f, value.g, value.h};
    char        *result;
    int         pos = 0;

    result = malloc(65);
    if (!result)
        return (NULL);

    for (int r = 0; r < 4; r++)
    {
        for (int i = 0; i < 4; i++)
        {
            unsigned char byte = (regs[r] >> (8 * i)) & 0xFF;
            sprintf(result + pos, "%02x", byte);
            pos += 2;
        }
    }
    result[32] = '\0';
    return (result);
}

char    *ft_ssl_sha256(char *str) {
    size_t          len;
    unsigned char   *message = md5_sha256_pad(str, strlen(str), &len, SHA256_HASH);
    sha256_context  initial_value = {0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a, };
    static const    uint32_t k[64] = {
        0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
        0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
        0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
        0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
        0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13, 0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
        0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
        0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
        0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208, 0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
    };

    for (int nb_blocs = 0; nb_blocs < len; nb_blocs += 64) {
        sha256_context  haching_var = initial_value;
        uint32_t        *w = get_words(message, nb_blocs, SHA256_HASH);
        uint32_t        s0;
        uint32_t        s1;
        uint32_t        temp0;
        uint32_t        temp1;
        uint32_t        ch;
        uint32_t        maj;

        for (int i = 16; i < 64; i++) {
            s0 = rotr(w[i - 15], 7) ^ rotr(w[i - 15], 18) ^ SHR(w[i - 15], 3);
            s1 = rotr(w[i - 2], 17) ^ rotr(w[i - 2], 19) ^ SHR(w[i - 2], 10);
            w[i] = w[i - 16] + s0 + w[i - 7] + s1;
        }

        for (int i = 0; i < 64; i++) {
            s1 = rotr(haching_var.e, 6) ^ rotr(haching_var.e, 11) ^ rotr(haching_var.e, 25);
            ch = CH(haching_var.e, haching_var.f, haching_var.g);
            temp0 = haching_var.h + s1 + ch + k[i] + w[i];
            s0 = rotr(haching_var.a, 2) ^ rotr(haching_var.a, 13) ^ rotr(haching_var.a, 22);
            maj = MAJ(haching_var.a, haching_var.b, haching_var.c);
            temp1 = s0 + maj;

            haching_var.h = haching_var.g;
            haching_var.g = haching_var.f;
            haching_var.f = haching_var.e;
            haching_var.e = haching_var.d + temp0;
            haching_var.d = haching_var.c;
            haching_var.c = haching_var.b;
            haching_var.b = haching_var.a;
            haching_var.a = temp0 + temp1;
        }
        initial_value.a += haching_var.a;
        initial_value.b += haching_var.b;
        initial_value.c += haching_var.c;
        initial_value.d += haching_var.d;
        initial_value.e += haching_var.e;
        initial_value.f += haching_var.f;
        initial_value.g += haching_var.g;
        initial_value.h += haching_var.h;

        free(w);
    }
}