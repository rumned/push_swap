/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_complex_move.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisim <nisim@student.42penang.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 15:45:34 by nisim             #+#    #+#             */
/*   Updated: 2026/09/11 15:48:37 by nisim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_from_sa(t_list **a, t_list **b, t_ops *ops, t_pos to)
{
	if (to == START_B)
		pb(a, b, ops);
	else if (to == END_A)
		ra(a, ops, 1);
	else if (to == END_B)
	{
		pb(a, b, ops);
		rb(b, ops, 1);
	}
}

static void	move_from_sb(t_list **a, t_list **b, t_ops *ops, t_pos to)
{
	if (to == START_A)
		pa(a, b, ops);
	else if (to == END_B)
		rb(b, ops, 1);
	else if (to == END_A)
	{
		pa(a, b, ops);
		ra(a, ops, 1);
	}
}

static void	move_from_ea(t_list **a, t_list **b, t_ops *ops, t_pos to)
{
	if (to == START_A)
		rra(a, ops, 1);
	else if (to == START_B)
	{
		rra(a, ops, 1);
		pb(a, b, ops);
	}
	else if (to == END_B)
	{
		rra(a, ops, 1);
		pb(a, b, ops);
		rb(b, ops, 1);
	}
}

static void	move_from_eb(t_list **a, t_list **b, t_ops *ops, t_pos to)
{
	if (to == START_B)
		rrb(b, ops, 1);
	else if (to == START_A)
	{
		rrb(b, ops, 1);
		pa(a, b, ops);
	}
	else if (to == END_A)
	{
		rrb(b, ops, 1);
		pa(a, b, ops);
		rb(a, ops, 1);
	}
}

int	move_to(t_stack *stack, t_pos from, t_pos to)
{
	void	(*move_from[4])(t_list **, t_list **, t_ops *, t_pos);

	move_from[START_A] = move_from_sa;
	move_from[END_A] = move_from_ea;
	move_from[START_B] = move_from_sb;
	move_from[END_B] = move_from_eb;
	move_from[from](&stack->a, &stack->b, stack->operation, to);
	return (1);
}
