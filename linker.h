/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linker.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunner <gunner@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 11:05:51 by aabeid            #+#    #+#             */
/*   Updated: 2022/10/06 16:31:40 by gunner           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKER_H
# define LINKER_H

# include <sys/wait.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "gnl/get_next_line.h"

typedef struct linker
{
	int		fd[2];
	int		fd_f;
	char	*path;
	char	**arg;
	char	**env;
	char	**av;
}	t_linker;

void		no_permission(char *file);
char		*paths_getter(t_linker container);
void		stream_creator(t_linker val, int i);
void		executer(t_linker vals, int i);
void		multi_ops_executer(t_linker vals, int ac);
void		cmd_not_found(char **arg);
int			ft_strlen(const char *str);
void		input_not_found(char **arg);
char		*ft_strjoin(char const *s1, char const *s2);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
int			ft_strchr(const char *str, int c);
char		*ft_strnstr(const char *haystack, const char *needle, size_t n);

#endif