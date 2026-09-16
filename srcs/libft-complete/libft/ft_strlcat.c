#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	len_d;
	size_t	len_s;
	size_t	i;
	size_t	j;

	len_d = 0;
	len_s = 0;
	while (dest[len_d] != '\0')
		len_d++;
	while (src[len_s] != '\0')
		len_s++;
	if (len_d >= size)
		return (len_s + size);
	i = len_d;
	j = 0;
	while (src[j] != '\0' && i < size - 1)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (len_d + len_s);
}
/*int     main(void)
{
        char    dest[] = "hello";
        char    src[] = "salut";

        ft_strlcat(dest,src,11);
        printf("%s\n",dest);
        return (0);
}*/