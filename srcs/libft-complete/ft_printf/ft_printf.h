#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		ft_print_char(int c);
int		ft_print_str(char *str);
int		ft_print_int(int n);
int		ft_print_hexa(unsigned int n, int casse);
int		ft_print_pointer(void *ptr);
int		ft_print_unsigned(unsigned int n);

#endif