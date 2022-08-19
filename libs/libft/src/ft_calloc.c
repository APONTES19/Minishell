/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 16:18:14 by lucasmar          #+#    #+#             */
/*   Updated: 2021/09/28 23:20:34 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	int		tsize;
	void	*ret;

	tsize = num * size;
	ret = malloc(tsize);
	if (ret == 0)
		return (0);
	ft_bzero(ret, tsize);
	return (ret);
}
