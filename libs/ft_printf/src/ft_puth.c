/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puth.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 15:35:36 by lucasmar          #+#    #+#             */
/*   Updated: 2022/07/13 17:52:26 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_puth(unsigned long int n, const char *type)
{
	char			*base1;
	char			*base2;
	static int		result;

	base1 = "0123456789abcdef";
	base2 = "0123456789ABCDEF";
	result = 0;
	if (!n && !IS_MAC && *type == 'p')
		return (ft_puts("(nil)"));
	if (n >= 16)
		ft_puth(n / 16, type);
	if (result == 0 && *type == 'p')
	{
		ft_puts("0x");
		result = 2;
	}
	if (*type == 'X')
		ft_putc(base2[n % 16]);
	else
		ft_putc(base1[n % 16]);
	result++;
	return (result);
}
