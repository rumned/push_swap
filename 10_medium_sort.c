/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10_medium_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbin-mus <mbin-mus@student.42penang.edu    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 16:08:50 by mbin-mus          #+#    #+#             */
/*   Updated: 2026/09/04 19:09:38 by mbin-mus         ###   ########.fr       */
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

/* push the top of a into b, then sink it if it is a low half index */
static void	push_one(t_list **a, t_list **b, t_ops *operation, int mid)
{
	int	index;

	index = (*a)->index;
	pb(a, b, operation);
	if (index < mid)
		rb(b, operation, 1);
}

/* move every node of a into b, one chunk at a time */
static void	push_phase(t_list **a, t_list **b, t_ops *operation)
{
	int	width;
	int	hi;
	int	pushed;
	int	total;

	total = stack_size(*a);
	width = chunk_width(total);
	hi = width - 1;
	pushed = 0;
	while (pushed < total)
	{
		if ((*a)->index <= hi)
		{
			push_one(a, b, operation, hi - (width / 2));
			pushed++;
		}
		else
			step_a(a, operation, hi);
		if (pushed > hi)
			hi = hi + width;
	}
}

/* pull nodes back into a, biggest index first */
static void	pop_phase(t_list **a, t_list **b, t_ops *operation)
{
	int	size;

	size = stack_size(*b);
	while (size > 0)
	{
		rotate_b_to(b, operation, pos_of_index(*b, size - 1));
		pa(a, b, operation);
		size--;
	}
}

void	chunk_sort(t_list **a, t_list **b, t_ops *operation)
{
	if (!a || !*a || !(*a)->next)
		return ;
	push_phase(a, b, operation);
	pop_phase(a, b, operation);
}