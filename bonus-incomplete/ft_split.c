/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 16:18:29 by nisim             #+#    #+#             */
/*   Updated: 2026/07/31 14:21:51 by nisim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordcount(char const *str, char c)
{
	int	new_word;
	int	count;
	int	i;

	i = 0;
	count = 0;
	new_word = 1;
	while (str[i])
	{
		if (str[i] == c)
			new_word = 1;
		else
		{
			if (new_word == 1)
			{
				count++;
				new_word = 0;
			}
		}
		i++;
	}
	return (count);
}

static size_t	ft_wordlen(char const *str, char c)
{
	size_t	len;

	len = 0;
	while (str[len] && str[len] != c)
		len++;
	return (len);
}

static char	*ft_word_malloc(char const *str, size_t len)
{
	char	*word;
	size_t	i;

	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static char	**ft_free_arr(char **output, int words)
{
	int	i;

	i = 0;
	while (i < words)
	{
		free(output[i]);
		i++;
	}
	free(output);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	**output;

	if (!s)
		return (NULL);
	output = malloc(sizeof(char *) * (ft_wordcount(s, c) + 1));
	if (output == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			output[j] = ft_word_malloc(&s[i], ft_wordlen(&s[i], c));
			if (!output[j])
				return (output[j] = NULL, ft_free_arr(output, j));
			i += ft_wordlen(&s[i], c);
			j++;
		}
	}
	return (output[j] = NULL, output);
}
