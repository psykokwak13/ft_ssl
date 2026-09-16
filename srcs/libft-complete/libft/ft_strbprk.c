#include "libft.h"

char	*ft_strpbrk(const char *s, const char *charset)
{
	const char	*c;

	if (!s || !charset)
		return (NULL);
	while (*s)
	{
		c = charset;
		while (*c)
		{
			if (*s == *c)
				return ((char *)s);
			c++;
		}
		s++;
	}
	return (NULL);
}
/**
 * Breaks a string into tokens based on a specified delimiter.
 *
 * @param str The string to be tokenized.
 * @param delimiter The delimiter used to split the string into tokens.
 * @return A pointer to an array of strings representing the tokens.
 */