#include "libft.h"

int	ft_tolower(int letter)
{
	if (letter >= 65 && letter <= 90)
		return (letter += 32);
	return (letter);
}
/*int	main(void)
{
	int	c;

	c = 'T';
	c = ft_tolower(c);
	printf("%c\n", c);
	return (0);
}*/