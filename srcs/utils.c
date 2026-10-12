#include "../includes/ft_ssl.h"


char    *get_hashing_type(hashing_type type) {
    switch (type) {
        case MD5_HASH :
            return ("MD5");
        case SHA256_HASH :
            return ("SHA256");
    };
}

char *ft_strnjoin(char *s1, char *s2, size_t size_s1, size_t size_s2)
{
    size_t  i;
    size_t  j;
    char    *new;

    new = malloc(size_s1 + size_s2 + 1);
    if (!new)
        return (NULL);
    i = 0;
    while (i < size_s1)
    {
        new[i] = s1[i];
        i++;
    }
    j = 0;
    while (j < size_s2)
    {
        new[i + j] = s2[j];
        j++;
    }
    new[i + j] = '\0';
    return (new);
}

char    *handle_srcfile(t_source *source) {
    int     fd;
    char    buffer[1024];
    char    *temp;
    size_t  total = 0;

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
        result = ft_strnjoin(result, buffer, total, byte_read);
        total += byte_read;
        free(temp);
    }

    close(fd);
    source->size_of_value = total;

    if (byte_read == -1) {
        free(result);
        eprintf("%s : can't read file\n", source->value);
        return (NULL);
    }

    return (result);
}

bool    handle_stdin(hashing_data *data) {
    char    buffer[1024];
    ssize_t bytes_read = 1;
    char    *result = ft_strdup("");
    char    *temp = NULL;

    while (bytes_read > 0) {
        bytes_read = read(0, &buffer, 1023);
        buffer[bytes_read] = '\0';
        temp = result;
        result = ft_strjoin(result, buffer);
        free(temp);
    }

    if (bytes_read == -1) {
        eprintf("error : can't read stdin\n");
        return (false);
    }

    add_source(data, SRC_STDIN, result, ft_strlen(result));

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

void    add_source(hashing_data *data, t_src_type type, char *str, size_t size_str) {
    t_source    *new = malloc(sizeof(t_source));
    t_source    *root = data->source;

    if (!new) {
        ft_printf("error : malloc add_source()\n");
        return ;
    }
    new->type = type;
    new->value = str;
    new->size_of_value = size_str;
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