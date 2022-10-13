/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 20:21:10 by lucasmar          #+#    #+#             */
/*   Updated: 2022/10/13 17:31:58 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_execve(t_ms *ms, t_cmd *cm, char **envp)
{
	ms->pid = fork();
	if (ms->pid < 0)
		ft_error (2, ms, cm);
	if (ms->pid == 0)
	{
		close(ms->pipe[0]);
		if (ft_get_path(ms, cm[ms->p].arg_cmd[0], envp) == 0)
			ft_error(18, ms, cm);
		else
			if ((execve(ms->path_cmd, cm[ms->p].arg_cmd, NULL)) == -1)
				ft_error(18, ms, NULL);
	}
}
