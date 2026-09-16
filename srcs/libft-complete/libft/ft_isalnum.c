#include "libft.h"

int	ft_isalnum(int verif)
{
	if ((verif >= 'a' && verif <= 'z') || (verif >= 'A' && verif <= 'Z')
		|| (verif >= '0' && verif <= '9'))
		return (1);
	return (0);
}

/*int	main(void)
{
	int test = 'a';
	int test1 = 'A';
	int test2 = '1';
	int test3 = '/';

	printf ("%d", ft_isalnum(test));
	printf ("%d", ft_isalnum(test1));
	printf ("%d", ft_isalnum(test2));
	printf ("%d", ft_isalnum(test3));
	return (0);
}*/