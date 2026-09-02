/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbin-mus <mbin-mus@student.42penang.edu    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 20:21:46 by nisim             #+#    #+#             */
/*   Updated: 2026/09/02 21:15:18 by mbin-mus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	clear_split(t_list **a, t_list **b, int pending[3], t_ops *ops)
{
	int	digit;

	digit = pending[2];
	if (pending[0] && pending[1])
	{
		rr(a, b, ops);
		pending[0] = 0;
		pending[1] = 0;
	}
	if (digit == 0 || digit == 1)
	{
		if (pending[0])
			ra(a, ops, 1);
		if (pending[1])
			rb(b, ops, 1);
		pb(a, b, ops);
		pending[0] = 0;
		pending[1] = (digit == 0);
	}
	else if (digit == 2 || digit == 3)
	{
		if (pending[0])
			ra(a, ops, 1);
		pending[0] = 1;
	}
}

static void	bitwise_split(t_list **a, t_list **b, int *count, t_ops *operation)
{
	int	i;
	int	size;
	int	shift;
	int	digit;
	int	pending[3];

	i = 0;
	shift = count[4];
	size = stack_size(*a);
	pending[0] = 0;
	pending[1] = 0;
	while (i++ < size)
	{
		digit = ((*a)->index >> shift) & 3;
		pending[2] = digit;
		count[digit]++;
		clear_split(a, b, pending, operation);
	}
	if (pending[0])
		ra(a, operation, 1);
	if (pending[1])
		rb(b, operation, 1);
}

static void	refine_stack(t_list **a, t_list **b, int *count, t_ops *operation)
{
	int	digit;
	int	shift;
	int	size;
	int	i;

	if (!*a)
		return ;
	i = 0;
	shift = count[4];
	size = count[2] + count[3];
	while (i++ < size)
	{
		digit = ((*a)->index >> shift) & 3;
		if (digit == 2)
			pb(a, b, operation);
		else if (digit == 3)
			ra(a, operation, 1);
	}
	while (count[2]--)
		pa(a, b, operation);
}

static void	partition(t_list **a, t_list **b, int shift, t_ops *operation)
{
	int	count[5];
	// int	digit;
	int	i;

	i = 0;
	while (i++ < 4)
		count[i] = 0;
	count[4] = shift;
	bitwise_split(a, b, count, operation);
	refine_stack(a, b, count, operation);
	while (count[1]--)
		pa(a, b, operation);
	while (count[0]--)
		pa(a, b, operation);
}

void	radix_base4(t_list **a, t_list **b, t_ops *operation)
{
	int	size;
	int	max_bits;
	int	shift;

	size = stack_size(*a);
	max_bits = 0;
	while (((size - 1) >> max_bits) != 0)
		max_bits++;
	shift = 0;
	while (shift < max_bits)
	{
		partition(a, b, shift, operation);
		shift += 2;
		if (is_sorted(a))
			break ;
	}
}
