#include "../includes/ft_ssl_md5.h"
#include <stdio.h>
#include <string.h>

void    get_arr_debug(char **arr) {
    for (int i = 0; arr[i]; i++) {
        printf("[%s]", arr[i]);
    }
    putchar('\n');
}

void    print_data_statut(hashing_data data) {
  printf("HASHING DATA STATUS :\n \
            hashingtype (0 = md5 / 1 = sha256) : %d\n\
            echo_mode : %d\n\
            quiet_mode : %d\n\
            reverse_format : %d\n\
            print_mode : %d\n\
            str :",
         data.type, data.echo_mode, data.quiet_mode, data.reverse_format,
         data.print_mode);
  get_arr_debug(data.arr);
}

bool    get_flags(char **arr, hashing_data *data) {
    size_t i = 1;

    if (!strcmp(arr[i], "md5")) data->type = MD5_HASH;
    else if (!strcmp(arr[i], "sha256")) data->type = SHA256_HASH;
    else {
        eprintf("usage : ft_ssl command [flags] [file/string]\n");
        return (false);
    }

    while (arr[(++i) + 1]) {
        if (arr[i][0] != '-') break ;
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
                data->print_mode = true;
                break ;
            default :
                eprintf("invalid flag : %s\n", arr[i]);
                return (false);
        }
    }

    if (data->print_mode && arr[i])
        data->arr[0] = arr[i++];
    if (arr[i]) {
        data->stream = fopen(arr[i], "r");
        if (!data->stream) {
            eprintf("ft_ssl : %s: No such file or directory\n", arr[i]);
            return (false);
        }
    }
    if (!arr[i] || data->echo_mode)
        data->read_stdin = true;

    return (true);
}


int main(int argc, char **argv) {
    if (argc < 2) {
        eprintf("usage : ft_ssl command [flags] [file/string]\n");
        return (1);
    }

    hashing_data data = {0};
    data.arr[0] = NULL;

    if (!get_flags(argv, &data)) return (1);
    if (!ft_ssl_md5(&data)) return (1);

    printf("\n-----------\n");
    print_data_statut(data);

    if (data.stream) fclose(data.stream);

    return (0);
}
