/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   16_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbin-mus <mbin-mus@student.42penang.edu    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 20:13:23 by nisim             #+#    #+#             */
/*   Updated: 2026/09/04 19:09:17 by mbin-mus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_list **stack, t_ops *operation, int print)
{
	t_list	*first;
	t_list	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = first;
	while (last->next)
		last = last->next;
	last->prev->next = NULL;
	last->next = first;
	first->prev = last;
	last->prev = NULL;
	*stack = last;
	if (print)
	{
		write(1, "rra\n", 4);
		operation->rra++;
		operation->total++;
	}
}

void	rrb(t_list **stack, t_ops *operation, int print)
{
	t_list	*first;
	t_list	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = first;
	while (last->next)
		last = last->next;
	last->prev->next = NULL;
	last->next = first;
	first->prev = last;
	last->prev = NULL;
	*stack = last;
	if (print)
	{
		write(1, "rrb\n", 4);
		operation->rrb++;
		operation->total++;
	}
}

void	rrr(t_list **stack_a, t_list **stack_b, t_ops *operation)
{
	rra(stack_a, operation, 0);
	rrb(stack_b, operation, 0);
	write(1, "rrr\n", 4);
	operation->rrr++;
	operation->total++;
}
