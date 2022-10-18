/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 20:21:10 by lucasmar          #+#    #+#             */
/*   Updated: 2022/10/17 23:11:03 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_execve(t_ms *ms, t_cmd *cm)
{
	ms->j = 256;
	ms->pid1 = ms->pid[ms->p];
	ms->pid[ms->p] = fork();
	if (ms->pid[ms->p] < 0)
		ft_error (2, ms, cm, cm[ms->p].arg_cmd[0]);
	if (ms->pid[ms->p] == 0)
	{
		ft_set_fd_3(ms);
		if (ft_get_path(ms, cm[ms->p].arg_cmd[0]) == 0)
		{
			execve(ms->path_cmd, cm[ms->p].arg_cmd, g_ms.envp);
			ft_error(22, ms, cm, cm[ms->p].arg_cmd[1]);
		}
		else if (ft_strchr(cm[ms->p].arg_cmd[0], '/') != NULL)
		{
			execve(cm[ms->p].arg_cmd[0], cm[ms->p].arg_cmd, g_ms.envp);
			ft_error(22, ms, cm, cm[ms->p].arg_cmd[0]);
		}
		else
		{
			ft_free_point(ms->path_cmd);
			ft_error (18, ms, cm, cm[ms->p].arg_cmd[0]);
		}
	}
	else
		ft_set_fd_4(ms);
}


void	ft_set_fd_4(t_ms *ms)
{
	close(ms->pipe[1]);
	if (ms->p < (ms->n_pipe -1))
	{
		dup2(ms->pipe[0], STDIN);
	}
	else
		wait(&ms->k);
	close(ms->pipe[0]);
	printf("EXECUTEI P[%d]\n", ms->p);
}

void	ft_set_fd_3(t_ms *ms)
{
	close(ms->pipe[0]);
	if (ms->p < (ms->n_pipe -1))
		dup2(ms->pipe[1], STDOUT);
	else if (ms->p == (ms->n_pipe -1) && ms->path_outfile != NULL)
	{
		dup2(g_ms.fileout, STDOUT);
		close(g_ms.fileout);
	}
	if (ms->p == 0 && ms->path_infile != NULL)
	{
		dup2(g_ms.filein, STDIN);
		close(g_ms.filein);
	}
	close(g_ms.stdin);
	close(g_ms.stdout);
	close(ms->pipe[1]);
}
