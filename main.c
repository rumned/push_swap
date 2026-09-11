/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbin-mus <mbin-mus@student.42penang.edu    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/23 16:42:53 by mbin-mus          #+#    #+#             */
/*   Updated: 2026/09/11 17:28:44 by nisim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static void	print_list(t_list *head)
// {
// 	t_list	*tmp;

// 	tmp = head;
// 	while (tmp != NULL)
// 	{
// 		ft_putnbr_fd(tmp->value, 1);
// 		ft_putendl_fd("", 1);
// 		tmp = tmp->next;
// 	}
// }

static	void	free_stacks(t_list **stack_a, t_list **stack_b)
{
	free_stack(stack_a);
	free_stack(stack_b);
}

static t_list	**new_stack(void)
{
	t_list	**stack;

	stack = (t_list **)malloc(sizeof(t_list *));
	if (!stack)
		ft_error("Error");
	*stack = NULL;
	return (stack);
}

int	main(int ac, char **av)
{
	t_list	**stack_a;
	t_list	**stack_b;
	t_ops	operation;
	t_bench	bench;
	t_flags	flags;

	if (ac < 2)
		return (-1);
	flags.mode = DEFAULT;
	flags.bench = 0;
	ft_check_args(ac, av, &flags);
	stack_a = new_stack();
	stack_b = new_stack();
	init_ops(&operation);
	init_stack(stack_a, ac, av);
	bench = calc_disorder(*stack_a);
	bench.mode = flags.mode;
	sort_stack(stack_a, stack_b, &bench, &operation);
	if (flags.bench)
		print_bench(&operation, &bench);
	free_stacks(stack_a, stack_b);
	return (0);
}
