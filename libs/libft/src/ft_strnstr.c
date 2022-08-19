/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 16:34:39 by lucasmar          #+#    #+#             */
/*   Updated: 2021/09/29 11:02:54 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *small, size_t len)
{
	size_t	b;
	size_t	s;

	if (small[0] == '\0')
		return ((char *)big);
	b = 0;
	while (big[b] != '\0')
	{
		s = 0;
		while (big[b + s] == small[s] && (b + s) < len)
		{
			if (big[b + s] == '\0' && small[s] == '\0')
				return ((char *)&big[b]);
			s++;
		}
		if (small[s] == '\0')
			return ((char *)&big[b]);
		b++;
	}
	return (0);
}
