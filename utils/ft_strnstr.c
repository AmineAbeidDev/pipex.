/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunner <gunner@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 12:38:59 by aabeid            #+#    #+#             */
/*   Updated: 2022/10/06 16:33:03 by gunner           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../linker.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	n_len;
	size_t	i;

	i = 0;
	n_len = ft_strlen((char *) needle);
	if (*needle == 0)
		return ((char *) haystack);
	n_len = ft_strlen((char *) needle);
	while (i <= (n - n_len) && ft_strlen(needle) <= ft_strlen(haystack)
		&& n > 0)
	{
		if ((haystack[i] == needle[0])
			&& (0 == ft_strncmp(&haystack[i], needle, n_len)))
		{
			//free((void *)haystack);
			return ((char *) &haystack[i]);
		}
		i++;
	}
	return (0);
}
