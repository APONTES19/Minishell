/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 14:15:39 by lucasmar          #+#    #+#             */
/*   Updated: 2021/10/03 17:44:49 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *to, const char *from, size_t tosize)
{
	size_t	c;

	c = 0;
	if (to == NULL || from == NULL)
		return (0);
	if (tosize)
	{
		while (from[c] != '\0' && c < (tosize - 1))
		{
			to[c] = from[c];
			c++;
		}
		to[c] = '\0';
	}
	return (ft_strlen((char *)from));
}
