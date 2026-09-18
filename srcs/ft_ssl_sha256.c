#include "../includes/ft_ssl.h"

char    *ft_ssl_sha256(char *str) {
    size_t  len;
    unsigned char   *message = md5_sha256_pad(str, strlen(str), &len);