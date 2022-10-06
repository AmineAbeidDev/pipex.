/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabeid <aabeid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 17:40:52 by aabeid            #+#    #+#             */
/*   Updated: 2022/03/03 17:44:58 by aabeid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linker.h"

int	main(int ac, char **av, char **env)
{
	t_linker	container;

	if (ac != 5)
		return (0);
	container.av = av;
	container.env = env;
	multi_ops_executer(container, ac);
	return (0);
}
