#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		(*f)(i, &s[i]);
		i++;
	}
}
/*
void	upper_iteri(unsigned int i, char *c)
{
	if (i % 2 == 0)
		*c = ft_toupper(*c);
	else
		*c = ft_tolower(*c);
}

int	main(void)
{
	char	str[]=  "Hello World";
	
	printf ("original dizi: %s\n", str);
	ft_striteri(str,upper_iteri);
	printf ("guncellenmis dizi: %s\n", str);
	return (0);
}
*/