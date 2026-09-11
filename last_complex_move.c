#include "push_swap.h"

static void	move_from_sa(t_stack *stack, t_pos to)
{
	if (to == START_B)
		pb(&stack->a, &stack->b, stack->operation);
	else if (to == END_A)
		ra(&stack->a, stack->operation, 1);
	else if (to == END_B)
	{
		pb(&stack->a, &stack->b, stack->operation);
		rb(&stack->b, stack->operation, 1);
	}
}

static void	move_from_sb(t_stack *stack, t_pos to)
{
	if (to == START_A)
		pa(&stack->a, &stack->b, stack->operation);
	else if (to == END_B)
		rb(&stack->b, stack->operation, 1);
	else if (to == END_A)
	{
		pa(&stack->a, &stack->b, stack->operation);
		ra(&stack->a, stack->operation, 1);
	}
}

static void	move_from_ea(t_stack *stack, t_pos to)
{
	if (to == START_A)
		rra(&stack->a, stack->operation);
	else if (to == START_B)
	{
		rra(&stack->a, stack->operation, 1);
		pb(&stack->b, stack->operation);
	}
	else if (to == END_B)
	{
		rra(&stack->a, stack->operation, 1);
		pb(&stack->a, &stack->b, stack->operation);
		rb(&stack->b, stack->operation, 1);
	}
}

static void	move_from_eb(t_stack *stack, t_pos to)
{
	if (to == START_B)
		rrb(&stack->b, stack->operation);
	else if (to == START_A)
	{
		rrb(&stack->b, stack->operation, 1);
		pa(&stack->a, &stack->b, stack->operation);
	}
	else if (to == END_A)
	{
		rrb(&stack->b, stack->operation, 1);
		pa(&stack->a, &stack->b, stack->operation);
		rb(&stack->a, stack->operation, 1);
	}
}

int	move_to(t_stack *stack, t_pos from, t_pos to)
{
	void	(*move_from[4])(t_stack *, t_pos);

	move_from[START_A] = move_from_sa;
	move_from[END_A] = move_from_ea;
	move_from[START_B] = move_from_sb;
	move_from[END_B] = move_from_eb;

	move_from[from](stack, to);
	return (1);
}