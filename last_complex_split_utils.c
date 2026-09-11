/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_complex_split_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisim <nisim@student.42penang.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 15:46:15 by nisim             #+#    #+#             */
/*   Updated: 2026/09/11 18:41:55 by nisim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_start(t_list *head, int size)
{
	int	max;

	if (!head)
		return (-1);
	max = head->index;
	while (size-- && head)
	{
		if (head->index > max)
			max = head->index;
		head = head->next;
	}
	return (max);
}

static int	get_max_end(t_list *head, int size)
{
	int	max;

	if (!head)
		return (-1);
	while (head->next)
		head = head->next;
	max = head->index;
	while (size-- && head)
	{
		if (head->index > max)
			max = head->index;
		head = head->prev;
	}
	return (max);
}

int	get_max(t_stack *stack, int size, t_pos current)
{
	if (current == START_A)
		return (get_max_start(stack->a, size));
	else if (current == START_B)
		return (get_max_start(stack->b, size));
	else if (current == END_A)
		return (get_max_end(stack->a, size));
	else if (current == END_B)
		return (get_max_end(stack->b, size));
	return (-1);
}

static int	get_tail_index(t_list *head)
{
	if (!head)
		return (-1);
	while (head->next)
		head = head->next;
	return (head->index);
}

int	get_next_index(t_stack *stack, t_pos current)
{
	int	next_index;

	next_index = -1;
	if (current == START_A)
		next_index = stack->a->index;
	else if (current == START_B)
		next_index = stack->b->index;
	else if (current == END_A)
		next_index = get_tail_index(stack->a);
	else if (current == END_B)
		next_index = get_tail_index(stack->b);
	return (next_index);
}
