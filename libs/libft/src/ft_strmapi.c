/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 13:33:51 by lucasmar          #+#    #+#             */
/*   Updated: 2021/10/01 13:35:59 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*string;
	unsigned int	counter;

	(string = ft_strdup(s));
	if (!s || !f || !string)
		return (0);
	counter = 0;
	while (string[counter])
	{
		string[counter] = f(counter, string[counter]);
		counter++;
	}
	return (string);
}
