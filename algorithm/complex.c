/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_complex_split.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisim <nisim@student.42penang.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 15:46:05 by nisim             #+#    #+#             */
/*   Updated: 2026/09/11 15:50:59 by nisim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	next_position(t_pos current, int *data)
{
	if (current == START_A)
	{
		data[3] = END_B;
		data[4] = START_B;
		data[5] = END_A;
	}
	if (current == END_A)
	{
		data[3] = END_B;
		data[4] = START_B;
		data[5] = START_A;
	}
	if (current == START_B)
	{
		data[3] = END_B;
		data[4] = END_A;
		data[5] = START_A;
	}
	if (current == END_B)
	{
		data[3] = START_B;
		data[4] = END_A;
		data[5] = START_A;
	}
}

/*
pivot[2] -> pivot 0 and pivot 1;
== pivot 0 is for max / left ( > piv[0] = max)  ==
== between pivot 0 and pivot 1 is mid           ==
== pivot 1 is for min / right ( < piv[1] = min) ==
 */
static void	get_pivot(t_stack *stack, int size, int *pivot, t_pos current)
{
	int	max;
	int	pivot1;
	int	pivot0;

	if (!stack || size <= 0)
		return ;
	max = get_max(stack, size, current);
	pivot0 = size / 3;
	if (current == START_A || current == END_A)
		pivot1 = 2 * size / 3;
	else
		pivot1 = size / 2;
	if ((current == START_A || current == END_A) && size < 15)
		pivot1 = size;
	if (current == END_B && size < 8)
		pivot0 = size / 2;
	pivot[0] = max - pivot0;
	pivot[1] = max - pivot1;
}

static void	dual_split(t_stack *stack, int size, t_pos current, int *data)
{
	int	pivot[2];
	int	next_index;	

	data[0] = 0;
	data[1] = 0;
	data[2] = 0;
	next_position(current, data);
	get_pivot(stack, size, pivot, current);
	while (size--)
	{
		next_index = get_next_index(stack, current);
		if (next_index > pivot[0])
			data[2] += move_to(stack, current, (t_pos)data[5]);
		else if (next_index > pivot[1])
			data[1] += move_to(stack, current, (t_pos)data[4]);
		else
			data[0] += move_to(stack, current, (t_pos)data[3]);
	}
}

/*
== data 0~2 holds chunk size | 3~5 holds position ==
==        {0, 3} = min/smaller index value        ==
==        {1, 4} = mid                            ==
==        {2, 5} = max/bigger index value         ==
*/
static void	recurse_quick(t_stack *stack, int size, t_pos current)
{
	int	data[6];

	if (current == END_A && stack_size(stack->a) == size)
		current = START_A;
	else if (current == END_B && stack_size(stack->b) == size)
		current = START_B;
	if (size <= 3)
		return (small_sort(stack, size, current));
	dual_split(stack, size, current, data);
	recurse_quick(stack, data[2], (t_pos)data[5]);
	recurse_quick(stack, data[1], (t_pos)data[4]);
	recurse_quick(stack, data[0], (t_pos)data[3]);
}

void	dual_quicksort(t_list **a, t_list **b, t_ops *operation)
{
	t_stack	stack;
	int		size;

	stack.a = *a;
	stack.b = *b;
	stack.operation = operation;
	size = stack_size(*a);
	recurse_quick(&stack, size, START_A);
	*a = stack.a;
	*b = stack.b;
}
