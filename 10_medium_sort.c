/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10_medium_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbin-mus <mbin-mus@student.42penang.edu    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 16:08:50 by mbin-mus          #+#    #+#             */
/*   Updated: 2026/09/04 23:05:00 by mbin-mus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* how wide one chunk is, roughly twice the square root of the size */
static int	chunk_width(int size)
{
	int	width;

	if (size <= 5)
		return (size);
	width = 1;
	while (width * width < size)
		width++;
	return (width * 2);
}

/* st[0] = hi, st[1] = width, st[2] = pending sink on b */
static void	push_one(t_list **a, t_list **b, int st[3], t_ops *operation)
{
	int	index;

	flush_pending(b, &st[2], operation);
	index = (*a)->index;
	pb(a, b, operation);
	if (index < st[0] - (st[1] / 2))
		st[2] = 1;
}

/* one rotation of a, folding a pending rb into rr when directions agree */
static void	push_step(t_list **a, t_list **b, int st[3], t_ops *operation)
{
	int	up;
	int	down;

	up = first_in_chunk(*a, st[0]);
	down = stack_size(*a) - last_in_chunk(*a, st[0]);
	if (up <= down)
	{
		if (st[2])
		{
			rr(a, b, operation);
			st[2] = 0;
		}
		else
			ra(a, operation, 1);
	}
	else
	{
		flush_pending(b, &st[2], operation);
		rra(a, operation, 1);
	}
}

/* move every node of a into b, one chunk at a time */
static void	push_phase(t_list **a, t_list **b, t_ops *operation)
{
	int	st[3];
	int	pushed;
	int	total;

	total = stack_size(*a);
	st[1] = chunk_width(total);
	st[0] = st[1] - 1;
	st[2] = 0;
	pushed = 0;
	while (pushed < total)
	{
		if ((*a)->index <= st[0])
		{
			push_one(a, b, st, operation);
			pushed++;
		}
		else
			push_step(a, b, st, operation);
		if (pushed > st[0])
			st[0] = st[0] + st[1];
	}
	flush_pending(b, &st[2], operation);
}

void	chunk_sort(t_list **a, t_list **b, t_ops *operation)
{
	if (!a || !*a || !(*a)->next)
		return ;
	push_phase(a, b, operation);
	pop_phase(a, b, operation);
}
