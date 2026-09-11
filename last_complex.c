#include "push_swap.h"

typedef struct s_stack
{
	t_list	*a;
	t_list	*b;
	t_ops	*operation;
}	t_stack;

typedef enum e_position
{
	START_A,
	END_A,
	START_B,
	END_B
}	t_pos;

int	get_max_start(t_list *head, int size)
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

int	get_max_end(t_list * head, int size)
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

void	move_from_sa(t_stack *stack, t_pos to)
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

void	move_from_sb(t_stack *stack, t_pos to)
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

void	move_from_ea(t_stack *stack, t_pos to)
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

void	move_from_eb(t_stack *stack, t_pos to)
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


/*
data 0~2 holds chunk size | 3~5 holds position
  {0, 3} = min;
  {1, 4} = mid;
  {2, 5} = max;
*/
void	recurse_quick(t_stack *stack, int size, t_pos current)
{
	int	data[6];

	if (current == END_A && stack_size(stack->a) == size)
		current = START_A;
	else if (current == END_B && stack_size(stack->b) == size)
		current = START_B;
	if (size <= 3)
		return (small_sort(stack, size, current));
	dual_split(stack, size, current, data);
	recurse_quick(stack, data[2], (t_pos)data[5]);
	recurse_quick(stack, data[1], (t_pos)data[4]);
	recurse_quick(stack, data[0], (t_pos)data[3]);
}

int	get_tail_index(t_list *head)
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

void	next_position(t_pos current, int *data)
{
	if (current == START_A)
	{
		data[3] = END_B;
		data[4] = START_B;
		data[5] = END_A;
	}
	if (current == END_A)
	{
		data[3] = END_B;
		data[4] = START_B;
		data[5] = START_A;
	}
	if (current == START_B)
	{
		data[3] = END_B;
		data[4] = END_A;
		data[5] = START_A;
	}
	if (current == END_B)
	{
		data[3] = START_B;
		data[4] = END_A;
		data[5] = START_A;
	}
}

/*
pivot[2] -> pivot 0 and pivot 1;
== pivot 0 is for max / left ( > piv[0] = max)  ==
== between pivot 0 and pivot 1 is mid           ==
== pivot 1 is for min / right ( < piv[1] = min) ==
 */
void	get_pivot(t_stack *stack, int size, int *pivot, t_pos current)
{
	int	max;
	int	pivot1;
	int	pivot0;

	if (!stack || size <= 0)
		return ;
	max = get_max(stack, size, current);
	pivot0 = size / 3;
	if (current == START_A || current == END_A)
		pivot1 = 2 * size / 3;
	else
		pivot1 = size / 2;
	if ((current == START_A || current == END_A) && size < 15)
		pivot1 = size;
	if (current == END_B && size < 8)
		pivot0 = size / 2;
	pivot[0] = max - pivot0;
	pivot[1] = max - pivot1;
}

void	dual_split(t_stack *stack, int size, t_pos current, int *data)
{
	int	pivot[2];
	int	next_index;	

	data[0] = 0;
	data[1] = 0;
	data[2] = 0;
	next_position(current, data);
	get_pivot(stack, size, pivot, current);
	while (size--)
	{
		next_index = get_next_index(stack, current);
		if (next_index > pivot[0])
			data[2] += move_to(stack, current, (t_pos)data[5]);
		else if (next_index > pivot[1])
			data[1] += move_to(stack, current, (t_pos)data[4]);
		else
			data[0] += move_to(stack, current, (t_pos)data[3]);
	}
}	

void	dual_quicksort(t_list **a, t_list **b, t_ops *operation)
{
	t_stack	stack;
	int	size;

	stack.a = *a;
	stack.b = *b;
	stack.operation = operation;
	size = stack_size(*a);
	recurse_quick(&stack, size, START_A);
	*a = stack.a;
	*b = stack.b;
}
