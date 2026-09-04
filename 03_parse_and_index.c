/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_parse_and_index.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbin-mus <mbin-mus@student.42penang.edu    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 16:12:04 by nisim             #+#    #+#             */
/*   Updated: 2026/09/04 20:39:01 by mbin-mus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*get_next_min(t_list **stack)
{
	t_list	*node;
	t_list	*min;

	min = NULL;
	node = *stack;
	if (node)
	{
		while (node)
		{
			if ((node->index == -1) && (!min || node->value < min->value))
				min = node;
			node = node->next;
		}
	}
	return (min);
}

void	index_stack(t_list **stack)
{
	t_list	*node;
	int		index;

	index = 0;
	node = get_next_min(stack);
	while (node)
	{
		node->index = index++;
		node = get_next_min(stack);
	}
}

void	init_stack(t_list **stack, int ac, char **av)
{
	t_list	*new;
	char	**args;
	int		i;

	i = 0;
	if (ac == 2)
		args = ft_split(av[1], ' ');
	else
	{
		i = 1;
		args = av;
	}
	while (args[i])
	{
		new = ft_lstnew_int(ft_atoi(args[i]));
		ft_lstadd_back(stack, new);
		i++;
	}
	index_stack(stack);
	if (ac == 2)
		ft_free(args);
}

/* a function to check flags and return flags
	might move check args to here
*/