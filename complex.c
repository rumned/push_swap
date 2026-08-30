/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisim <nisim@student.42penang.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 20:21:46 by nisim             #+#    #+#             */
/*   Updated: 2026/08/30 21:59:00 by nisim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	bitwise_slice(t_list **a, t_list **b, int digit)
{
	if (digit == 0)
	{
		pb(a, b);
		rb(b);
	}
	else if (digit == 1)
		pb(a, b);
	else if (digit == 2 || digit == 3)
		ra(a);
}

static void	refine_slice(t_list **a, t_list **b, int digit)
{
	if (digit == 2)
		pb(a, b);
	else if (digit == 3)
		ra(a);
}

static void	refine_stack(t_list **a, t_list **b, int count)
{
	while (count--)
		pa
}

static void	partition(t_list **a, t_list **b, int shift, int size)
{
	int	count[4];
	int	digit;
	int	i;

	i = 0;
	while (i < 4)
		count[i] = 0;
	i = 0;
	while (i++ < size)
	{
		digit = ((*a)->index >> shift) & 3;
		count[digit]++;
		bitwise_slice(a, b, digit);
	}
	while (count[1]--)
		pa(a, b);
	while (count[0]--)
	{
		rrb(b);
		pa(a, b);
	}
	while (count[2]--)
		rra(a);
}

void	radix_base4(t_list **a, t_list **b)
{
	int	size;
	int	max_bits;
	int	shift;

	size = stack_size(a);
	max_bits = 0;
	while (((size - 1) >> max_bits) != 0)
		max_bits++;
	shift = 0;
	while (shift < max_bits)
	{
		partition(a, b, shift, size);
		shift += 2;
	}
}
