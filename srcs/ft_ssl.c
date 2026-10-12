#include "../includes/ft_ssl.h"

static char *get_algorithm_result(hashing_type type, char *str, size_t len) {
    switch (type) {
        case MD5_HASH :
            return (ft_ssl_md5(str, len));
        case SHA256_HASH :
            return (ft_ssl_sha256(str, len));
        };
}

static void output_src_file(hashing_data *data, t_source *node) {
    char    *content = handle_srcfile(node);
    char    *output = NULL;

    if (!content)
        return ;

    output = get_algorithm_result(data->type, content, node->size_of_value);

    if (data->quiet_mode)
        ft_printf("%s\n", output);
    else if (data->reverse_format)
        ft_printf("%s %s\n", output, node->value);
    else
        ft_printf("%s (%s) = %s\n", get_hashing_type(data->type), node->value, output);

    free(output);
    free(content);
}

static void output_src_stdin(hashing_data *data, t_source *node) {
    char    *output = NULL;

    output = get_algorithm_result(data->type, node->value, node->size_of_value);

    if (data->quiet_mode) {
        if (data->echo_mode)
            printf("%s\n", node->value);
        ft_printf("%s\n", output);
    }
    else {
        if (data->echo_mode) ft_printf("%s (\"%s\") = %s\n", get_hashing_type(data->type), node->value, output);
        else ft_printf("%s (stdin) = %s\n", get_hashing_type(data->type), output);
    }
    free(output);
}

static void output_src_string(hashing_data *data, t_source *node) {
    char    *output = NULL;

    output = get_algorithm_result(data->type, node->value, node->size_of_value);

    node->value[ft_strlen(node->value)] = '\0';
    if (data->quiet_mode)
        ft_printf("%s\n", output);
    else if (data->reverse_format)
        ft_printf("%s \"%s\"\n", output, node->value);
    else
        ft_printf("(\"%s\") = %s\n", node->value, output);

    free(output);
}

void    ft_ssl(hashing_data *data) {
    t_source    *node = data->source;

    for (; node; node = node->next) {
        switch (node->type) {
            case SRC_FILE :
                output_src_file(data, node);
                break ;
            case SRC_STDIN :
                output_src_stdin(data, node);
                break ;
            case SRC_STRING :
                output_src_string(data, node);
                break ;
        }
    }
}
