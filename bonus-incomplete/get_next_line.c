/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 11:18:35 by nisim             #+#    #+#             */
/*   Updated: 2026/09/14 17:09:55 by nisim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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


