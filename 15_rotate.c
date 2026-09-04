/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   15_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbin-mus <mbin-mus@student.42penang.edu    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 19:41:24 by nisim             #+#    #+#             */
/*   Updated: 2026/09/04 19:09:07 by mbin-mus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **stack, t_ops *operation, int print)
{
	t_list	*stack_a;
	t_list	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	stack_a = *stack;
	last = stack_a;
	while (last->next)
		last = last->next;
	last->next = stack_a;
	stack_a->prev = last;
	stack_a->next->prev = NULL;
	*stack = stack_a->next;
	stack_a->next = NULL;
	if (print)
	{
		write(1, "ra\n", 3);
		operation->ra++;
		operation->total++;
	}
}

void	rb(t_list **stack, t_ops *operation, int print)
{
	t_list	*stack_b;
	t_list	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	stack_b = *stack;
	last = stack_b;
	while (last->next)
		last = last->next;
	last->next = stack_b;
	stack_b->prev = last;
	stack_b->next->prev = NULL;
	*stack = stack_b->next;
	stack_b->next = NULL;
	if (print)
	{
		write(1, "rb\n", 3);
		operation->rb++;
		operation->total++;
	}
}

void	rr(t_list **stack_a, t_list **stack_b, t_ops *operation)
{
	ra(stack_a, operation, 0);
	rb(stack_b, operation, 0);
	write(1, "rr\n", 3);
	operation->rr++;
	operation->total++;
}
