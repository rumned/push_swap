#include "push_swap.h"

static void    sort_one(t_stack *stack, t_pos current)
{
    if (current == END_A || current == START_B || current == END_B)
        move_to(stack, current, TOP_A);
    return ;
}

static void    sort_two(t_stack *stack, t_pos current)
{
    if (current == END_A || current == START_B || current == END_B)
    {
        move_to(stack, current, TOP_A);
        move_to(stack, current, TOP_A);
    }
    if (stack->a->index > stack->a->next->index)
		sa(&stack->a, stack->operation, 1);
    return ;
}

void    small_sort(t_stack *stack, int size, t_pos current)
{
    if (size == 3)
        sort_three(stack, current);
    else if (size == 2)
        sort_two(stack, current);
    else if (size == 1)
        sort_one(stack, current);
    return ;
}