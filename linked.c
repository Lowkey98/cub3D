# include "includes/cub3d.h"
t_list	*ft_lstlast(t_list *lst)
{
	t_list *current;

	if (!lst)
		return (NULL);
	current = lst;
	while (current->next != NULL)
	{
		current = current->next;
	}
	return (current);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *last;

	if (*lst == NULL)
		*lst = new;
	else if (lst)
	{
		last = ft_lstlast(*lst);
		last->next = new;
	}
}