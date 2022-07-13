/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 16:43:35 by lucasmar          #+#    #+#             */
/*   Updated: 2022/07/13 17:44:18 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./define.h"
# include "./libs.h"

int		ft_printf(const char *format, ...);
int		ft_putc(const int c);
int		ft_puts(const char *s);
int		ft_putn(unsigned long int n);
int		ft_puth(unsigned long int n, const char *type);
char	*ft_itoa(long int n);
char	*ft_strchr(const char *str, int ch);

#endif
