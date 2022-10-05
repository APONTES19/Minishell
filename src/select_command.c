/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 04:29:41 by lucasmar          #+#    #+#             */
/*   Updated: 2022/10/05 14:40:12 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_select(t_ms *ms, t_cmd *cmd, char **envp)
{
	if(ms->n_pipe > 1)
		ft_creat_pipe(ms);
	ms->p = 0;
	while(ms->p < ms->n_pipe)
	{
		if (ms->quote == 1)
			ft_clean_quote(cmd);
		if (ft_select_arg_2(ms, cmd) == 1)
			ft_command(ms, cmd, envp);
		ms->p++;
	}
	waitpid(ms->pid, &ms->exit_s, 0);
}

void	ft_creat_pipe(t_ms *ms)
{
	int	i;

	i = 0;
	ms->fd = malloc(2 * (ms->n_pipe - 1) * sizeof(ms->pipe));
	while(i < ms->n_pipe - 1)
	{
		ms->pipe = pipe(ms->fd + (2 * i));
		if (ms->pipe == -1)
			ft_error(9, ms);
		i++;
	}
}

void	ft_clean_quote(t_cmd *cmd)
{
	int	i;
	int	j;
	char	*c;

	c = malloc(ft_strlen(cmd[0].arg_cmd[0])+1);
	i = 0;
	j = 0;
	while (cmd[0].arg_cmd[0][i])
	{
		if(cmd[0].arg_cmd[0][i] == '\'' || cmd[0].arg_cmd[0][i] == '\"')
			i++;
		c[j] = cmd[0].arg_cmd[0][i];
		j++;
		i++;
	}
	c[j] = '\0';
	cmd[0].arg_cmd[0] = ft_strdup(c);
	free(c);
	c = NULL;
}

void	ft_select_arg(t_ms *ms, t_cmd *cmd, char **envp)
{
	if (!ft_strncmp(cmd[ms->p].arg_cmd[0], "pwd", 3))
		ft_pwd();
	else if (!ft_strncmp(cmd[ms->p].arg_cmd[0], "echo", 4))
		ft_echo(ms, cmd);
	else
	{
		if(ft_get_path(ms, cmd[ms->p].arg_cmd[0], envp) == 0)
			ft_error_2(07, cmd, ms);
		else
			if ((execve(ms->path_cmd, cmd[ms->p].arg_cmd, NULL)) == -1)
				ft_error (3, ms);
	}
}

int	ft_select_arg_2(t_ms *ms, t_cmd *cmd)
{
	if (ms->n_pipe > 1)
	{
		ft_select_fd(ms);
		ft_close_fds(ms);
	}
	else
	{
		if (dup2(ms->fd_in, 0) == -1)
			ft_error(10, ms);
		if (dup2(ms->fd_out, 1) == -1)
			ft_error(10, ms);
	}
	if (!ft_strncmp(cmd[ms->p].arg_cmd[0], "cd", 2))
	{
		ft_cd(ms, cmd);
		return (0);
	}
	else if (ft_strncmp(cmd[ms->p].arg_cmd[0], "env", 3) == 0)
	{
		ft_env(ms, cmd);
		return (0);
	}
	else if (!ft_strncmp(cmd[ms->p].arg_cmd[0], "export", 6))
	{
		ft_export(ms, cmd);
		return (0);
	}
	else if (!ft_strncmp(cmd[ms->p].arg_cmd[0], "unset", 5))
	{
		ft_unset(ms, cmd);
		return (0);
	}
	return (1);
}
