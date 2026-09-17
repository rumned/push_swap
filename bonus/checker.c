#include "bonus.h"

void	init_both(t_stack *stack)
{
	t_list	**a;
	t_list	**b;

	a = (t_list **)malloc(sizeof(t_list *));
	b = (t_list **)malloc(sizeof(t_list *));
	*a = NULL;
	*b = NULL;
	stack->a = *a;
	stack->b = *b;
	stack->operation = NULL;
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0')
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	is_ops(char *input)
{
	if (!ft_strcmp(input, "pa") || !ft_strcmp(input, "pb"))
		return (1);
	else if (!ft_strcmp(input, "sa") || !ft_strcmp(input, "sb")
			|| !ft_strcmp(input, "ss"))
		return (1);
	else if (!ft_strcmp(input, "ra") || !ft_strcmp(input, "rb")
			|| !ft_strcmp(input, "rr"))
		return (1);
	else if (!ft_strcmp(input, "rra") || !ft_strcmp(input, "rrb")
			|| !ft_strcmp(input, "rrr"))
		return (1);
	return (0);
}

static void	free_all(t_stack *stacks, char **input)
{
	if (input)
		ft_free(input);
	free_stack(&stacks->a);
	free_stack(&stacks->b);
}

int	main(int argc, char **argv)
{
	t_stack	stacks;
	char	*ops_list;
	char	**input;

	if (argc < 2)
		return (0);
	ft_check_args(argc, argv);
	init_both(&stacks);
	init_stack(&stacks.a, argc, argv);
	ops_list = get_next_line(0);
	input = ft_split(ops_list, '\n');
	free(ops_list);
	execute_operation(&stacks, input);
	if (is_sorted(&stacks.a) && !stacks.b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_all(&stacks, input);
	return (0);
}
