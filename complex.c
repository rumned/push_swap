/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisim <nisim@student.42penang.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 16:21:51 by nisim             #+#    #+#             */
/*   Updated: 2026/09/06 21:01:54 by nisim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	msd_base2(t_list **a, t_list **b, int *s_mb, t_ops *operation)
{
	int	size;
	int	bit;
	int	item_pb;

	size = s_mb[0];
	bit = s_mb[1];
	item_pb = 0;
	while (size--)
	{
		rra(a, operation, 1);
		if ((((*a)->index >> bit) & 1) == 0)
		{
			pb(a, b, operation);
			item_pb++;
		}
	}
	return (item_pb);
}

static void	refine_a(t_list **a, t_list **b, int *count, t_ops *operation)
{
	int	bit;
	int	size;
	int	digit;
	int	bucket_3;

	size = count[0];
	bit = count[1];
	while (size--)
		rra(a, operation, 1);
	size = count[0];
	count[2] = 0;
	count[3] = 0;
	while (size--)
	{
		digit = ((*a)->index >> bit) & 3;
		count[digit]++;
		if (digit == 2)
			pb(a, b, operation);
		else if (digit == 3)
			ra(a, operation, 1);
	}
	bucket_3 = count[3];
	while (bucket_3--)
		rra(a, operation, 1);
}

static void	recurse_msd_a(t_list **a, t_list **b, int *count, t_ops *ops)
{
	int	next_count[2];

	next_count[1] = count[1] - 2;
	next_count[0] = count[3];
	msd_a(a, b, next_count, ops);
	next_count[0] = count[2];
	msd_b(a, b, next_count, ops);
	while (count[2]--)
		pa(a, b, ops);
	next_count[0] = count[4];
	msd_b(a, b, next_count, ops);
	while (count[4]--)
		pa(a, b, ops);
}

void	msd_a(t_list **a, t_list **b, int *s_mb, t_ops *operation)
{
	int	size;
	int	count[5];

	size = s_mb[0];
	if (size <= 16)
		return (small_sort_a(a, b, size, operation));
	count[0] = 0;
	count[1] = s_mb[1];
	while (size--)
	{
		if ((((*a)->index >> s_mb[1]) & 3) >= 2)
		{
			ra(a, operation, 1);
			count[0]++;
		}
		else
			pb(a, b, operation);
	}
	count[4] = s_mb[0] - count[0];
	refine_a(a, b, count, operation);
	recurse_msd_a(a, b, count, operation);
}

void	radix_msd(t_list **a, t_list **b, t_ops *operation)
{
	int	max_bits;
	int	item_pb;
	int	size_maxbits[2];

	size_maxbits[0] = stack_size(*a);
	max_bits = 0;
	while (((size_maxbits[0] - 1) >> max_bits) != 0)
		max_bits++;
	size_maxbits[1] = max_bits - 1;
	if (max_bits % 2 != 0)
	{
		item_pb = msd_base2(a, b, size_maxbits, operation);
		size_maxbits[0] = stack_size(*a);
		size_maxbits[1] -= 2;
		msd_a(a, b, size_maxbits, operation);
		size_maxbits[0] = item_pb;
		msd_b(a, b, size_maxbits, operation);
		while (item_pb--)
			pa(a, b, operation);
	}
	else
	{
		size_maxbits[1] -= 1;
		msd_a(a, b, size_maxbits, operation);
	}
	write(2, "this is radix\n", 14);
}
