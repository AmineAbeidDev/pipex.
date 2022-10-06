/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunner <gunner@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:54:40 by aabeid            #+#    #+#             */
/*   Updated: 2022/10/06 16:33:19 by gunner           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../linker.h"

void	input_not_found(char **arg)
{
	write(2, "zsh: no such file or directory: ", 33);
	write(2, arg[1], ft_strlen(arg[1]));
	write(2, "\n", 1);
}

void	no_permission(char *file)
{
	write(2, "zsh: permission denied: ", 25);
	write(2, file, ft_strlen(file));
	write(2, "\n", 1);
}

void	cmd_not_found(char **arg)
{
	if (ft_strchr(arg[0], '/'))
	{
		write(2, "zsh: no such file or directory: ", 33);
		write(2, arg[0], ft_strlen(arg[0]));
		write(2, "\n", 1);
	}
	else if (arg[0] != 0)
	{
		write(2, "zsh: command not found: ", 25);
		write(2, arg[0], ft_strlen(arg[0]));
		write(2, "\n", 1);
	}
}
