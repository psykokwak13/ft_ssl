#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*elem;

	elem = malloc(sizeof(t_list));
	if (!elem)
		return (NULL);
	elem->content = content;
	elem->next = NULL;
	return (elem);
}

/*void	print_list(t_list *list)
{
	while (list != NULL)
	{
		printf ("%d ->", *(int *)list->content);
		list = list ->next;
	}
}

int	main(void)
{
    int value = 42;
    t_list *node = ft_lstnew(&value);

    if (node != NULL)
    {
        printf("Düğüm içeriği: %d\n", *(int *)node->content);
        print_list(node);
    }	
	free(node);
	return 0;
}*/