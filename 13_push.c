/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   13_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbin-mus <mbin-mus@student.42penang.edu    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 19:09:36 by nisim             #+#    #+#             */
/*   Updated: 2026/09/04 19:09:13 by mbin-mus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_list **stack_a, t_list **stack_b, t_ops *operation)
{
	t_list	*a;
	t_list	*b;

	if (!stack_a || !*stack_b || !stack_b)
		return ;
	a = *stack_a;
	b = *stack_b;
	*stack_b = (*stack_b)->next;
	if (*stack_b)
		(*stack_b)->prev = NULL;
	b->prev = NULL;
	b->next = a;
	if (a)
		a->prev = b;
	*stack_a = b;
	write(1, "pa\n", 3);
	operation->pa++;
	operation->total++;
}

void	pb(t_list **stack_a, t_list **stack_b, t_ops *operation)
{
	t_list	*a;
	t_list	*b;

	if (!stack_a || !*stack_a || !stack_b)
		return ;
	a = *stack_a;
	b = *stack_b;
	*stack_a = (*stack_a)->next;
	if (*stack_a)
		(*stack_a)->prev = NULL;
	a->prev = NULL;
	a->next = b;
	if (b)
		b->prev = a;
	*stack_b = a;
	write(1, "pb\n", 3);
	operation->pb++;
	operation->total++;
}
