/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 23:48:30 by lucasmar          #+#    #+#             */
/*   Updated: 2021/09/28 23:53:41 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*dst;

	dst = malloc(ft_strlen((char *)str) + 1);
	if (dst == NULL)
		return (NULL);
	ft_memcpy(dst, str, ft_strlen((char *)str) + 1);
	return (dst);
}
