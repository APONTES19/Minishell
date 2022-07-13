/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 15:07:49 by lucasmar          #+#    #+#             */
/*   Updated: 2021/10/25 15:08:18 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	counter;
	size_t	size_s;

	if (!s)
		return (0);
	size_s = ft_strlen((char *)s);
	if (start > size_s)
		return (ft_strdup(""));
	if (len > size_s)
		len = (size_s - start);
	result = (char *)malloc(len + 1);
	if (!result)
		return (0);
	counter = 0;
	while (len--)
		result[counter++] = s[start++];
	result[counter] = '\0';
	return (result);
}
