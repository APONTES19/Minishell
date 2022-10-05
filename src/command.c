/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 20:21:10 by lucasmar          #+#    #+#             */
/*   Updated: 2022/10/05 16:19:39 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_command(t_ms *ms, t_cmd *cm, char **envp)
{
	ms->pid = fork();
	if (ms->pid < 0)
		ft_error (2, ms);



	if (ms->pid == 0)
	{
		if(ft_get_path(ms, cm[ms->p].arg_cmd[0], envp) == 0)
			ft_error_2(07, cm, ms);
		else
			if ((execve(ms->path_cmd, cm[ms->p].arg_cmd, NULL)) == -1)
				ft_error (3, ms);
	}
	if (ms->pid > 0)
		ft_execve_parent(ms, cm);
}

void	ft_execve_parent(t_ms *ms, t_cmd *cm)
{
	(void) cm;
	if (ms->p == (ms->n_pipe - 1))
	{
		if (ms->n_pipe > 1)
			ft_close_fds(ms);
		//ft_exit(ms, cm);
	}
}


void	ft_close_fds(t_ms *ms)
{
		int	i;
		if(ms->n_pipe == 1)
		{
			close(ms->fd_in);
			close(ms->fd_out);
		}
		else
		{
			i = (((ms->n_pipe - 1) * 2) - 1 );
			while (i != -1)
			{
				close(ms->fd[i]);
				i--;
			}
	}
}
