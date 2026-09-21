#include "../includes/ft_ssl.h"
#include <stdio.h>
#include <string.h>

bool    get_flags(char **arr, int size, hashing_data *data) {
    size_t  i = 1;

    if (!ft_strcmp(arr[i], "md5")) data->type = MD5_HASH;
    else if (!ft_strcmp(arr[i], "sha256")) data->type = SHA256_HASH;
    else {
        print_data_statut(*data);
        eprintf("usage : ft_ssl command [flags] [file/string]\n");
        return (false);
    }
    i++;

    for (; arr[i] && arr[i][0] == '-'; i++) {
        if (arr[i][0] != '-') break ;
        if (ft_strlen(arr[i]) != 2) {
            eprintf("invalid command '%s'\n", arr[i]);
            return (false) ;
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
                data->print_mode = true;
                break ;
            default :
                eprintf("invalid command : %s\n", arr[i]);
                return (false);
        }
    }

    if (!arr[i] || data->echo_mode) {
        if (!handle_stdin(data))
            return false;
    }

    if (data->print_mode) {
        if (!arr[i]) {
            eprintf("error : '-s' command without string\n");
            return (false);
        }
        add_source(data, SRC_STRING, ft_strdup(arr[i++]));
    }

    for (; arr[i] ;i++)
        add_source(data, SRC_FILE, ft_strdup(arr[i]));

    return (true);
}


int main(int argc, char **argv) {
    if (argc < 2) {
        eprintf("usage : ft_ssl command [flags] [file/string]\n");
        return (1);
    }

    hashing_data data = {0};

    if (!get_flags(argv, argc, &data)) {
        free_source(data.source);
        return (1);
    }

    ft_ssl(&data);

    // printf("\n-----------\n");
    // print_data_statut(data);

    free_source(data.source);

    return (0);
}
