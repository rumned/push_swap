/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   14_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbin-mus <mbin-mus@student.42penang.edu    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 18:48:27 by nisim             #+#    #+#             */
/*   Updated: 2026/09/04 19:09:10 by mbin-mus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **stack, t_ops *operation, int print)
{
	t_list	*first;
	t_list	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	if (first->next)
		first->next->prev = first;
	second->prev = first->prev;
	first->prev = second;
	second->prev = NULL;
	*stack = second;
	if (print)
	{
		write(1, "sa\n", 3);
		operation->sa++;
		operation->total++;
	}
}

void	sb(t_list **stack, t_ops *operation, int print)
{
	t_list	*first;
	t_list	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	if (first->next)
		first->next->prev = first;
	second->prev = first->prev;
	first->prev = second;
	second->prev = NULL;
	*stack = second;
	if (print)
	{
		write(1, "sb\n", 3);
		operation->sb++;
		operation->total++;
	}
}

void	ss(t_list **stack_a, t_list **stack_b, t_ops *operation)
{
	sa(stack_a, operation, 0);
	sb(stack_b, operation, 0);
	write(1, "ss\n", 3);
	operation->ss++;
	operation->total++;
}
