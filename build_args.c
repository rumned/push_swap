/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   22_build_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbin-mus <mbin-mus@student.42penang.edu    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 20:49:43 by mbin-mus          #+#    #+#             */
/*   Updated: 2026/09/11 17:27:55 by nisim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*join_args(int ac, char **av)
{
	char	*joined;
	char	*tmp;
	int		i;

	joined = ft_strdup("");
	i = 1;
	while (joined && i < ac)
	{
		tmp = ft_strjoin(joined, " ");
		free(joined);
		joined = NULL;
		if (tmp)
		{
			joined = ft_strjoin(tmp, av[i]);
			free(tmp);
		}
		i++;
	}
	return (joined);
}

char	**build_args(int ac, char **av)
{
	char	*joined;
	char	**args;

	joined = join_args(ac, av);
	if (!joined)
		return (NULL);
	args = ft_split(joined, ' ');
	free(joined);
	return (args);
}

int	count_args(char **args)
{
	int	n;

	n = 0;
	while (args[n])
		n++;
	return (n);
}
