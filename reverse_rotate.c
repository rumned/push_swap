/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisim <nisim@student.42penang.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 20:13:23 by nisim             #+#    #+#             */
/*   Updated: 2026/08/24 21:24:43 by nisim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_list **stack, t_ops *operation, int print)
{
	t_list	*first;
	t_list	*last;
	t_list	*prev;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = first;
	prev = NULL;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = first;
	*stack = last;
	if (print)
	{
		write(1, "rra\n", 3);
		operation->rra++;
		operation->total++;
	}
}

void	rrb(t_list **stack, t_ops *operation, int print)
{
	t_list	*first;
	t_list	*last;
	t_list	*prev;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = first;
	prev = NULL;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = first;
	*stack = last;
	if (print)
	{
		write(1, "rrb\n", 3);
		operation->rrb++;
		operation->total++;
	}
}

void	rrr(t_list **stack_a, t_list **stack_b, t_ops *operation)
{
	rra(stack_a, operation, 0);
	rrb(stack_b, operation, 0);
	write(1, "rrr\n", 3);
	operation->rrr++;
	operation->total++;
}

