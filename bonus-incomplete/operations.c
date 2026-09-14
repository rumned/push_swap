/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisim <nisim@student.42penang.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 17:10:06 by nisim             #+#    #+#             */
/*   Updated: 2026/09/14 19:59:05 by nisim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

static void	push(t_stack *stack, char *op)
{
	t_list	**a;
	t_list	**b;

	a = &stack->a;
	b = &stack->b;
	if (!ft_strcmp(op, "pa\n"))
		pa(a, b, NULL, 0);
	else
		pb(a, b, NULL, 0);
}

static void	swap(t_stack *stack, char *op)
{
	t_list	**a;
	t_list	**b;

	a = &stack->a;
	b = &stack->b;
	if (!ft_strcmp(op, "sa\n"))
		sa(a, NULL, 0);
	else if (!ft_strcmp(op, "sb\n"))
		sb(b, NULL, 0);
	else
		ss(a, b, NULL, 0);
}

static void	rotate(t_stack *stack, char *op)
{
	t_list	**a;
	t_list	**b;

	a = &stack->a;
	b = &stack->b;
	if (!ft_strcmp(op, "ra\n"))
		ra(a, NULL, 0);
	else if (!ft_strcmp(op, "rb\n"))
		rb(b, NULL, 0);
	else
		rr(a, b, NULL, 0);
}

static void	reverse_rotate(t_stack *stack, char *op)
{
	t_list	**a;
	t_list	**b;

	a = &stack->a;
	b = &stack->b;
	if (!ft_strcmp(op, "rra\n"))
		rra(a, NULL, 0);
	else if (!ft_strcmp(op, "rrb\n"))
		rrb(b, NULL, 0);
	else
		rrr(a, b, NULL, 0);
}

void	execute_operation(t_list **a, t_list **b, char **input)
{
	int		i;
	t_stack	stack;

	stack.a = *a;
	stack.b = *b;
	stack.operation = NULL;
	i = 0;
	while (input[i])
	{
		if (!ft_strcmp(input[i], "pa\n") || !ft_strcmp(input[i], "pb\n"))
			push(&stack, input[i]);
		else if (!ft_strcmp(input[i], "sa\n") || !ft_strcmp(input[i], "sb\n")
				|| !ft_strcmp(input[i], "ss\n"))
			swap(&stack, input[i]);
		else if (!ft_strcmp(input[i], "ra\n") || !ft_strcmp(input[i], "rb\n")
				|| !ft_strcmp(input[i], "rr\n"))
			rotate(&stack, input[i]);
		else if (!ft_strcmp(input[i], "rra\n") || !ft_strcmp(input[i], "rrb\n")
				|| !ft_strcmp(input[i], "rrr\n"))
			reverse_rotate(&stack, input[i]);
		i++;
	}
}
