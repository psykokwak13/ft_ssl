#include "libft.h"

char	*ft_strrchr(const char *str, int searchedChar)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	while (i >= 0)
	{
		if (str[i] == (char)searchedChar)
			return ((char *)&str[i]);
		i--;
	}
	return (NULL);
}
/*int	main(void)
{
	char	str[] = "salut comment ca va";
	char	value=  't';
	char	*result;

	result = ft_strrchr(str, value);
	if(result != NULL)
		printf("deger = '%c', pozisyonu = '%td'", value, result - str);
	else
		printf("karakter bulunamadi\n");
	return (0);
}*/