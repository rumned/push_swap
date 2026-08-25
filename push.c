/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisim <nisim@student.42penang.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 19:09:36 by nisim             #+#    #+#             */
/*   Updated: 2026/08/24 19:41:16 by nisim            ###   ########.fr       */
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
	b->next = a;
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
	a->next = b;
	*stack_b = a;
	write(1, "pb\n", 3);
	operation->pb++;
	operation->total++;
}
