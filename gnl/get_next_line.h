/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabeid <aabeid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 20:25:26 by orbiay            #+#    #+#             */
/*   Updated: 2022/03/01 10:02:40 by aabeid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

char	*gnl_ft_strjoin(char *s1, char *s2);
int		gnl_ft_strlen(char *s);
int		gnl_ft_strchr(char *str);
char	*gnl_ft_substr(char *s, int start, int len);
char	*get_next_line(int fd);

#endif
