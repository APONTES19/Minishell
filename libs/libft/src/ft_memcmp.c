/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 16:54:57 by lucasmar          #+#    #+#             */
/*   Updated: 2021/09/29 09:14:05 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(void *str1, void *str2, size_t n)
{
	size_t	c;

	c = 0;
	while (c < n)
	{
		if (((unsigned char *)str1)[c] != ((unsigned char *)str2)[c])
			return (((unsigned char *)str1)[c] - ((unsigned char *)str2)[c]);
		c++;
	}
	return (0);
}
