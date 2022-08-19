/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 10:09:00 by lucasmar          #+#    #+#             */
/*   Updated: 2022/07/06 19:44:37 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *to, void *from, size_t n)
{
	size_t			c;
	unsigned char	*nto;
	unsigned char	*nfrom;

	nfrom = (unsigned char *)from;
	nto = (unsigned char *)to;
	c = n;
	if (nfrom < nto)
	{
		while (c > 0)
		{
			c--;
			nto[c] = nfrom[c];
		}
		return (to);
	}
	ft_memcpy(nto, nfrom, c);
	return (to);
}
