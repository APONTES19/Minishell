/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 20:21:10 by lucasmar          #+#    #+#             */
/*   Updated: 2022/10/16 00:52:24 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_execve(t_ms *ms, t_cmd *cm)
{
	ms->pid = fork();
	if (ms->pid < 0)
		ft_error (2, ms, cm);
	if (ms->pid == 0)
	{
		close(ms->pipe[0]);
		;
		if (ft_get_path(ms, cm[ms->p].arg_cmd[0]) == 0)
		{
			ft_printf("entrei valor do path\n");
			if ((execve(ms->path_cmd, cm[ms->p].arg_cmd, g_ms.envp)) == -1)
				ft_error(18, ms, cm);
		}
		else if (ft_strchr(cm[ms->p].arg_cmd[0], '/') != NULL)
		{
			if ((execve(cm[ms->p].arg_cmd[0], cm[ms->p].arg_cmd,
				g_ms.envp)) == -1)
			ft_error(18, ms, cm);
		}
		else
			ft_error(18, ms, cm);
		ft_printf("PASSEI\n");
	}
}
