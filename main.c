/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbin-mus <mbin-mus@student.42penang.edu    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/23 16:42:53 by mbin-mus          #+#    #+#             */
/*   Updated: 2026/09/01 19:40:58 by mbin-mus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	t_ops	**operation;

	if (ac < 2)
		return (-1);
	ft_check_args(ac, av);
	stack_a = (t_list **)malloc(sizeof(t_list *));
	stack_b = (t_list **)malloc(sizeof(t_list *));
	operation = (t_ops **)malloc(sizeof(t_ops *));
	*operation = (t_ops *)malloc(sizeof(t_ops));
	*stack_a = NULL;
	*stack_b = NULL;
	init_stack(stack_a, ac, av);
	index_stack(stack_a); //indexes stack_a
	if (is_sorted(stack_a))
	{
		free_stack(stack_a);
		free_stack(stack_b);
		free(*operation); //might need to write a separate one
		free(operation);
		return (0);
	}
	// needs a function to commence sorting (sort_stack etc)
	sort_stack(stack_a, stack_b, *operation);
	print_list(*stack_a);
	print_list(*stack_b);
	// print_list(*operation); need a separate fn to print ops
	free_stack(stack_a);
	free_stack(stack_b);
	free(*operation); //might need to write a separate one
	free(operation);
	return (0);
}
