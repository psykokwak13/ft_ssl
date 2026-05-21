#include "../includes/ft_ssl_md5.h"
#include <string.h>

bool get_flags(char **arr, hashing_data *data) {
    size_t i = 1;

    if (!strcmp(arr[i], "md5")) data->type = MD5_HASH;
    else if (!strcmp(arr[i], "sha256")) data->type = SHA256_HASH;
    else {
        eprintf("usage : ft_ssl command [flags] [file/string]\n");
        return (false);
    }

    while (arr[++i]) {
        if (strlen(arr[i]) != 2 || arr[i][0] != '-') {
            eprintf("invalid flag : %s", arr[i]);
            return (false);
        }
        switch (arr[i][1]) {
            case 'p':
                data->echo_mode = true;
                break ;
            case 'q':
                data->quiet_mode = true;
                break ;
            case 'r':
                data->reverse_format = true;
                break ;
            case 's':
                data->print_sum = true;
                break ;
            default :
                eprintf("invalid flag : %s", arr[i]);
                return (false);
        }
    }

    return (true);
}


int main(int argc, char **argv) {
    if (argc < 2) {
        eprintf("usage : ft_ssl command [flags] [file/string]\n");
        return (1);
    }

    hashing_data data = {0};
    if (!get_flags(argv, &data)) return (1);

    return (0);
}
