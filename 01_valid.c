/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbin-mus <mbin-mus@student.42penang.edu    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 20:00:16 by mbin-mus          #+#    #+#             */
/*   Updated: 2026/09/08 20:02:31 by mbin-mus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isnum(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '-')
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	ft_contains(long num, char **args, int i, int count)
{
	i++;
	while (i < count)
	{
		if (ft_atoi(args[i]) == num)
			return (1);
		i++;
	}
	return (0);
}

void	ft_check_args(int ac, char **av, t_flags *flags)
{
	char	**args;
	int		count;
	int		i;
	long	tmp;

	args = build_args(ac, av);
	if (!args)
		ft_error("Error");
	count = count_args(args);
	extract_flags(args, &count, flags);
	i = 0;
	while (i < count)
	{
		tmp = ft_atoi(args[i]);
		if (!ft_isnum(args[i]) || ft_contains(tmp, args, i, count))
			ft_error("Error");
		if (tmp < -2147483648 || tmp > 2147483647)
			ft_error("Error");
		i++;
	}
	ft_free(args);
}

// if the stack is sorted, returns 1
int	is_sorted(t_list **stack)
{
	t_list	*head;

	head = *stack;
	while (head && head->next)
	{
		if (head->value > head->next->value)
			return (0);
		head = head->next;
	}
	return (1);
}

void	ft_error(char *msg)
{
	ft_putendl_fd(msg, 2);
	exit(0);
}
