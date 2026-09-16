#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	len_src;
	size_t	i;

	len_src = 0;
	while (src[len_src] != '\0')
		len_src++;
	i = 0;
	if (size > 0)
	{
		while (src[i] && i < (size - 1))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (len_src);
}
/*int     main(void)
{
        char    dest[90];
        char    src[] = "salut comment ca va";

        ft_strlcpy(dest,src,8);
        printf("%s\n", dest);
        return (0);
}*/