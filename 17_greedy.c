/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   17_greedy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbin-mus <mbin-mus@student.42penang.edu    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 21:40:00 by mbin-mus          #+#    #+#             */
/*   Updated: 2026/09/04 23:03:32 by mbin-mus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* c[0] = rotations owed by a, c[1] = rotations owed by b */
static void	shared_rot(t_list **a, t_list **b, int c[2], t_ops *operation)
{
	while (c[0] > 0 && c[1] > 0)
	{
		rr(a, b, operation);
		c[0]--;
		c[1]--;
	}
	while (c[0] < 0 && c[1] < 0)
	{
		rrr(a, b, operation);
		c[0]++;
		c[1]++;
	}
}

static void	solo_rot(t_list **a, t_list **b, int c[2], t_ops *operation)
{
	while (c[0] > 0 && c[0]--)
		ra(a, operation, 1);
	while (c[0] < 0 && c[0]++)
		rra(a, operation, 1);
	while (c[1] > 0 && c[1]--)
		rb(b, operation, 1);
	while (c[1] < 0 && c[1]++)
		rrb(b, operation, 1);
}

static t_list	*node_at(t_list *stack, int pos)
{
	while (pos-- > 0 && stack)
		stack = stack->next;
	return (stack);
}

/* best[0] = cheapest cost found, best[1] = its position in b */
static void	cheapest(t_list **a, t_list **b, int best[2])
{
	int		pos;
	int		cost;
	int		size_a;
	int		size_b;
	t_list	*tmp;

	tmp = *b;
	pos = 0;
	size_a = stack_size(*a);
	size_b = stack_size(*b);
	best[0] = 0;
	best[1] = 0;
	while (tmp)
	{
		cost = combined(rot_cost(insert_pos(*a, tmp->value), size_a),
				rot_cost(pos, size_b));
		if (pos == 0 || cost < best[0])
		{
			best[0] = cost;
			best[1] = pos;
		}
		tmp = tmp->next;
		pos++;
	}
}

void	greedy_pop(t_list **a, t_list **b, t_ops *operation)
{
	int	best[2];
	int	c[2];

	if (!*a)
		pa(a, b, operation);
	while (*b)
	{
		cheapest(a, b, best);
		c[1] = rot_cost(best[1], stack_size(*b));
		c[0] = rot_cost(insert_pos(*a, node_at(*b, best[1])->value),
				stack_size(*a));
		shared_rot(a, b, c, operation);
		solo_rot(a, b, c, operation);
		pa(a, b, operation);
	}
	c[0] = rot_cost(pos_of_min(*a), stack_size(*a));
	c[1] = 0;
	solo_rot(a, b, c, operation);
}
