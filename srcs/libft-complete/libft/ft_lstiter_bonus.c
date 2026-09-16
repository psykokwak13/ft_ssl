#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*tmp;

	tmp = lst;
	while (tmp)
	{
		f(tmp -> content);
		tmp = tmp -> next;
	}
}
/*
void	print_content(void *content) 
{
    printf ("%d\n", *(int *)content);
}*/
/*int	main(void) 
{
    t_list elem1, elem2, elem3;
    int val1 = 1, val2 = 2, val3 = 3;

    elem1.content = &val1;
    elem1.next = &elem2;

    elem2.content = &val2;
    elem2.next = &elem3;

    elem3.content = &val3;
    elem3.next = NULL;

    ft_lstiter(&elem1, print_content);

    return 0;
}*/	
/*
int main(void)
{
    t_list *first_node;
    t_list *second_node;
    t_list *third_node;

    int val1 = 1, val2 = 2, val3 = 3;

    first_node = malloc(sizeof(t_list));
    second_node = malloc(sizeof(t_list));
    third_node = malloc(sizeof(t_list));

    first_node->content = &val1;
    first_node->next = second_node;

    second_node->content = &val2;
    second_node->next = third_node;

    third_node->content = &val3;
    third_node->next = NULL;

    ft_lstiter(first_node, print_content);
    return (0);
}*/