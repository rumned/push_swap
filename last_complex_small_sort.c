#include "push_swap.h"

void	sort_three_start_a(t_stack *stack, int max)
{
	if (stack->a->index == max)
	{
		sa(&stack->a, stack->operation, 1);
		ra(&stack->a, stack->operation, 1);
		sa(&stack->a, stack->operation, 1);
		rra(&stack->a, stack->operation, 1);
	}
	else if (stack->a->next->index == max)
	{
		ra(&stack->a, stack->operation, 1);
		sa(&stack->a, stack->operation, 1);
		rra(&stack->a, stack->operation, 1);
	}
	sort_two(stack, START_A);
}

void	sort_three_start_b(t_stack *stack, int max)
{
	if (stack->a->index == max)
	{
		sa(&stack->a, stack->operation, 1);
		ra(&stack->a, stack->operation, 1);
		sa(&stack->a, stack->operation, 1);
		rra(&stack->a, stack->operation, 1);
	}
	else if (stack->a->next->index == max)
	{
		ra(&stack->a, stack->operation, 1);
		sa(&stack->a, stack->operation, 1);
		rra(&stack->a, stack->operation, 1);
	}
	sort_two(stack, START_A);
}

void	sort_three(t_stack *stack, t_pos current)
{
	void	(*sort_three_at[4])(t_stack *, int);
	int		max;

	sort_three_at[START_A] = sort_three_start_a;
	sort_three_at[END_A] = sort_three_end_a;
	sort_three_at[START_B] = sort_three_start_b;
	sort_three_at[END_B] = sort_three_end_b;
	max = get_max(stack, 3, current);
	sort_three_pos[current](stack, max);
}
