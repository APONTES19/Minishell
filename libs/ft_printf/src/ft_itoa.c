/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 16:55:32 by lucasmar          #+#    #+#             */
/*   Updated: 2022/07/13 17:52:16 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static size_t	intlen(long int n);

char	*ft_itoa(long int n)
{
	char	*result;
	size_t	len;
	long	new;

	len = intlen (n);
	new = n;
	if (new < 0)
	{
		new = -new;
		len = len + 1;
	}
	result = (char *)malloc(len + 1);
	if (!result)
		return (0);
	*(result + len--) = '\0';
	while (new > 0)
	{
		*(result + len--) = (new % 10) + '0';
		new = new / 10;
	}
	if (len == 0 && result[1] == '\0')
		*(result + len) = '0';
	else if (len == 0 && result[1] != '\0')
		*(result + len) = '-';
	return (result);
}

static size_t	intlen(long int n)
{
	size_t	result;

	result = 0;
	if (n == 0)
		result = 1;
	while (n)
	{
		n = n / 10;
		result++;
	}
	return (result);
}
