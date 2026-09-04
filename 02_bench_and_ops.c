/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_and_ops.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbin-mus <mbin-mus@student.42penang.edu    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 16:16:48 by nisim             #+#    #+#             */
/*   Updated: 2026/09/04 16:30:41 by mbin-mus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_list *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

float	disorder_metric(t_list *stack_a)
{
	t_list	*temp;
	t_list	*comp;
	int		mistake;
	int		total_pairs;
	int		size;

	size = stack_size(stack_a);
	if (size <= 1)
		return (0.0f);
	mistake = 0;
	total_pairs = (size * (size - 1)) / 2;
	temp = stack_a;
	while (temp)
	{
		comp = temp->next;
		while (comp)
		{
			if (temp->index > comp->index)
				mistake++;
			comp = comp->next;
		}
		temp = temp->next;
	}
	return ((float)mistake / total_pairs);
}

void	init_bench(t_bench *bench)
{
	bench->disorder = 0.0;
	bench->strategy = NULL;
	bench->complex_class = NULL;
}

void	init_ops(t_ops *operation)
{
	operation->sa = 0;
	operation->sb = 0;
	operation->ss = 0;
	operation->pa = 0;
	operation->pb = 0;
	operation->ra = 0;
	operation->rb = 0;
	operation->rr = 0;
	operation->rra = 0;
	operation->rrb = 0;
	operation->rrr = 0;
	operation->total = 0;
}

t_bench	calc_disorder(t_list *stack_a)
{
	t_bench	bench;

	init_bench(&bench);
	bench.disorder = disorder_metric(stack_a);
	return (bench);
}

