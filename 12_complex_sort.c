/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   12_complex_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbin-mus <mbin-mus@student.42penang.edu    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 20:21:46 by nisim             #+#    #+#             */
/*   Updated: 2026/09/04 19:10:36 by mbin-mus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	clear_split(t_list **a, t_list **b, int pending[2], t_ops *ops)
{
	int	digit;

	digit = pending[1];
	if (digit == 0 || digit == 1)
	{
		if (pending[0])
		{
			rb(b, ops, 1);
			pending[0] = 0;
		}
		pb(a, b, ops);
		pending[0] = (digit == 0);
	}
	else if (digit == 2 || digit == 3)
	{
		if (pending[0])
		{
			rr(a, b, ops);
			pending[0] = 0;
		}
		else
			ra(a, ops, 1);
	}
}

static void	bitwise_split(t_list **a, t_list **b, int *count, t_ops *operation)
{
	int	i;
	int	size;
	int	shift;
	int	digit;
	int	pending[2];

	i = 0;
	shift = count[4];
	size = stack_size(*a);
	pending[0] = 0;
	while (i++ < size)
	{
		digit = ((*a)->index >> shift) & 3;
		pending[1] = digit;
		count[digit]++;
		clear_split(a, b, pending, operation);
	}
	if (pending[0])
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

static void	partition(t_list **a, t_list **b, int *ssm, t_ops *operation)
{
	int	count[2];
	int	digit;

	while (ssm[0] < ssm[2])
	{
		count[0] = 0;
		count[1] = 0;
		ssm[1] = stack_size(*a);
		while (ssm[1]--)
		{
			digit = ((*a)->index >> ssm[0]) & 1;
			count[digit]++;
			if (digit == 0)
				pb(a, b, operation);
			else if (digit == 1)
				ra(a, operation, 1);
		}
		while (count[0]--)
			pa(a, b, operation);
		ssm[0]++;
		if (is_sorted(a))
			break ;
	}
}

void	radix_mix(t_list **a, t_list **b, t_ops *operation)
{
	int	size;
	int	max_bits;
	int	i;
	int	count[5];
	int	shift_size_max[3];

	size = stack_size(*a);
	max_bits = 0;
	while (((size - 1) >> max_bits) != 0)
		max_bits++;
	i = 5;
	while (i--)
		count[i] = 0;
	bitwise_split(a, b, count, operation);
	refine_stack(a, b, count, operation);
	while (count[1]--)
		pa(a, b, operation);
	while (count[0]--)
		pa(a, b, operation);
	shift_size_max[0] = 2;
	shift_size_max[1] = size;
	shift_size_max[2] = max_bits;
	partition(a, b, shift_size_max, operation);
}
