/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 20:21:10 by lucasmar          #+#    #+#             */
/*   Updated: 2022/10/20 19:02:38 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_execve(t_ms *ms, t_cmd *cm)
{
	g_ms.pid[g_ms.p] = fork();
	if (g_ms.pid[g_ms.p] < 0)
		ft_error (2, ms, cm, cm[g_ms.p].arg_cmd[0]);
	if (g_ms.pid[g_ms.p] == 0)
	{
		if (g_ms.p == (ms->n_pipe -1))
			close(ms->pipe[0]);
		if (ft_get_path(ms, cm[g_ms.p].arg_cmd[0]) == 0)
		{
			if ((execve(ms->path_cmd, cm[g_ms.p].arg_cmd, g_ms.envp)) == -1)
				ft_error(22, ms, cm, cm[g_ms.p].arg_cmd[1]);
		}
		else if (ft_strchr(cm[g_ms.p].arg_cmd[0], '/') != NULL)
		{
			if ((execve(cm[g_ms.p].arg_cmd[0], cm[g_ms.p].arg_cmd,
				g_ms.envp)) == -1)
			ft_error(22, ms, cm, cm[g_ms.p].arg_cmd[0]);
		}
		else
		{
			ft_free_point(ms->path_cmd);
			ft_error (18, ms, cm, cm[g_ms.p].arg_cmd[0]);
		}
	}
}
