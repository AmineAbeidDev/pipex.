/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunner <gunner@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 16:32:57 by orbiay            #+#    #+#             */
/*   Updated: 2022/10/06 16:32:19 by gunner           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define BUFFER_SIZE 265

char	*after_new_line( char *buf)
{
	char	*remind;
	int		j;

	j = 0;
	while (buf[j])
	{
		if (buf[j] == '\n')
		{
			remind = gnl_ft_substr(buf, j + 1, gnl_ft_strlen(buf) - j);
			free(buf);
			return (remind);
		}
		j++;
	}
	free(buf);
	return (NULL);
}

char	*cut(char *buf)
{
	int	j;

	j = 0;
	if (!buf[0])
		return (NULL);
	while (buf[j] && buf[j] != '\n')
		j++;
	return (gnl_ft_substr(buf, 0, j));
}

char	*get_line(int fd, char *buf)
{
	char	*rsv;
	int		i;

	rsv = malloc (sizeof(char) * (BUFFER_SIZE + 1));
	i = 1;
	while (!gnl_ft_strchr(buf) && i)
	{
		i = read(fd, rsv, BUFFER_SIZE);
		if (i == -1)
		{
			free(rsv);
			return (NULL);
		}
		rsv[i] = '\0';
		buf = gnl_ft_strjoin(buf, rsv);
	}
	free (rsv);
	return (buf);
}

char	*get_next_line(int fd)
{
	static char		*buf;
	char			*line;

	buf = get_line(fd, buf);
	if (!buf)
		return (NULL);
	line = cut(buf);
	buf = after_new_line(buf);
	return (line);
}
