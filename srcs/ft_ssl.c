#include "../includes/ft_ssl.h"

static void output_src_file(hashing_data *data, t_source *node) {
    char    *content = handle_srcfile(node);
    char    *output = NULL;

    if (!content)
        return ;

    if (data->quiet_mode) {
        if (data->type == MD5_HASH) {
            output = ft_ssl_md5(content);
            printf("%s\n", output);
        }
        if (data->type == SHA256_HASH) {
            output = ft_ssl_sha256(content);
            printf("%s\n", output);
        }
    }
    else if (data->reverse_format) {
        if (data->type == MD5_HASH) {
            output = ft_ssl_md5(content);
            printf("%s %s\n", output, node->value);
        }
        if (data->type == SHA256_HASH) {
            output = ft_ssl_sha256(content);
            printf("%s %s\n", output, node->value);
        }
    }
    else {
        if (data->type == MD5_HASH) {
            output = ft_ssl_md5(content);
            printf("MD5 (%s) = %s\n", node->value, output);
        }
        if (data->type == SHA256_HASH) {
            output = ft_ssl_sha256(content);
            printf("SHA256 (%s) = %s\n", node->value, output);
        }
    }

    free(output);
    free(content);
}

static void output_src_stdin(hashing_data *data, t_source *type) { // do this at the end for testing etc
    char    *output = NULL;

    if (!handle_stdin(data)) {
        ft_putstr_fd("stdin : can't access", 2);
        return ;
    }

    if (data->quiet_mode) {
        if (data->type == MD5_HASH) {
            output = ft_ssl_md5(type->value);
        }
        if (data->type == SHA256_HASH) {
            output = ft_ssl_sha256(type->value);
        }
    }
    else if (data->reverse_format) {
        if (data->type == MD5_HASH) {
            output = ft_ssl_md5(type->value);
        }
        if (data->type == SHA256_HASH) {
            output = ft_ssl_sha256(type->value);
        }
    }
    else {
        if (data->type == MD5_HASH) {
            output = ft_ssl_md5(type->value);
        }
        if (data->type == SHA256_HASH) {
            output = ft_ssl_sha256(type->value);
        }
    }
    free(output);
}

static void output_src_string(hashing_data *data, t_source *node) {
    char    *output = NULL;

    if (data->quiet_mode) {
        if (data->type == MD5_HASH) {
            output = ft_ssl_md5(node->value);
            printf("%s\n", output);
        }
        if (data->type == SHA256_HASH) {
            output = ft_ssl_sha256(node->value);
            printf("%s\n", output);
        }
    }
    else if (data->reverse_format) {
        if (data->type == MD5_HASH){
            output = ft_ssl_md5(node->value);
            printf("%s \"%s\"\n", output, node->value);
        }
        if (data->type == SHA256_HASH) {
            output = ft_ssl_sha256(node->value);
            printf("%s \"%s\"\n", output, node->value);
        }
    }
    else {
        if (data->type == MD5_HASH) {
            output = ft_ssl_md5(node->value);
            printf("MD5 (\"%s\") = %s\n", node->value, output);
        }
       if (data->type == SHA256_HASH) {
           output = ft_ssl_sha256(node->value);
            printf("SHA256 (\"%s\") = %s\n", node->value, output);
        }
    }
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
