/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   09_sort_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbin-mus <mbin-mus@student.42penang.edu    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 19:22:17 by mbin-mus          #+#    #+#             */
/*   Updated: 2026/09/11 18:16:18 by nisim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_label(t_bench *bench)
{
	static char *const	names[] = {"Adaptive", "Insertion sort",
		"Chunk sort", "Quick sort", "Adaptive"};
	static char *const	classes[] = {"Adaptive", "O(n²)",
		"O(n√n))", "O(n log n)", "Adaptive"};

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
	{
		insertion_sort(a, b, ops);
		bench->complex_class = "O(n²)";
	}
	else if (disorder >= 0.2 && disorder < 0.5)
	{
		chunk_sort(a, b, ops);
		bench->complex_class = "O(n√n)";
	}
	else if (disorder >= 0.5)
	{
		dual_quicksort(a, b, ops);
		bench->complex_class = "O(n log n)";
	}
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
		dual_quicksort(a, b, ops);
	else
		adaptive_sort(a, b, bench, ops);
}
