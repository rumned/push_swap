/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbin-mus <mbin-mus@student.42penang.edu    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 19:22:17 by mbin-mus          #+#    #+#             */
/*   Updated: 2026/09/02 21:53:16 by mbin-mus         ###   ########.fr       */
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
	// 	chunk_sort(a, b, &operation);
	// else if (disorder >= 0.5)
	else
		radix_base4(a, b, operation);
}
