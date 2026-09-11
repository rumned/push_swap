#include "push_swap.h"

static void	sort_three_start_a(t_list **a, t_list **b, int, t_ops *ops)
{
	(void)b;
	if ((*a)->index == max)
	{
		sa(a, ops, 1);
		ra(a, ops, 1);
		sa(a, ops, 1);
		rra(a, ops, 1);
	}
	else if ((*a)->next->index == max)
	{
		ra(a, ops, 1);
		sa(a, ops, 1);
		rra(a, ops, 1);
	}
	if ((*a)->index > (*a)->next->index)
		sa(a, ops, 1);
}

static void	sort_three_start_b(t_list **a, t_list **b, int, t_ops *ops)
{
	pa(a, b, ops);
	if ((*b)->index == max)
	{
		pa(a, b, ops);
		sa(a, ops, 1);
	}
	else if ((*b)->next->index == max)
	{
		sb(b, ops, 1);
		pa(a, b, ops);
		sa(a, ops, 1);
	}
	else
		pa(a, b, ops);
	pa(a, b, ops);
	if ((*a)->index > (*a)->next->index)
		sa(a, ops, 1);
}

static void	sort_three_end_a(t_list **a, t_list **b, int, t_ops *ops)
{
	rra(a, ops);
	rra(a, ops);
	if ((*a)->index == max)
	{
		sa(a, ops, 1);
		rra(a, ops, 1);
	}
	else if ((*a)->next->index == max)
		rra(a, ops, 1);
	else
	{
		pb(a, b, ops)
		rra(a, ops, 1);
		sa(a, ops, 1);
		pa(a, b, ops, 1);
	}
	if ((*a)->index > (*a)->next->index)
		sa(a, ops, 1);
}

static void	sort_three_end_b(t_list **a, t_list **b, int, t_ops *ops)
{
	rrb(b, ops, 1);
	rrb(a, ops, 1);
	if ((*b)->index == max)
	{
		pa(a, b, ops);
		rrb(b, ops, 1);
	}
	else if ((*b)->next->index == max)
	{
		sb(b, ops, 1);
		pa(a, b, ops);
		rrb(b, ops, 1);
	}
	else
	{
		rrb(b, ops, 1);
		pa(a, b, ops, 1);
	}
	pa(a, b, ops);
	pa(a, b, ops);
	if ((*a)->index > (*a)->next->index)
		sa(a, ops, 1);
}

void	sort_three(t_stack *stack, t_pos current)
{
	void	(*sort_three_at[4])(t_list **, t_list **, int, t_ops *);
	int		max;

	sort_three_at[START_A] = sort_three_start_a;
	sort_three_at[END_A] = sort_three_end_a;
	sort_three_at[START_B] = sort_three_start_b;
	sort_three_at[END_B] = sort_three_end_b;
	max = get_max(stack, 3, current);
	sort_three_pos[current](&stack->a, &stack->b, max, stack->operation);
}