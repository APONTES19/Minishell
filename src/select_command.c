/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 04:29:41 by lucasmar          #+#    #+#             */
/*   Updated: 2022/10/18 17:11:51 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_main_while(t_ms *ms, t_cmd *cmd)
{
	ms->pid = (int *) malloc(ms->n_pipe * sizeof(int *));
	ft_bzero(ms->pid, ms->n_pipe * sizeof(int *));
	ms->p = 0;
	while (ms->p < ms->n_pipe)
	{
		if (ms->quote == 1)
			ft_clean_quote(cmd);
		if (pipe(ms->pipe) == -1)
			ft_error(21, ms, cmd, cmd[ms->p].arg_cmd[1]);
		ft_set_fd_1(ms);
		if (ft_check_build(ms, cmd) != 1)
			ft_select_build(ms, cmd);
		else
		{
			ft_execve(ms, cmd);
		}
		ft_set_fd_2(ms);
		ms->p++;
	}
	int i;

	i = 0;
	while(i < ms->n_pipe)
	{
		printf("PID%d[%d]\n", i, ms->pid[i]);
		waitpid(ms->pid[i], &ms->k, 0);
		g_ms.exit_s = WEXITSTATUS(ms->k);
		i++;
	}
	free(ms->pid);
	ft_free_cmd(ms, cmd);
}

void	ft_clean_quote(t_cmd *cmd)
{
	int		i;
	int		j;
	char	*c;

	c = malloc(ft_strlen(cmd[0].arg_cmd[0]) + 1);
	i = 0;
	j = 0;
	while (cmd[0].arg_cmd[0][i])
	{
		if (cmd[0].arg_cmd[0][i] == '\'' || cmd[0].arg_cmd[0][i] == '\"')
			i ++;
		c[j] = cmd[0].arg_cmd[0][i];
		j++;
		i++;
	}
	c[j] = '\0';
	cmd[0].arg_cmd[0] = ft_strdup(c);
	ft_free_point(c);
}

void	ft_select_build(t_ms *ms, t_cmd *cmd)
{
	if (ft_strncmp_m(cmd[ms->p].arg_cmd[0], "cd") == 0)
		ft_cd(ms, cmd);
	else if (ft_strncmp_m(cmd[ms->p].arg_cmd[0], "env") == 0)
		ft_env(ms, cmd);
	else if (ft_strncmp_m(cmd[ms->p].arg_cmd[0], "export") == 0)
		ft_export(ms, cmd);
	else if (ft_strncmp_m(cmd[ms->p].arg_cmd[0], "unset") == 0)
		ft_unset(ms, cmd);
	else if (ft_strncmp_m(cmd[ms->p].arg_cmd[0], "pwd") == 0)
		ft_pwd();
	else if (ft_strncmp_m(cmd[ms->p].arg_cmd[0], "echo") == 0)
		ft_echo(ms, cmd);
	else if (ft_strncmp_m(cmd[ms->p].arg_cmd[0], "exit") == 0)
		ft_exit_m(ms, cmd);
}

int	ft_check_build(t_ms *ms, t_cmd *cmd)
{
	if (ft_strncmp_m(cmd[ms->p].arg_cmd[0], "cd") == 0)
		return (0);
	else if (ft_strncmp_m(cmd[ms->p].arg_cmd[0], "env") == 0)
		return (0);
	else if (ft_strncmp_m(cmd[ms->p].arg_cmd[0], "export") == 0)
		return (0);
	else if (ft_strncmp_m(cmd[ms->p].arg_cmd[0], "unset") == 0)
		return (0);
	else if (ft_strncmp_m(cmd[ms->p].arg_cmd[0], "pwd") == 0)
		return (0);
	else if (ft_strncmp_m(cmd[ms->p].arg_cmd[0], "echo") == 0)
		return (0);
	else if (ft_strncmp_m(cmd[ms->p].arg_cmd[0], "exit") == 0)
		return (0);
	return (1);
}

void	ft_set_fd_1(t_ms *ms)
{
	if (ms->p < (ms->n_pipe -1))
		dup2(ms->pipe[1], STDOUT);
	else if (ms->p == (ms->n_pipe -1) && ms->path_outfile != NULL)
	{
		dup2(g_ms.fileout, STDOUT);
		close(g_ms.fileout);
	}
	close(ms->pipe[1]);
	if (ms->p == 0 && ms->path_infile != NULL)
	{
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
