#include "bonus.h"

int	is_sorted(t_list **stack)
{
	t_list	*head;

	head = *stack;
	while (head && head->next)
	{
		if (head->value > head->next->value)
			return (0);
		head = head->next;
	}
	return (1);
}

t_list	*ft_lstnew_int(int value)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->value = value;
	new->index = -1;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*hldr;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	hldr = *lst;
	while (hldr->next != NULL)
		hldr = hldr->next;
	hldr->next = new;
	new->prev = hldr;
}
