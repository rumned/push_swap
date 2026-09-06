/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisim <nisim@student.42penang.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 19:47:13 by nisim             #+#    #+#             */
/*   Updated: 2026/09/06 20:08:46 by nisim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_next_min(t_list *stack, int size)
{
	int	min;

	if (!stack)
		return (0);
	min = stack->index;
	while (size-- && stack)
	{
		if (stack->index < min)
			min = stack->index;
		stack = stack->next;
	}
	return (min);
}

static int	get_next_max(t_list *stack, int size)
{
	int	max;

	if (!stack)
		return (0);
	max = stack->index;
	while (size-- && stack)
	{
		if (stack->index > max)
			max = stack->index;
		stack = stack->next;
	}
	return (max);
}

void	small_sort_a(t_list **a, t_list **b, int size, t_ops *operation)
{
	int	min;
	int	item_pb;
	int	item_ra;

	item_pb = 0;
	while (size > 2)
	{
		min = get_next_min(*a, size);
		item_ra = 0;
		while ((*a)->index != min)
		{
			ra(a, operation, 1);
			item_ra++;
		}
		pb(a, b, operation);
		item_pb++;
		size--;
		while (item_ra--)
			rra(a, operation, 1);
	}
	if ((*a)->index > (*a)->next->index)
		sa(a, operation, 1);
	while (item_pb--)
		pa(a, b, operation);
}

void	small_sort_b(t_list **a, t_list **b, int size, t_ops *operation)
{
	int	max;
	int	item_rb;

	while (size > 2)
	{
		max = get_next_max(*b, size);
		item_rb = 0;
		while ((*b)->index != max)
		{
			rb(b, operation, 1);
			item_rb++;
		}
		pa(a, b, operation);
		size--;
		while (item_rb--)
			rrb(b, operation, 1);
	}
	if (size == 2 && ((*b)->index < (*b)->next->index))
		sb(b, operation, 1);
	while (size--)
		pa(a, b, operation);
}
