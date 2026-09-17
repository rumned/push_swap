/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisim <nisim@student.42penang.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 22:08:32 by nisim             #+#    #+#             */
/*   Updated: 2026/09/14 22:08:46 by nisim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

static long	ft_atoi(const char *nptr)
{
	int		i;
	long	neg;
	long	result;
	long	sign_flag;

	i = 0;
	neg = 1;
	result = 0;
	sign_flag = 0;
	while ((nptr[i] >= '\t' && nptr[i] <= '\r') || nptr[i] == ' ')
		i++;
	while ((nptr[i] == '-' || nptr[i] == '+') && sign_flag == 0)
	{
		if (nptr[i] == '-')
			neg *= -1;
		sign_flag = 1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (result * neg);
}

static int	ft_isnum(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '-')
		i++;
	while (num[i])
	{
		if (num[i] < '0' || num[i] > '9')
			return (0);
		i++;
	}
	if (ft_atoi(num) < -2147483648 || ft_atoi(num) > 2147483647)
		return (0);
	return (1);
}

static int	ft_isdup(long num, char **args, int i)
{
	i++;
	while (args[i])
	{
		if (ft_atoi(args[i]) == num)
			return (1);
		i++;
	}
	return (0);
}

void	ft_check_args(int argc, char **argv)
{
	int		i;
	long	tmp;
	char	**args;

	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		args = argv;
	}
	while (args[i])
	{
		tmp = ft_atoi(args[i]);
		if (!ft_isnum(args[i]) || ft_isdup(tmp, args, i))
		{
			write(2, "Error\n", 6);
			exit(0);
		}
		i++;
	}
	if (argc == 2)
		ft_free(args);
}

void	init_stack(t_list **stack, int ac, char **av)
{
	t_list	*new;
	char	**args;
	int		i;

	i = 0;
	if (ac == 2)
		args = ft_split(av[1], ' ');
	else
	{
		i = 1;
		args = av;
	}
	while (args[i])
	{
		new = ft_lstnew_int(ft_atoi(args[i]));
		ft_lstadd_back(stack, new);
		i++;
	}
	if (ac == 2)
		ft_free(args);
}
