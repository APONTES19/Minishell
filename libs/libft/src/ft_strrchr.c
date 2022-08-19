/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 15:43:21 by lucasmar          #+#    #+#             */
/*   Updated: 2022/06/23 11:29:16 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	int		len_str;
	char	*pointer;

	pointer = NULL;
	len_str = ft_strlen((char *)str);
	if (ch == '\0')
		return ((char *)str + len_str);
	while (*str != '\0')
	{
		if (*str == ch)
			pointer = ((char *)str);
		str++;
	}
	return (pointer);
}
