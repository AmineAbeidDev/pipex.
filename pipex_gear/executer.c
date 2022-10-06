/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabeid <aabeid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 10:42:56 by aabeid            #+#    #+#             */
/*   Updated: 2022/03/03 17:24:58 by aabeid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../linker.h"

void	executer(t_linker vals, int i)
{
	vals.arg = ft_split(vals.av[i], ' ');
	vals.path = paths_getter(vals);
	if (-1 == execve(vals.path, vals.arg, vals.env))
		cmd_not_found(vals.arg);
	exit(1);
}
