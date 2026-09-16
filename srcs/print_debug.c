#include "../includes/ft_ssl.h"

void    get_arr_debug(char **arr) { // have to be deleted at the end !!
    for (int i = 0; arr[i]; i++) {
        printf("[%s]", arr[i]);
    }
    putchar('\n');
}

static char    *get_type(t_src_type type) {
    if (type == SRC_STDIN)
        return ("SRC_STDIN");
    else if (type == SRC_STRING)
        return ("SRC_STRING");
    else
        return ("SRC_FILE");
}

static void    print_source(t_source *source) {
    t_source    *checkpoint = source;
    if (!source) {
        printf("null\n");
    }
    while (checkpoint) {
        printf("[%s | %s]\n", checkpoint->value, get_type(checkpoint->type));
        checkpoint = checkpoint->next;
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
            source : \n",
         data.type, data.echo_mode, data.quiet_mode, data.reverse_format,
         data.print_mode);
    print_source(data.source);
}