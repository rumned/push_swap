/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   09_simple_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbin-mus <mbin-mus@student.42penang.edu    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 22:53:27 by mbin-mus          #+#    #+#             */
/*   Updated: 2026/09/04 20:54:42 by mbin-mus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_max_pos(t_list *stack)
{
	int	pos;
	int	best;
	int	best_val;

	pos = 0;
	best = 0;
	best_val = stack->value;
	while (stack)
	{
		if (stack->value > best_val)
		{
			best_val = stack->value;
			best = pos;
		}
		stack = stack->next;
		pos++;
	}
	return (best);
}

/* position that must be on top of b before pushing value onto it */
static int	find_target(t_list *stack_b, int value)
{
	int		pos;
	int		best;
	int		best_val;
	t_list	*hldr;

	hldr = stack_b;
	pos = 0;
	best = -1;
	best_val = 0;
	while (hldr)
	{
		if (hldr->value < value && (best == -1 || hldr->value > best_val))
		{
			best_val = hldr->value;
			best = pos;
		}
		hldr = hldr->next;
		pos++;
	}
	if (best == -1)
		return (find_max_pos(stack_b));
	return (best);
}

void	insertion_sort(t_list **a, t_list **b, t_ops *ops)
{
	int	target;

	if (!a || !*a || !(*a)->next)
		return ;
	while (*a)
	{
		if (*b)
		{
			target = find_target(*b, (*a)->value);
			rotate_b_to(b, ops, target);
		}
		pb(a, b, ops);
	}
	rotate_b_to(b, ops, find_max_pos(*b));
	while (*b)
		pa(a, b, ops);
}
