/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbin-mus <mbin-mus@student.42penang.edu    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 20:00:16 by mbin-mus          #+#    #+#             */
/*   Updated: 2026/09/05 18:49:05 by nisim            ###   ########.fr       */
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

static int	ft_contains(long num, char **argv, int i)
{
	i++;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == num)
			return (1);
		i++;
	}
	return (0);
}

void	ft_check_args(int ac, char **av, t_mode *mode)
{
	char	**args;
	int		start;
	int		end;
	long	tmp;

	args = av;
	start = 1;
	if (ac == 2)
	{
		args = ft_split(av[1], ' '); // Fixed to av[1]
		start = 0;
	}
	end = get_end_index(ac, args);
	extract_flags(args, &start, &end, mode);
	while (start <= end)
	{
		tmp = ft_atoi(args[start]);
		if (!ft_isnum(args[start]) || ft_contains(tmp, args, start))
			ft_error("Error");
		if (tmp < -2147483648 || tmp > 2147483647)
			ft_error("Error");
		start++;
	}
	if (ac == 2)
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
