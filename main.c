/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbin-mus <mbin-mus@student.42penang.edu    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/23 16:42:53 by mbin-mus          #+#    #+#             */
/*   Updated: 2026/09/02 21:42:03 by mbin-mus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_op(char *name, int count)
{
	int	i;

	i = 0;
	while (name[i])
		ft_putchar_fd(name[i++], 2);
	ft_putchar_fd(':', 2);
	ft_putchar_fd(' ', 2);
	ft_putnbr_fd(count, 2);
	ft_putchar_fd('\n', 2);
}

void	print_ops(t_ops *operation)
{
	print_op("sa", operation->sa);
	print_op("sb", operation->sb);
	print_op("ss", operation->ss);
	print_op("pa", operation->pa);
	print_op("pb", operation->pb);
	print_op("ra", operation->ra);
	print_op("rb", operation->rb);
	print_op("rr", operation->rr);
	print_op("rra", operation->rra);
	print_op("rrb", operation->rrb);
	print_op("rrr", operation->rrr);
	print_op("total", operation->total);
}

void	print_list(t_list *head)
{
	t_list	*tmp;

	tmp = head;
	while (tmp != NULL)
	{
		ft_putnbr_fd(tmp->value, 1);
		ft_putendl_fd("", 1);
		tmp = tmp->next;
	}
}

int	main(int ac, char **av)
{
	t_list	**stack_a;
	t_list	**stack_b;
	t_ops	operation;
	t_bench bench;

	if (ac < 2)
		return (-1);
	ft_check_args(ac, av);
	stack_a = (t_list **)malloc(sizeof(t_list *));
	stack_b = (t_list **)malloc(sizeof(t_list *));
	init_ops(&operation);
	*stack_a = NULL;
	*stack_b = NULL;
	init_stack(stack_a, ac, av);
	index_stack(stack_a); //indexes stack_a
	if (is_sorted(stack_a))
	{
		free_stack(stack_a);
		free_stack(stack_b);
		return (0);
	}
	bench = calc_disorder(*stack_a);
	sort_stack(stack_a, stack_b, &bench, &operation);
	// print_list(*stack_a);
	// print_list(*stack_b);
	print_ops(&operation);
	print_op("disorder * 100", (int)(bench.disorder * 100));
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
