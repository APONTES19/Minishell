/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 20:36:51 by lucasmar          #+#    #+#             */
/*   Updated: 2022/10/22 02:14:51 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_quit(int signum)
{
	int	i;

	(void) signum;
	i = 0;
	while (i < g_ms.n_pipe)
	{
		if (g_ms.pid[i] != 0)
		{
			kill(g_ms.pid[i], SIGKILL);
			ft_putstr_fd("Quit\n", 1);
		}
		i++;
	}
}
