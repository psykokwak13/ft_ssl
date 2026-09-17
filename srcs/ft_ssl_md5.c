#include "../includes/ft_ssl.h"

#define F(X, Y, Z) (((X) & (Y)) | ((~(X)) & (Z)))
#define G(X, Y, Z) (((X) & (Z)) | (Y & (~(Z))))
#define H(X, Y, Z) ((X) ^ (Y) ^ (Z))
#define I(X, Y, Z) ((Y) ^ ((X) | (~(Z))))
#define TO_I32(x,i) (((uint32_t)(x)[i]) | ((uint32_t)(x)[i+1]<<8) | ((uint32_t)(x)[i+2]<<16) | ((uint32_t)(x)[i+3]<<24))

uint32_t rotl(uint32_t x, int s) {
    return (x << s) | (x >> (32 - s));
}

uint32_t *get_words(unsigned char *message, int nb_bloc) {
    uint32_t    *words = malloc(sizeof(uint32_t) * 16);
    int         x = 0;

    for (int i = 0; i < 64; i += 4) {
        words[x] = TO_I32(message, i + nb_bloc);
        x++;
    }

    return (words);
}

unsigned char *md5_pad(const char *msg, size_t len, size_t *out_len) // a revoir
{
    size_t          total;
    uint64_t        bits;
    unsigned char   *buf;

    total = ((len + 8) / 64 + 1) * 64;

    buf = calloc(total, 1);
    if (!buf)
        return (NULL);

    memcpy(buf, msg, len);
    buf[len] = 0x80;
    bits = (uint64_t)len * 8;

    for (int i = 0; i < 8; i++)
        buf[total - 8 + i] = (unsigned char)(bits >> (8 * i));
    *out_len = total;

    return (buf);
}

char *md5_to_hex(uint32_t h0, uint32_t h1, uint32_t h2, uint32_t h3) // !!! printf
{
    uint32_t    regs[4] = {h0, h1, h2, h3};
    char        *result;
    int         pos = 0;

    result = malloc(33);
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

char    *ft_ssl_md5(char *str) {
    size_t          len;
    char            result[32]; // 0 to f | concatener a, b, c et d
    unsigned char   *message = md5_pad(str, strlen(str), &len);

    if (!message) return (NULL);

    uint32_t     h0 = 0x67452301;
    uint32_t     h1 = 0xefcdab89;
    uint32_t     h2 = 0x98badcfe;
    uint32_t     h3 = 0x10325476;
    uint32_t     k[64];

    for (int i = 0; i < 64; i++) {
        k[i] = (uint32_t)(fabs(sin(i + 1.0)) * 4294967296.0);
    }

    int r[64] = {7, 12, 17, 22,  7, 12, 17, 22,  7, 12, 17, 22,  7, 12, 17, 22, 
                 5, 9, 14, 20,  5, 9, 14, 20,  5, 9, 14, 20,  5, 9, 14, 20,
                 4, 11, 16, 23,  4, 11, 16, 23,  4, 11, 16, 23,  4, 11, 16, 23,
                 6, 10, 15, 21,  6, 10, 15, 21,  6, 10, 15, 21,  6, 10, 15, 21};

    // faire la boucle principale
    // faire la division des blocs 512 en 16 blocs de 32

    for (int nb_bloc = 0; nb_bloc < len; nb_bloc += 64) { // parcourir les blocs
        uint32_t    *value = get_words(message, nb_bloc);
        md5_context haching_var = {h0, h1, h2, h3};
        uint32_t    f;
        int         g;

        for (int i = 0; i < 64; i++) {
            if (i <= 15) {
                f = F(haching_var.b, haching_var.c ,haching_var.d);
                g = i;
            }
            else if (i <= 31) {
                f = G(haching_var.b, haching_var.c, haching_var.d);
                g = (5 * i + 1) % 16;
            }
            else if (i <= 47) {
                f = H(haching_var.b, haching_var.c, haching_var.d);
                g = (3 * i + 5) % 16;
            }
            else if (i <= 63) {
                f = I(haching_var.b, haching_var.c, haching_var.d);
                g = (7 * i) % 16;
            }

            uint32_t    temp = haching_var.d;

            haching_var.d = haching_var.c;
            haching_var.c = haching_var.b;
            haching_var.b = rotl((haching_var.a + f + k[i] + value[g]), r[i]) + haching_var.b;
            haching_var.a = temp;
        }

        h0 += haching_var.a;
        h1 += haching_var.b;
        h2 += haching_var.c;
        h3 += haching_var.d;

        free(value);
    }

    free(message);

    return (md5_to_hex(h0, h1, h2, h3));
}