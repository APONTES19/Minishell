/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp_m.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 22:49:40 by lucasmar          #+#    #+#             */
/*   Updated: 2022/10/22 01:12:54 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_strncmp_m(const char *str1, const char *str2)
{
	size_t	a;
	size_t	b;

	a = ft_strlen(str1);
	b = ft_strlen(str2);
	if ((a - b) != 0)
		return (1);
	while (*str1)
	{
		if (*str1 != *str2)
			return (1);
		str1++;
		str2++;
	}
	return (0);
}
