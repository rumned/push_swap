/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisim <nisim@student.42penang.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 20:21:46 by nisim             #+#    #+#             */
/*   Updated: 2026/09/01 15:53:04 by nisim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	clear_slice(t_list **a, t_list **b, int pending[2], t_ops *ops)
{
	if (pending[0] && pending[1])
	{
		rr(a, b, &ops);
		pending[0] = 0;
		pending[1] = 0;
	}
	else if (pending[0])
	{
		ra(a, &ops);
		pending[0] = 0;
	}
	else if (pending[1])
	{
		rb(b, &ops);
		pending[1] = 0;
	}
}

static void	bitwise_slice(t_list **a, t_list **b, int *count, t_ops *operation)
{
	int	i;
	int	size;
	int	pending[2];

	i = 0;
	size = stack_size(a);
	pending[0] = 0;
	pending[1] = 0;
	while (i++ < size)
	{
		digit = ((*a)->index >> shift) & 3;
		count[digit]++;
		clear_slice(a, b, pending, &operation);
		if (digit == 0)
		{
			pb(a, b, &operation);
			pending[1] = 1;
		}
		else if (digit == 1)
			pb(a, b, &operation);
		else if (digit == 2 || digit == 3)
			pending[0] = 1;
	}
	clear_slice(a, b, pending, &operation);
}

static void	refine_stack(t_list **a, t_list **b, int *count, t_ops *operation)
{
	int	digit;
	int	shift;
	int	size;
	int	i;

	if (!a)
		return ;
	i = 0;
	shift = count[4];
	size = count[2] + count[3];
	while (i++ < size)
	{
		digit = ((*a)->index >> shift) & 3;
		if (digit == 2)
			pb(a, b, &operation);
		else if (digit == 3)
			ra(a, &operation);
	}
	while (count[2]--)
		pa(a, b, &operation);
}

static void	partition(t_list **a, t_list **b, int shift, t_ops *operation)
{
	int	count[5];
	int	digit;
	int	i;

	i = 0;
	while (i++ < 4)
		count[i] = 0;
	count[4] = shift;
	bitwise_slice(a, b, &count, &operation);
	refine_stack(a, b, shift, &count);
	while (count[1]--)
		pa(a, b, &operation);
	while (count[0]--)
		pa(a, b, &operation);
}

void	radix_base4(t_list **a, t_list **b, t_ops *operation)
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
		partition(a, b, shift, &operation);
		shift += 2;
		if (is_sorted)
			break ;
	}
}
