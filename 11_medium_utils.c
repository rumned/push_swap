/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11_medium_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbin-mus <mbin-mus@student.42penang.edu    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 16:07:48 by mbin-mus          #+#    #+#             */
/*   Updated: 2026/09/04 23:05:20 by mbin-mus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* position of the topmost node belonging to the current chunk */
int	first_in_chunk(t_list *stack, int hi)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->index <= hi)
			return (pos);
		pos++;
		stack = stack->next;
	}
	return (-1);
}

/* position of the deepest node belonging to the current chunk */
int	last_in_chunk(t_list *stack, int hi)
{
	int	pos;
	int	best;

	pos = 0;
	best = -1;
	while (stack)
	{
		if (stack->index <= hi)
			best = pos;
		pos++;
		stack = stack->next;
	}
	return (best);
}

/* apply a deferred sink rotation on b */
void	flush_pending(t_list **b, int *pending, t_ops *operation)
{
	if (*pending)
	{
		rb(b, operation, 1);
		*pending = 0;
	}
}

/* how many nodes sit above the node holding this index */
int	pos_of_index(t_list *stack, int index)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->index == index)
			return (pos);
		pos++;
		stack = stack->next;
	}
	return (-1);
}

/* bring position pos of b to the top, shorter direction first */
void	rotate_b_to(t_list **b, t_ops *operation, int pos)
{
	int	size;

	size = stack_size(*b);
	if (pos <= size - pos)
	{
		while (pos > 0)
		{
			rb(b, operation, 1);
			pos--;
		}
	}
	else
	{
		while (pos < size)
		{
			rrb(b, operation, 1);
			pos++;
		}
	}
}
