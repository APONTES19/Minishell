/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 14:35:10 by lucasmar          #+#    #+#             */
/*   Updated: 2022/07/06 19:44:44 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *str, size_t n)
{
	size_t	c;

	c = 0;
	if ((unsigned char *)dest == NULL && (unsigned char *)str == NULL)
		return ((unsigned char *)dest);
	while (c < n)
	{
		((unsigned char *)dest)[c] = ((unsigned char *)str)[c];
		c++;
	}
	return (dest);
}
