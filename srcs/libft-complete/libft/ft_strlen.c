#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}
/*int	main(void)
{
	printf("%d", ft_strlen("salut comment ca va"));
	return (0);
}*/