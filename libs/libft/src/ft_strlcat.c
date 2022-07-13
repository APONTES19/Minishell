/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 15:13:30 by lucasmar          #+#    #+#             */
/*   Updated: 2021/10/02 20:43:34 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *to, const char *from, size_t tosize)
{
	size_t	c;
	size_t	f;
	size_t	tolen;
	size_t	fromlen;

	tolen = ft_strlen(to);
	fromlen = ft_strlen(from);
	if (tosize < tolen)
		return (tosize + fromlen);
	c = tolen;
	f = 0;
	while (from[f] != '\0' && (c + 1) < tosize)
	{
		to[c] = from[f];
		c++;
		f++;
	}
	to[c] = '\0';
	return (ft_strlen(to) + ft_strlen(&from[f]));
}
