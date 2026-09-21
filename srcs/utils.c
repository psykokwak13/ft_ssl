#include "../includes/ft_ssl.h"

char    *get_hashing_type(hashing_type type) {
    switch (type) {
        case MD5_HASH :
            return ("MD5");
        case SHA256_HASH :
            return ("SHA256");
    };
}

char    *handle_srcfile(t_source *source) { // a tester
    int     fd;
    char    buffer[1024];
    char    *temp;

    if (source->type != SRC_FILE) {
        eprintf("'%s' don't contain SRC_FILE\n", source->value);
        return (NULL);
    }
    fd = open(source->value, O_RDONLY);
    if (fd == -1) {
        eprintf("%s : No such file or directory\n", source->value);
        return (NULL);
    }

    ssize_t byte_read = 1;
    char *result = ft_strdup("");

    while (byte_read > 0) {
        byte_read = read(fd, &buffer, 1023);
        temp = result;
        buffer[byte_read] = '\0';
        result = ft_strjoin(result, buffer);
        free(temp);
    }

    if (byte_read == -1) {
        close(fd);
        free(result);
        eprintf("%s : can't read file\n", source->value);
        return (NULL);
    }

    close(fd);

    if (!ft_strcmp(result, "")) {
        eprintf("%s : empty file\n", source->value);
        free(result);
        return (NULL);
    }


    return (result);
}

bool    handle_stdin(hashing_data *data) { // a tester
    char    buffer[1024];
    ssize_t bytes_read = 1;
    char    *result = ft_strdup("");
    char    *temp = NULL;

    while (bytes_read > 0) {
        bytes_read = read(0, &buffer, 1024);
        buffer[bytes_read] = '\0';
        temp = result;
        result = ft_strjoin(result, buffer);
        free(temp);
    }

    if (bytes_read == -1) {
        eprintf("error : can't read stdin\n");
        return (false);
    }

    add_source(data, SRC_STDIN, result);

    return (true);
}

void    free_source(t_source *source) {
    t_source    *checkpoint;

    while (source) {
        checkpoint = source->next;
        free(source->value);
        free(source);
        source = checkpoint;
    }
}

void    add_source(hashing_data *data, t_src_type type, char *str) {
    t_source    *new = malloc(sizeof(t_source));
    t_source    *root = data->source;

    new->type = type;
    new->value = str;
    new->next = NULL;

    if (!root) {
        data->source = new;
        return ;
    }
    while (data->source->next) {
        data->source = data->source->next;
    }

    data->source->next = new;
    data->source = root;
}