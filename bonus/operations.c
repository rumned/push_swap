/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisim <nisim@student.42penang.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 17:10:06 by nisim             #+#    #+#             */
/*   Updated: 2026/09/21 15:41:35 by nisim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

static void	push(t_stack *stack, char *op)
{
	t_list	**a;
	t_list	**b;

	a = &stack->a;
	b = &stack->b;
	if (!ft_strcmp(op, "pa"))
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
	if (!ft_strcmp(op, "sa"))
		sa(a, NULL, 0);
	else if (!ft_strcmp(op, "sb"))
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
	if (!ft_strcmp(op, "ra"))
		ra(a, NULL, 0);
	else if (!ft_strcmp(op, "rb"))
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
	if (!ft_strcmp(op, "rra"))
		rra(a, NULL, 0);
	else if (!ft_strcmp(op, "rrb"))
		rrb(b, NULL, 0);
	else
		rrr(a, b, NULL, 0);
}

void	execute_operation(t_stack *stack, char **input)
{
	int		i;

	i = 0;
	while (input && input[i])
	{
		if (!is_ops(input[i]))
		{
			write(2, "Error\n", 6);
			free_all(&stacks, input);
			exit(0);
		}
		if (!ft_strcmp(input[i], "pa") || !ft_strcmp(input[i], "pb"))
			push(stack, input[i]);
		else if (!ft_strcmp(input[i], "sa") || !ft_strcmp(input[i], "sb")
			|| !ft_strcmp(input[i], "ss"))
			swap(stack, input[i]);
		else if (!ft_strcmp(input[i], "ra") || !ft_strcmp(input[i], "rb")
			|| !ft_strcmp(input[i], "rr"))
			rotate(stack, input[i]);
		else if (!ft_strcmp(input[i], "rra") || !ft_strcmp(input[i], "rrb")
			|| !ft_strcmp(input[i], "rrr"))
			reverse_rotate(stack, input[i]);
		i++;
	}
}
