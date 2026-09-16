#include "../includes/ft_ssl.h"

// ATTENTION AU CAS D'ERREUR -> NE DOIT PAS COUPER LE PROGRAMME : AFFICHE JUSTE ET PASSE A LA SUITE COMME SRC_FILE/SRC_STRING
// -> on init source avec SRC_STDIN et on laisse value a NULL
char    *handle_srcfile(t_source *source) { // beta version, have to handle file > 1024 bits
    int     fd;
    char    buffer[1024];
    if (source->type != SRC_FILE) {
        printf("'%s' don't contain SRC_FILE\n", source->value);
        return (NULL);
    }
    fd = open(source->value, O_RDONLY);
    if (fd == -1) {
        printf("%s : No such file or directory\n", source->value);
        return (NULL);
    }

    ssize_t byte_read = read(fd, &buffer, 1024);

    if (byte_read == -1) {
        printf("%s : can't read file", source->value);
        return (NULL);
    }
    return (strdup(buffer));
}

bool    handle_stdin(hashing_data *data) { // beta version, have to handle stdin > 1024 bits
    char    buffer[1024];
    ssize_t bytes_read = read(0, &buffer, 1024);

    if (bytes_read == -1) {
        eprintf("Error : can't read stdin\n");
        return (false);
    }

    buffer[bytes_read] = '\0';
    add_source(data, SRC_STDIN, strdup(buffer));

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