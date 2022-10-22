/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 20:30:07 by lucasmar          #+#    #+#             */
/*   Updated: 2022/10/22 01:08:19 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_exit_m(t_ms *ms, t_cmd *cmd)
{
	if (cmd[g_ms.p].arg_cmd[1] != NULL
		&& ft_str_isnum(cmd[g_ms.p].arg_cmd[1]) == 0)
		ft_error(27, ms, cmd, cmd[g_ms.p].arg_cmd[1]);
	else if (cmd[g_ms.p].arg_cmd[1] != NULL
		&& cmd[g_ms.p].arg_cmd[2] != NULL)
		ft_error(28, ms, cmd, cmd[g_ms.p].arg_cmd[1]);
	else if (cmd[g_ms.p].arg_cmd[1] != NULL
		&& ft_str_isnum(cmd[g_ms.p].arg_cmd[1]) == 1)
		g_ms.exit_s = ft_atoi(cmd[g_ms.p].arg_cmd[1]);
	ft_free_cmd(ms, cmd);
	ft_free_exit(ms, cmd);
	exit(g_ms.exit_s);
}

int	ft_str_isnum(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] <= '9' && str[i] >= '0')
			i++;
		else
			return (0);
	}
	return (1);
}
