/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_ops_executer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabeid <aabeid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 10:36:35 by aabeid            #+#    #+#             */
/*   Updated: 2022/03/03 17:42:04 by aabeid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../linker.h"

void	stream_creator(t_linker val, int i)
{
	int		id1;

	pipe(val.fd);
	id1 = fork();
	if (id1 == 0)
	{
		close(val.fd[0]);
		dup2(val.fd[1], STDOUT_FILENO);
		close(val.fd[1]);
		executer(val, i);
	}
	else
	{
		close(val.fd[1]);
		dup2(val.fd[0], STDIN_FILENO);
		close(val.fd[0]);
	}
}

void	input_handler(t_linker vals, int i)
{
	int	input;

	input = open(vals.av[1], O_RDONLY);
	if (input == -1)
	{
		input_not_found(vals.av);
		pipe(vals.fd);
		close(vals.fd[1]);
		dup2(vals.fd[0], STDIN_FILENO);
	}
	else
	{
		dup2(input, STDIN_FILENO);
		close(input);
		stream_creator(vals, i);
	}
}

void	heredoc_handler(t_linker vals)
{
	int		here_doc;
	char	*ret;

	here_doc = open("/tmp/.here_doc", O_RDWR | O_TRUNC | O_CREAT, 0600);
	ret = get_next_line(0);
	while (ft_strncmp(vals.av[2], ret, ft_strlen(vals.av[2]) + 1) && ret)
	{
		write(here_doc, ret, ft_strlen(ret));
		write(here_doc, "\n", 1);
		free(ret);
		ret = get_next_line(0);
	}
	free(ret);
	close(here_doc);
	here_doc = open("/tmp/.here_doc", O_RDONLY, 0600);
	dup2(here_doc, STDIN_FILENO);
	close(here_doc);
}

void	multi_ops_executer(t_linker vals, int ac)
{
	int		output;
	int		i;

	i = 2;
	if (!ft_strncmp("here_doc", vals.av[1], 9))
	{
		heredoc_handler(vals);
		i++;
	}
	else
		input_handler(vals, i);
	i++;
	output = open(vals.av[ac - 1], O_TRUNC | O_WRONLY | O_CREAT, 0600);
	while (i < ac - 2)
		stream_creator(vals, i++);
	dup2(output, STDOUT_FILENO);
	close(output);
	if (fork() == 0)
		executer(vals, i);
	close(0);
	while (wait(NULL) != -1)
	{
	}
}
