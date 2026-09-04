/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   08_sort_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbin-mus <mbin-mus@student.42penang.edu    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 19:22:17 by mbin-mus          #+#    #+#             */
/*   Updated: 2026/09/04 16:36:46 by mbin-mus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_list **a, t_list **b, t_bench *bench, t_ops *operation)
{
	float	disorder;

	disorder = bench->disorder;
	if (disorder < 0.2)
		insertion_sort(a, b, operation);
	// else if (disorder >= 0.2 && disorder < 0.5)
	else
		chunk_sort(a, b, operation);
	// else if (disorder >= 0.5)
	// 	radix_base4(a, b, operation);
}
