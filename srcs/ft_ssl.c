#include "../includes/ft_ssl.h"

static void output_src_file(hashing_data *data, t_source *node) {
    char    *content = handle_srcfile(node);

    if (!content)
        return ;

    if (data->quiet_mode) {
        if (data->type == MD5_HASH) printf("%s\n", ft_ssl_md5(content));
        if (data->type == SHA256_HASH) printf("%s\n", ft_ssl_sha256(content));
    }
    else if (data->reverse_format) {
        if (data->type == MD5_HASH) printf("%s %s\n", ft_ssl_md5(content), node->value);
        if (data->type == SHA256_HASH) printf("%s %s\n", ft_ssl_sha256(content), node->value);
    }
    else {
        if (data->type == MD5_HASH) printf("MD5 (%s) = %s\n", node->value, ft_ssl_md5(content));
        if (data->type == SHA256_HASH) printf("MD5 (%s) = %s\n", node->value, ft_ssl_sha256(content));
    }

    free(content);
}

static void output_src_stdin(hashing_data *data, t_source *type) { // do this at the end for testing etc
    if (data->quiet_mode) {
        
    }
    else if (data->reverse_format) {
        
    }
    else {
        
    }
}

static void output_src_string(hashing_data *data, t_source *node) {
    if (data->quiet_mode) {
        if (data->type == MD5_HASH) printf("%s\n", ft_ssl_md5(node->value));
        if (data->type == SHA256_HASH) printf("%s\n", ft_ssl_sha256(node->value));
    }
    else if (data->reverse_format) {
        if (data->type == MD5_HASH) printf("%s \"%s\"\n", ft_ssl_md5(node->value), node->value);
        if (data->type == SHA256_HASH) printf("%s \"%s\"\n", ft_ssl_sha256(node->value), node->value);
    }
    else {
        if (data->type == MD5_HASH) printf("MD5 (\"%s\") = %s\n", node->value, ft_ssl_md5(node->value));
        if (data->type == SHA256_HASH) printf("MD5 (\"%s\") = %s\n", node->value, ft_ssl_sha256(node->value));
    }
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
