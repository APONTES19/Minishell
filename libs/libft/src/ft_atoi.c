/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 19:19:19 by lucasmar          #+#    #+#             */
/*   Updated: 2022/06/30 16:00:37 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c);

int	ft_atoi(const char *str)
{
	int	a;
	int	r;
	int	c;

	c = 1;
	a = 0;
	r = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			c = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		r = (r * 10) + ((*str++) - '0');
		a++;
	}
	if (a > 10 && c == 1)
		return (-1);
	else if (a > 10)
		return (0);
	return (r * c);
}

static int	ft_isspace(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}
