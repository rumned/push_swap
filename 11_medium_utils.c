/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11_medium_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbin-mus <mbin-mus@student.42penang.edu    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 16:07:48 by mbin-mus          #+#    #+#             */
/*   Updated: 2026/09/04 19:09:33 by mbin-mus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

/* one rotation of a, towards whichever end of the chunk is nearer */
void	step_a(t_list **a, t_ops *operation, int hi)
{
	int	up;
	int	down;

	up = first_in_chunk(*a, hi);
	down = stack_size(*a) - last_in_chunk(*a, hi);
	if (up <= down)
		ra(a, operation, 1);
	else
		rra(a, operation, 1);
}