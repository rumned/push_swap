/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   20_parse_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbin-mus <mbin-mus@student.42penang.edu    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 14:31:45 by nisim             #+#    #+#             */
/*   Updated: 2026/09/08 20:00:59 by mbin-mus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_mode	is_flag(char *str)
{
	if (ft_strcmp(str, "--simple") == 0)
		return (SIMPLE);
	if (ft_strcmp(str, "--medium") == 0)
		return (MEDIUM);
	if (ft_strcmp(str, "--complex") == 0)
		return (COMPLEX);
	if (ft_strcmp(str, "--adaptive") == 0)
		return (ADAPTIVE);
	if (ft_strcmp(str, "--bench") == 0)
		return (BENCH);
	return (DEFAULT);
}

int	get_end_index(int ac, char **args)
{
	int	end;

	if (ac == 2)
	{
		end = 0;
		while (args[end])
			end++;
		return (end - 1);
	}
	return (ac - 1);
}

static int	take_flag(char *arg, t_flags *flags)
{
	t_mode	flag;

	flag = is_flag(arg);
	if (flag == DEFAULT)
		return (0);
	if (flag == BENCH)
	{
		if (flags->bench)
			ft_error("Error");
		flags->bench = 1;
		return (1);
	}
	if (flags->mode != DEFAULT)
		ft_error("Error");
	flags->mode = flag;
	return (1);
}

void	extract_flags(char **args, int *count, t_flags *flags)
{
	int	i;
	int	w;

	i = 0;
	w = 0;
	while (i < *count)
	{
		if (take_flag(args[i], flags))
			free(args[i]);
		else
			args[w++] = args[i];
		i++;
	}
	args[w] = NULL;
	*count = w;
}
