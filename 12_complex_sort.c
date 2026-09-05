/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   12_complex_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisim <nisim@student.42penang.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 20:21:46 by nisim             #+#    #+#             */
/*   Updated: 2026/09/05 13:55:40 by nisim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* count[4] holds the current shift; count[0..3] the digit tallies */
static void	split_low(t_list **a, t_list **b, int *count, t_ops *operation)
{
	int	i;
	int	size;
	int	digit;

	i = 0;
	size = stack_size(*a);
	while (i++ < size)
	{
		digit = ((*a)->index >> count[4]) & 3;
		count[digit]++;
		if (digit < 2)
			pb(a, b, operation);
		else
			ra(a, operation, 1);
	}
}

/* separate digit 2 from digit 3, leaving a as [2s, 3s] */
static void	refine_stack(t_list **a, t_list **b, int *count, t_ops *operation)
{
	int	digit;
	int	size;
	int	i;

	if (!*a)
		return ;
	i = 0;
	size = count[2] + count[3];
	while (i++ < size)
	{
		digit = ((*a)->index >> count[4]) & 3;
		if (digit == 2)
			pb(a, b, operation);
		else if (digit == 3)
			ra(a, operation, 1);
	}
	i = count[2];
	while (i--)
		pa(a, b, operation);
}

/* pull digit 1 out of b first, then digit 0, keeping both groups in order */
static void	extract_ones(t_list **a, t_list **b, int *count, t_ops *operation)
{
	int	i;
	int	size;

	i = 0;
	size = count[0] + count[1];
	while (i++ < size)
	{
		if ((((*b)->index >> count[4]) & 3) == 1)
			pa(a, b, operation);
		else
			rb(b, operation, 1);
	}
	i = count[0];
	while (i--)
		pa(a, b, operation);
}

/* one stable binary pass, used when a single bit is left over */
static void	partition_bit(t_list **a, t_list **b, int *count, t_ops *operation)
{
	int	i;
	int	size;

	i = 0;
	count[0] = 0;
	size = stack_size(*a);
	while (i++ < size)
	{
		if ((((*a)->index >> count[4]) & 1) == 0)
		{
			count[0]++;
			pb(a, b, operation);
		}
		else
			ra(a, operation, 1);
		if (is_sorted(a))
			break ;
	}
	i = count[0];
	while (i--)
		pa(a, b, operation);
}

void	radix_mix(t_list **a, t_list **b, t_ops *operation)
{
	int	max_bits;
	int	count[5];
	int	i;

	max_bits = 0;
	while (((stack_size(*a) - 1) >> max_bits) != 0)
		max_bits++;
	count[4] = 0;
	while (count[4] < max_bits)
	{
		i = 4;
		while (i--)
			count[i] = 0;
		if (count[4] + 1 == max_bits)
			partition_bit(a, b, count, operation);
		else
		{
			split_low(a, b, count, operation);
			refine_stack(a, b, count, operation);
			extract_ones(a, b, count, operation);
		}
		count[4] += 2;
		if (is_sorted(a))
			break ;
	}
}
