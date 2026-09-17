/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   19_greedy_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbin-mus <mbin-mus@student.42penang.edu    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 23:01:54 by mbin-mus          #+#    #+#             */
/*   Updated: 2026/09/12 22:16:50 by mbin-mus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* signed rotation count: positive means ra/rb, negative means rra/rrb */
int	rot_cost(int pos, int size)
{
	if (pos <= size / 2)
		return (pos);
	return (pos - size);
}

int	abs_i(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

/* cost of moving both stacks, sharing rr/rrr when the signs agree */
int	combined(int ca, int cb)
{
	if ((ca >= 0 && cb >= 0) || (ca <= 0 && cb <= 0))
	{
		if (abs_i(ca) > abs_i(cb))
			return (abs_i(ca));
		return (abs_i(cb));
	}
	return (abs_i(ca) + abs_i(cb));
}

int	pos_of_min(t_list *stack)
{
	int	pos;
	int	best_pos;
	int	best_val;

	if (!stack)
		return (-1);
	pos = 0;
	best_pos = 0;
	best_val = stack->value;
	while (stack)
	{
		if (stack->value < best_val)
		{
			best_val = stack->value;
			best_pos = pos;
		}
		stack = stack->next;
		pos++;
	}
	return (best_pos);
}

/* where value belongs in a, which stays sorted but rotated */
int	find_insert_pos(t_list *a, int value)
{
	int		pos;
	int		best_pos;
	int		best_val;
	t_list	*tmp;

	tmp = a;
	pos = 0;
	best_pos = -1;
	best_val = 0;
	while (tmp)
	{
		if (tmp->value > value && (best_pos == -1 || tmp->value < best_val))
		{
			best_val = tmp->value;
			best_pos = pos;
		}
		tmp = tmp->next;
		pos++;
	}
	if (best_pos == -1)
		return (pos_of_min(a));
	return (best_pos);
}
