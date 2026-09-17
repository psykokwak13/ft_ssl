#ifndef FT_SSL_MD5_H

#define FT_SSL_MD5_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>
#include <fcntl.h>
#include <math.h>
#include <stdint.h>
#include "../srcs/libft-complete/libft/libft.h"

#define eprintf(...) fprintf (stderr, __VA_ARGS__)

typedef struct {
    uint32_t a, b, c, d;
} md5_context;

typedef enum {
    MD5_HASH,
    SHA256_HASH
} hashing_type;

typedef enum e_src_type {
    SRC_STDIN,
    SRC_STRING,
    SRC_FILE
} t_src_type;

typedef struct s_source {
    t_src_type          type;
    char                *value;
    struct s_source     *next;
} t_source;

typedef struct {
    hashing_type    type;
    bool            echo_mode;
    bool            quiet_mode;
    bool            reverse_format;
    bool            print_mode;
    bool            read_stdin;

    t_source        *source;
} hashing_data;

void    ft_ssl(hashing_data *data); // handle output option and redirect to md5 or sha256
char    *ft_ssl_md5(char *str); // main function for hashing string into md5
char    *ft_ssl_sha256(char *data);
void    get_arr_debug(char **arr);

// utils
void    get_arr_debug(char **arr);
void    print_data_statut(hashing_data data);
void    add_source(hashing_data *data, t_src_type type, char *str);
void    free_source(t_source *source);
bool    handle_stdin(hashing_data *data);
char    *handle_srcfile(t_source *source); // beta version, have to handle file > 1024 bits

#endif