#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
/*int	main(void)
{
	char	letter = 'a';
	
	ft_putchar_fd(letter, 1);
	return (0);
}
*/	