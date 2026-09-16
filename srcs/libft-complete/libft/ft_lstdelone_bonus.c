#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	(*del)(lst->content);
	free(lst);
}

/*void	del(void *content)
{
	free(content);
}

int	main(void)
{
	t_list	*new;
	char	*tmp;
	
	tmp = ft_strdup("salut comment ca va");
	new = ft_lstnew(tmp);
	printf ("%s\n",(char *) new -> content);
	ft_lstdelone(new,del);
	printf ("%s\n",(char *) new -> content);
	return (0);
}*/