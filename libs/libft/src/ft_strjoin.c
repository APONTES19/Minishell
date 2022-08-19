/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 17:47:33 by lucasmar          #+#    #+#             */
/*   Updated: 2021/09/29 19:01:43 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_string;
	size_t	len_s1;
	size_t	len_s2;
	size_t	counter1;
	size_t	counter2;

	len_s1 = ft_strlen((char *)s1);
	len_s2 = ft_strlen((char *)s2);
	new_string = (char *)malloc(len_s1 + len_s2 + 1);
	if (!s1 || !s2 || !new_string)
		return (0);
	counter1 = 0;
	while (s1[counter1] != '\0')
	{
		new_string[counter1] = s1[counter1];
		counter1++;
	}
	counter2 = 0;
	while (s2[counter2] != '\0')
		new_string[counter1++] = s2[counter2++];
	new_string[counter1] = '\0';
	return (new_string);
}
