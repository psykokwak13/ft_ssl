#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		return (c -= 32);
	return (c);
}
/*int	main(void)
{
	int	c;

	c = 't';
	c = ft_toupper(c);
	printf("%c\n", c);
	return (0);
}*/