/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbin-mus <mbin-mus@student.42penang.edu    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 20:00:16 by mbin-mus          #+#    #+#             */
/*   Updated: 2026/08/24 22:19:28 by mbin-mus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// fixed ft_isnum so it doesn't accept "" and "-"
static int	ft_isnum(char *num)
{
	int	i;

	i = 0;
	if (num[i] == '\0')
		return (0);
	if (num[i] == '-' && ft_isdigit(num[i + 1]))
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

/*needs to accept long so it can compare num to temp*/
static int	ft_arg_is_dup(long num, char **argv, int i)
{
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == num)
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
		if (!ft_isnum(args[i]))
			ft_error("Error");
		if (ft_arg_is_dup(tmp, args, i + 1))
			ft_error("Error");
		if (tmp < INT_MIN || tmp > INT_MAX)
			ft_error("Error");
		i++;
	}
	if (argc == 2)
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

// prints out error message to stdout and exits the program
void	ft_error(char *msg)
{
	ft_putendl_fd(msg, 2);
	exit(0);
}
