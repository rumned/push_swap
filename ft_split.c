/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbin-mus <mbin-mus@student.42penang.edu    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 20:14:40 by mbin-mus          #+#    #+#             */
/*   Updated: 2026/08/24 20:22:14 by mbin-mus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	count_words(char const *s, char c)
{
	size_t	word_count;
	int		is_word;
	int		i;

	i = 0;
	word_count = 0;
	is_word = 0;
	while (s[i])
	{
		if ((s[i] != c) && (is_word == 0))
		{
			word_count++;
			is_word = 1;
		}
		if ((s[i] == c) && (is_word == 1))
			is_word = 0;
		i++;
	}
	return (word_count);
}

static	void	free_array_2d(char **arr2d, size_t i)
{
	while (i-- > 0)
		free(arr2d[i]);
	free(arr2d);
}

static int	splitter(char const *s, char c, char **res, size_t word_count)
{
	unsigned int	lead;
	unsigned int	edge;
	size_t			i;

	lead = 0;
	i = 0;
	while (i < word_count)
	{
		while ((s[lead]) && s[lead] == c)
			lead++;
		edge = lead;
		while ((s[edge]) && s[edge] != c)
			edge++;
		res[i] = ft_substr(s, lead, (size_t)(edge - lead));
		if (!res[i])
		{
			free_array_2d(res, i);
			return (1);
		}
		lead = edge;
		i++;
	}
	res[i] = NULL;
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	word_count;

	if (!s)
		return (NULL);
	word_count = count_words(s, c);
	res = (char **)malloc((word_count + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	if (splitter(s, c, res, word_count) != 0)
		return (NULL);
	return (res);
}
