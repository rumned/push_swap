/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisim <nisim@student.42penang.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 18:16:40 by nisim             #+#    #+#             */
/*   Updated: 2026/09/06 21:04:59 by nisim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	refine_b(t_list **a, t_list **b, int *count, t_ops *operation)
{
	int	bit;
	int	size;
	int	digit;
	int	bucket_0;

	size = count[0];
	bit = count[1];
	while (size--)
		rrb(b, operation, 1);
	size = count[0];
	count[2] = 0;
	count[3] = 0;
	while (size--)
	{
		digit = ((*b)->index >> bit) & 3;
		count[digit + 2]++;
		if (digit == 0)
			rb(b, operation, 1);
		else if (digit == 1)
			pa(a, b, operation);
	}
	bucket_0 = count[2];
	while (bucket_0--)
		rrb(b, operation, 1);
}

static void	recurse_msd_b(t_list **a, t_list **b, int *count, t_ops *ops)
{
	int	next_count[2];
	int	bucket_0;

	next_count[1] = count[1] - 2;
	next_count[0] = count[3];
	msd_a(a, b, next_count, ops);
	bucket_0 = count[2];
	while (bucket_0--)
		pa(a, b, ops);
	next_count[0] = count[2];
	msd_a(a, b, next_count, ops);
	next_count[0] = count[4];
	msd_a(a, b, next_count, ops);
}

void	msd_b(t_list **a, t_list **b, int *s_mb, t_ops *operation)
{
	int	size;
	int	count[5];

	size = s_mb[0];
	if (size <= 16)
		return (small_sort_b(a, b, size, operation));
	count[0] = 0;
	count[1] = s_mb[1];
	while (size--)
	{
		if ((((*b)->index >> s_mb[1]) & 3) >= 2)
			pa(a, b, operation);
		else
		{
			rb(b, operation, 1);
			count[0]++;
		}
	}
	count[4] = s_mb[0] - count[0];
	refine_b(a, b, count, operation);
	recurse_msd_b(a, b, count, operation);
}
