/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 04:29:41 by lucasmar          #+#    #+#             */
/*   Updated: 2022/10/24 21:37:54 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_main_while(t_ms *ms, t_cmd *cmd)
{
	g_ms.command_on = 1;
	signal (SIGQUIT, ft_quit);
	g_ms.pid = (int *) malloc(ms->n_pipe * sizeof(int *));
	ft_memset(g_ms.pid, -1, ms->n_pipe * sizeof(int *));
	g_ms.p = 0;
	while (g_ms.p < ms->n_pipe)
	{
		if (pipe(ms->pipe) == -1)
			ft_error(21, ms, cmd, cmd[g_ms.p].arg_cmd[1]);
		ft_set_fd_1(ms);
		ft_check_build(ms, cmd);
		if (ms->j == 0)
			ft_execve(ms, cmd);
		ft_set_fd_2(ms);
		g_ms.p++;
	}
	ft_main_while_aux(ms);
	ft_free_cmd(ms, cmd);
}

void	ft_main_while_aux(t_ms *ms)
{
	int	i;

	i = 0;
	while (i < ms->n_pipe)
	{
		if (g_ms.pid[i] != -20)
		{
			waitpid(g_ms.pid[i], &ms->k, 0);
			g_ms.exit_s = WEXITSTATUS(ms->k);
		}
		i++;
	}
	free(g_ms.pid);
	g_ms.pid = NULL;
}

void	ft_check_build(t_ms *ms, t_cmd *cmd)
{
	g_ms.pid[g_ms.p] = -20;
	ms->j = 1;
	if (ft_strncmp_m(cmd[g_ms.p].arg_cmd[0], "cd") == 0)
		return (ft_cd(ms, cmd));
	else if (ft_strncmp_m(cmd[g_ms.p].arg_cmd[0], "env") == 0)
		return (ft_env(ms, cmd));
	else if (ft_strncmp_m(cmd[g_ms.p].arg_cmd[0], "export") == 0)
		return (ft_export(ms, cmd));
	else if (ft_strncmp_m(cmd[g_ms.p].arg_cmd[0], "unset") == 0)
		return (ft_unset(cmd));
	else if (ft_strncmp_m(cmd[g_ms.p].arg_cmd[0], "pwd") == 0)
		return (ft_pwd());
	else if (ft_strncmp_m(cmd[g_ms.p].arg_cmd[0], "echo") == 0)
		return (ft_echo(ms, cmd));
	else if (ft_strncmp_m(cmd[g_ms.p].arg_cmd[0], "exit") == 0)
		return (ft_exit_m(ms, cmd));
	ms->j = 0;
}

void	ft_set_fd_1(t_ms *ms)
{
	if (g_ms.p < (ms->n_pipe -1))
		dup2(ms->pipe[1], STDOUT);
	else if (g_ms.p == (ms->n_pipe -1) && g_ms.path_outfile != NULL)
	{
		ft_free_point(g_ms.path_outfile);
		dup2(g_ms.fileout, STDOUT);
		close(g_ms.fileout);
	}
	close(ms->pipe[1]);
	if (g_ms.p == 0 && g_ms.path_infile != NULL)
	{
		ft_free_point(g_ms.path_infile);
		dup2(g_ms.filein, STDIN);
		close(g_ms.filein);
	}
}

void	ft_set_fd_2(t_ms *ms)
{
	dup2(ms->pipe[0], STDIN);
	dup2(g_ms.stdout, STDOUT);
	close(ms->pipe[0]);
	close(ms->pipe[1]);
}
