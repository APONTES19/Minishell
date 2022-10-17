/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 20:21:10 by lucasmar          #+#    #+#             */
/*   Updated: 2022/10/17 11:32:58 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_execve(t_ms *ms, t_cmd *cm)
{
	if (g_ms.pid == 0)
	{
		close(ms->pipe[0]);
		if (ft_get_path(ms, cm[ms->p].arg_cmd[0]) == 0)
		{
			if ((execve(ms->path_cmd, cm[ms->p].arg_cmd, g_ms.envp)) == -1)
				ft_error(22, ms, cm);
		}
		else if (ft_strchr(cm[ms->p].arg_cmd[0], '/') != NULL)
		{
			if ((execve(cm[ms->p].arg_cmd[0], cm[ms->p].arg_cmd,
				g_ms.envp)) == -1)
			ft_error(22, ms, cm);
		}
		else
		{
			ft_free_point(ms->path_cmd);
			ft_error (18, ms, cm);
		}
	}
}
