/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   20_parse_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbin-mus <mbin-mus@student.42penang.edu    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 14:31:45 by nisim             #+#    #+#             */
/*   Updated: 2026/09/05 19:18:53 by mbin-mus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_mode	is_flag(char *str)
{
	if (ft_strcmp(str, "--simple") == 0)
		return(SIMPLE);
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


void	extract_flags(char **args, int *start, int *end, t_mode *mode)
{
	t_mode	flag_start;
	t_mode	flag_end;

	flag_start = is_flag(args[*start]);
	if (flag_start != DEFAULT)
	{
		*mode = flag_start;
		(*start)++;
	}
	if (*mode == DEFAULT && *end >= *start)
	{
		flag_end = is_flag(args[*end]);
		if (flag_end != DEFAULT)
		{
			*mode = flag_end;
			(*end)--;
		}
	}
}
