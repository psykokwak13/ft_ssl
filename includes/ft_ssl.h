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
#include "../srcs/libft-complete/ft_printf/ft_printf.h"

#define TO_I32_LITTLE_ENDIAN(x,i) (((uint32_t)(x)[i]) | ((uint32_t)(x)[i+1]<<8) | ((uint32_t)(x)[i+2]<<16) | ((uint32_t)(x)[i+3]<<24))
#define TO_I32_BIG_ENDIAN(x,i) (((uint32_t)(x)[i + 3]) | ((uint32_t)(x)[i+2]<<8) | ((uint32_t)(x)[i+1]<<16) | ((uint32_t)(x)[i]<<24))

#define eprintf(...) fprintf (stderr, __VA_ARGS__)

typedef struct {
    uint32_t a, b, c, d;
} md5_context;

typedef struct {
    uint64_t a, b, c, d, e, f, g, h;
} sha256_context;

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
    bool            echo_mode; // -p
    bool            quiet_mode; // -q
    bool            reverse_format; // -r
    bool            print_mode; // -s
    bool            read_stdin;
    t_source        *source;
} hashing_data;

void            ft_ssl(hashing_data *data); // handle output option and redirect to md5 or sha256
char            *ft_ssl_md5(char *str); // main function for hashing string into md5
char            *ft_ssl_sha256(char *data);
void            get_arr_debug(char **arr);

// md5/sha256 utils
unsigned char   *md5_sha256_pad(const char *msg, size_t len, size_t *out_len, hashing_type type);
uint32_t        *get_words(unsigned char *message, int nb_bloc, hashing_type type);
uint32_t        rotl(uint32_t x, int s);
uint32_t        rotr(uint32_t x, int s);

// utils
void            get_arr_debug(char **arr);
void            print_data_statut(hashing_data data);
void            add_source(hashing_data *data, t_src_type type, char *str);
void            free_source(t_source *source);
bool            handle_stdin(hashing_data *data);
char            *handle_srcfile(t_source *source);
char            *get_hashing_type(hashing_type type);

#endif