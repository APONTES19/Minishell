/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 11:45:48 by lucasmar          #+#    #+#             */
/*   Updated: 2022/07/13 17:52:31 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putn(unsigned long int n)
{
	char	*print;
	int		result;

	print = ft_itoa(n);
	result = ft_puts(print);
	free(print);
	return (result);
}
