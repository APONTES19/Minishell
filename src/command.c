/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 20:21:10 by lucasmar          #+#    #+#             */
/*   Updated: 2022/09/19 20:38:29 by lucasmar         ###   ########.fr       */
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
		if (ms->n_pipe > 1)
		{
			ft_select_fd(ms);
			ft_close_fds(ms);
		}
		ft_select_arg(ms, cm, envp);
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

void	ft_select_fd(t_ms *ms)
{
	if(ms->p == 0)
		ft_change_fd(0, ms->fd[1], ms);
	if(ms->p > 0 && ms->p < (ms->n_pipe - 1))
		ft_change_fd(ms->fd[(2 * ms->p) - 2],
			ms->fd[(2 * ms->p) + 1], ms);
	if(ms->p == (ms->n_pipe - 1))
		ft_change_fd(ms->fd[(2 * ms->p) - 2] , 1, ms);
}

void	ft_change_fd(int input, int output, t_ms *ms)
{
	if (dup2(input, 0) == -1)
		ft_error(10, ms);
	if (dup2(output, 1) == -1)
		ft_error(10, ms);
}

void	ft_close_fds(t_ms *ms)
{
		int	i;
		i = (((ms->n_pipe - 1) * 2) - 1 );
		while (i != -1)
		{
			close(ms->fd[i]);
			i--;
		}
}

