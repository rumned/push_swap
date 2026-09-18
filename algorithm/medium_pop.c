/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_pop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbin-mus <mbin-mus@student.42penang.edu    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 23:02:34 by mbin-mus          #+#    #+#             */
/*   Updated: 2026/09/18 16:21:42 by nisim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	max_index(t_list *b)
{
	int	best;

	best = -1;
	while (b)
	{
		if (b->index > best)
			best = b->index;
		b = b->next;
	}
	return (best);
}

static int	bottom_index(t_list *a)
{
	if (!a)
		return (-1);
	while (a->next)
		a = a->next;
	return (a->index);
}

static int	can_park(t_list **a, t_list **b, int parked, int pos)
{
	int	size;

	size = stack_size(*b);
	if (size - pos < pos)
		pos = size - pos;
	if (pos <= 1 || !*a || !(*a)->next)
		return (0);
	if ((*b)->index > (*a)->index)
		return (0);
	if (parked && (*b)->index < bottom_index(*a))
		return (0);
	return (1);
}

/* recall parked nodes that now outrank everything left in b */
static int	unpark(t_list **a, int *parked, t_list *b, t_ops *operation)
{
	int	mx;

	mx = max_index(b);
	while (*parked > 0 && bottom_index(*a) > mx)
	{
		rra(a, operation, 1);
		(*parked)--;
	}
	return (mx);
}

void	pop_phase(t_list **a, t_list **b, t_ops *operation)
{
	int	parked;
	int	mx;
	int	pos;

	parked = 0;
	while (*b)
	{
		mx = unpark(a, &parked, *b, operation);
		pos = pos_of_index(*b, mx);
		if (can_park(a, b, parked, pos))
		{
			pa(a, b, operation, 1);
			ra(a, operation, 1);
			parked++;
		}
		else
		{
			rotate_b_to(b, operation, pos);
			pa(a, b, operation, 1);
		}
	}
	while (parked-- > 0)
		rra(a, operation, 1);
}
