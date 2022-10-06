/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_getter_finder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabeid <aabeid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 10:18:36 by aabeid            #+#    #+#             */
/*   Updated: 2022/03/03 17:25:05 by aabeid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../linker.h"

char	*path_finder(char **paths, char *path, char *arg)
{
	int	i;

	i = 0;
	while (paths[i])
	{
		paths[i] = ft_strjoin(paths[i], "/");
		path = ft_strjoin(paths[i], arg);
		if (access(path, F_OK) == 0)
			return (path);
		i++;
		free(path);
		free(paths[i]);
	}
	return (0);
}

char	*paths_getter(t_linker container)
{
	char	*path;
	char	**paths;
	int		i;

	i = 0;
	if (!container.arg)
		return (0);
	if (access(container.arg[0], X_OK) == 0)
		return (container.arg[0]);
	while (1)
	{
		if (ft_strncmp(container.env[i], "PATH", 4) == 0)
		{
			path = container.env[i];
			break ;
		}
		i++;
	}
	paths = ft_split(path, ':');
	paths[0] = ft_strnstr(paths[0], "/", 10);
	path = path_finder(paths, path, container.arg[0]);
	i = 0;
	while (paths[i])
		free(paths[i++]);
	return (path);
}
