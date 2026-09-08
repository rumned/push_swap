/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   09_sort_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbin-mus <mbin-mus@student.42penang.edu    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 19:22:17 by mbin-mus          #+#    #+#             */
/*   Updated: 2026/09/08 21:24:05 by mbin-mus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_label(t_bench *bench)
{
	static char *const	names[] = {"adaptive", "insertion_sort",
		"chunk_sort", "radix_mix", "adaptive"};
	static char *const	classes[] = {"adaptive", "O(n^2)",
		"O(n sqrt(n))", "O(n log n)", "adaptive"};

	if (bench->mode > ADAPTIVE)
		bench->mode = DEFAULT;
	bench->strategy = names[bench->mode];
	bench->complex_class = classes[bench->mode];
}

void	adaptive_sort(t_list **a, t_list **b, t_bench *bench, t_ops *ops)
{
	float	disorder;

	disorder = bench->disorder;
	if (disorder < 0.2)
		insertion_sort(a, b, ops);
	else if (disorder >= 0.2 && disorder < 0.5)
		chunk_sort(a, b, ops);
	else if (disorder >= 0.5)
		radix_mix(a, b, ops);
}

void	sort_stack(t_list **a, t_list **b, t_bench *bench, t_ops *ops)
{
	set_label(bench);
	if (is_sorted(a))
		return ;
	if (bench->mode == SIMPLE)
		insertion_sort(a, b, ops);
	else if (bench->mode == MEDIUM)
		chunk_sort(a, b, ops);
	else if (bench->mode == COMPLEX)
		radix_mix(a, b, ops);
	else
		adaptive_sort(a, b, bench, ops);
}
