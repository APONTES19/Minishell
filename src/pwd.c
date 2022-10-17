/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 19:50:30 by lucasmar          #+#    #+#             */
/*   Updated: 2022/10/17 00:17:43 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_pwd(void)
{
	char	*s;

	s = (char *) malloc(1024 * sizeof(char));
	getcwd(s, 1024);
	ft_printf("%s\n", s);
	ft_free_point(s);
	g_ms.exit_s = 0;
	return ;
}
