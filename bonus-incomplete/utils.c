/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 18:53:10 by nisim             #+#    #+#             */
/*   Updated: 2026/09/14 22:06:28 by nisim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

static char	*ft_strjoin_free(char *s1, char *s2)
{
	int		i;
	int		j;
	size_t	len1;
	char	*str;

	if (!s2)
		return (s1);
	len1 = 0;
	if (s1)
		len1 = ft_strlen(s1);
	str = malloc(sizeof(char) * (len1 + ft_strlen(s2) + 1));
	if (!str)
		return (free(s1), free(s2), NULL);
	i = 0;
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s1);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*str;
	char		*buf;
	ssize_t		total_rbyte;

	if (fd < 0)
		return (NULL);
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	total_rbyte = 1;
	while (total_rbyte > 0)
	{
		total_rbyte = read(fd, buf, BUFFER_SIZE);
		if (total_rbyte > 0)
		{
			buf[total_rbyte] = '\0';
			str = ft_strjoin_free(str, buf);
		}
	}
	free(buf);
	if (total_rbyte < 0 || !str || *str == '\0')
		return (free(str), str = NULL, NULL);
	return (str);
}

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	while (i >= 0)
		free(str[i--]);
	free(str);
}

void	free_stack(t_list **stack)
{
	t_list	*head;
	t_list	*tmp;

	head = *stack;
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
	free(stack);
}
