/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   08_libft_functions_3.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbin-mus <mbin-mus@student.42penang.edu    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 20:41:43 by mbin-mus          #+#    #+#             */
/*   Updated: 2026/09/11 17:24:43 by nisim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strdup(const char *s)
{
	int		len;
	int		i;
	char	*dup;

	i = 0;
	len = ft_strlen((char *)s);
	dup = (char *)malloc((len + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	while (s[i] != '\0')
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		len_1;
	size_t		len_2;
	char		*join;

	len_1 = ft_strlen(s1);
	len_2 = ft_strlen(s2);
	join = (char *)malloc((len_1 + len_2 + 1) * sizeof(char));
	if (!join)
		return (NULL);
	len_1 = 0;
	while (s1[len_1])
	{
		join[len_1] = s1[len_1];
		len_1++;
	}
	len_2 = 0;
	while (s2[len_2])
	{
		join[len_1] = s2[len_2];
		len_1++;
		len_2++;
	}
	join[len_1] = '\0';
	return (join);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	len;

	if (!s)
		return ;
	len = 0;
	while (s[len])
		len++;
	write(fd, s, len);
}
