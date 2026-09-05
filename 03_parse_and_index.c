/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_parse_and_index.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbin-mus <mbin-mus@student.42penang.edu    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 16:12:04 by nisim             #+#    #+#             */
/*   Updated: 2026/09/05 18:51:25 by nisim            ###   ########.fr       */
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

void	init_stack(t_list **stack, int ac, char **av, t_mode mode)
{
	t_list	*new;
	char	**args;
	int		start;
	int		end;

	args = av;
	start = 1;
	if (ac == 2)
	{
		args = ft_split(av[1], ' '); // Fixed to av[1]
		start = 0;
	}
	end = get_end_index(ac, args);
	if (is_flag(args[start]) == mode && mode != DEFAULT)
		start++;
	if (is_flag(args[end]) == mode && mode != DEFAULT)
		end--;
	while (start <= end)
	{
		new = ft_lstnew_int(ft_atoi(args[start]));
		ft_lstadd_back(stack, new);
		start++;
	}
	index_stack(stack);
	if (ac == 2)
		ft_free(args);
}
