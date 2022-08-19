/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 13:50:20 by lucasmar          #+#    #+#             */
/*   Updated: 2022/07/13 17:51:02 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_put(const char *str, va_list list);

int	ft_printf(const char *format, ...)
{
	int		count;
	int		ret;
	va_list	list;

	count = 0;
	ret = 0;
	va_start(list, format);
	while (format[count])
	{
		if (format[count] == '%' && ft_strchr("%csdiupxX", format[count + 1]))
		{
			ret = ret + ft_put(&format[count + 1], list);
			count++;
		}
		else
			ret = ret + ft_putc(format[count]);
		count++;
	}
	va_end(list);
	return (ret);
}

static int	ft_put(const char *str, va_list list)
{
	if (*str == '%')
		return (ft_putc(*str));
	else if (*str == 'c')
		return (ft_putc(va_arg(list, int)));
	else if (*str == 's')
		return (ft_puts(va_arg(list, char *)));
	else if (*str == 'd' || *str == 'i')
		return (ft_putn(va_arg(list, int)));
	else if (*str == 'u')
		return (ft_putn(va_arg(list, unsigned int)));
	else if (*str == 'p')
		return (ft_puth(va_arg(list, unsigned long int), str));
	else if (*str == 'x' || *str == 'X')
		return (ft_puth(va_arg(list, unsigned int), str));
	return (0);
}
