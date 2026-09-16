#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*castdest;
	char	*castsrc;

	if (!dest && !src)
		return (NULL);
	castdest = (char *)dest;
	castsrc = (char *)src;
	i = 0;
	while (i < n)
	{
		castdest[i] = castsrc[i];
		i++;
	}
	return (dest);
}

/*
int	main(void)
{
	char dest[100];
	char src[] = "salut comment ca va";
	ft_memcpy(dest,src,19);
	printf ("%s\n", dest);
	return (0);
}*/