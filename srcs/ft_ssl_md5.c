#include "../includes/ft_ssl_md5.h"
#include <stdio.h>

#define MAX_LEN 1024

char    *message_digest_5(char *str, bool reverse_format) {
    
}

bool    ft_ssl_md5(hashing_data *data) {
    char    result[MAX_LEN], *buffer;
    size_t  i = 1;

    if (data->stream) {
        buffer = fgets(result, MAX_LEN, data->stream);
        data->arr[i++] = buffer;
    }
    if (data->read_stdin) {
        buffer = fgets(result, MAX_LEN, stdin);
        data->arr[i] = buffer;
    }

    for (int i = 0; data->arr[i]; i++) {
        data->arr[i] = message_digest_5(data->arr[i], data->reverse_format);
    }
    return (true);
}