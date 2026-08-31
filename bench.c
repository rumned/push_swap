/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisim <nisim@student.42penang.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 16:16:48 by nisim             #+#    #+#             */
/*   Updated: 2026/08/24 18:43:54 by nisim            ###   ########.fr       */
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
	bench.disorder = 0.0;
	bench.strategy = NULL;
	bench.complex_class = NULL;
}

t_bench	calc_disorder(t_list *stack_a)
{
	t_bench	bench;

	init_bench(&bench);
	bench.disorder = disorder_metric(stack_a);
	return (bench);
}
