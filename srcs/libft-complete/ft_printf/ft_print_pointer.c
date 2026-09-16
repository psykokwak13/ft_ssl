#include "ft_printf.h"

static int	ft_print_hex(unsigned long n)
{
	int		count;
	char	*base;

	count = 0;
	base = "0123456789abcdef";
	if (n >= 16)
	{
		count += ft_print_hex(n / 16);
		count += ft_print_char(base[n % 16]);
	}
	else
		count += ft_print_char(base[n]);
	return (count);
}

int	ft_print_pointer(void *ptr)
{
	int				count;	
	unsigned long	n;

	count = 0;
	n = (unsigned long)ptr;
	if (ptr == 0)
		return (ft_print_str("(nil)"));
	count += ft_print_str("0x");
	count += ft_print_hex(n);
	return (count);
}

/*int main(void)
{
    int     a = 42;
    int     *ptr_a = &a;
    char    *str = "Hello, World!";
    char    **ptr_str = &str;

    ft_print_pointer(ptr_a);
    ft_print_char('\n');

    ft_print_pointer(NULL);
    ft_print_char('\n');

    ft_print_pointer(ptr_str);
    ft_print_char('\n');*/