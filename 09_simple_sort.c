/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbin-mus <mbin-mus@student.42penang.edu    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 22:53:27 by mbin-mus          #+#    #+#             */
/*   Updated: 2026/09/04 16:08:16 by mbin-mus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void sort_2(t_list **stack_a, t_ops *operation)
// {
//     if(!stack_a || !*stack_a || !(*stack_a)->next)
//         return ;
//     if((*stack_a)->value > (*stack_a)->next->value)
//         sa(stack_a, operation, 1);
// }

static int	find_max_pos(t_list *stack)
{
	int	pos;
	int	best;
	int	best_val;
 
	pos = 0;
	best = 0;
	best_val = stack->value;
	while (stack)
	{
		if (stack->value > best_val)
		{
			best_val = stack->value;
			best = pos;
		}
		stack = stack->next;
		pos++;
	}
	return (best);
}
 
/* position that must be on top of b before pushing value onto it */
static int	find_target(t_list *stack_b, int value)
{
	int		pos;
	int		best;
	int		best_val;
	t_list	*hldr;
 
	hldr = stack_b;
	pos = 0;
	best = -1;
	best_val = 0;
	while (hldr)
	{
		if (hldr->value < value && (best == -1 || hldr->value > best_val))
		{
			best_val = hldr->value;
			best = pos;
		}
		hldr = hldr->next;
		pos++;
	}
	if (best == -1)
		return (find_max_pos(stack_b));
	return (best);
}
 
void	insertion_sort(t_list **stack_a, t_list **stack_b, t_ops *operation)
{
	int	target;
 
	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	while (*stack_a)
	{
		if (*stack_b)
		{
			target = find_target(*stack_b, (*stack_a)->value);
			rotate_b_to(stack_b, operation, target);
		}
		pb(stack_a, stack_b, operation);
	}
	rotate_b_to(stack_b, operation, find_max_pos(*stack_b));
	while (*stack_b)
		pa(stack_a, stack_b, operation);
}
