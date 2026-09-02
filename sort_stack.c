/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbin-mus <mbin-mus@student.42penang.edu    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 19:22:17 by mbin-mus          #+#    #+#             */
/*   Updated: 2026/09/02 18:29:22 by mbin-mus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	adaptive_algo(t_list **a, t_list **b, t_bench *bench, t_ops *operation)
{
	float	disorder;

	disorder = bench->disorder;
	if (disorder < 0.2)
		simple_sort(a, b, &operation);
	else if (disorder >= 0.2 && disorder < 0.5)
		chunk_sort(a, b, &operation);
	else if (disorder >= 0.5)
		radix_base4(a, b, &operation);
}

void sort_stack(t_list **stack_a, t_list **stack_b, t_ops *operation)
{
	int size;

	// We cast stack_b to void since sort_2 and sort_3 don't use it yet
	(void)stack_b; 
	
	size = stack_size(*stack_a);
	if (size == 2)
		sort_2(stack_a, operation);
	else if (size == 3)
		sort_3(stack_a, operation);
	/* Future implementations:
	else if (size <= 5)
		sort_5(stack_a, stack_b, operation);
	else
		radix_base4(stack_a, stack_b, operation);
	*/
}