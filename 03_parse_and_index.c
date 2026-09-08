/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_parse_and_index.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbin-mus <mbin-mus@student.42penang.edu    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 16:12:04 by nisim             #+#    #+#             */
/*   Updated: 2026/09/08 20:03:20 by mbin-mus         ###   ########.fr       */
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
	char	**args;
	int		count;
	int		i;
	t_flags	skip;

	skip.mode = DEFAULT;
	skip.bench = 0;
	args = build_args(ac, av);
	if (!args)
		ft_error("Error");
	count = count_args(args);
	extract_flags(args, &count, &skip);
	i = 0;
	while (i < count)
	{
		ft_lstadd_back(stack, ft_lstnew_int(ft_atoi(args[i])));
		i++;
	}
	index_stack(stack);
	ft_free(args);
}
