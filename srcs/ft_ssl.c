#include "../includes/ft_ssl.h"

unsigned char *md5_sha256_pad(const char *msg, size_t len, size_t *out_len) // a revoir
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


/*
    if (data->quiet_mode) { // all in quiet_mode
        // manage before all stdin input (-p option or no arg)
    }
    else if (data->reverse_format) { // all in reverse_format if no quiet_mode
        // manage before all stdin input (-p option or no arg)
    }
    else { // normal output
        // manage before all stdin input (-p option or no arg)
    }
 */