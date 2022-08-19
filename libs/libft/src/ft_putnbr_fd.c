/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 16:24:28 by lucasmar          #+#    #+#             */
/*   Updated: 2021/10/03 18:34:08 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	base;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		base = (unsigned int)(n * -1);
	}
	else
		base = (unsigned int)n;
	if (base >= 10)
		ft_putnbr_fd(base / 10, fd);
	ft_putchar_fd((char)(base % 10 + '0'), fd);
}
