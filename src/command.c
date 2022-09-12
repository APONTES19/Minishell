/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 20:21:10 by lucasmar          #+#    #+#             */
/*   Updated: 2022/09/12 20:04:24 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_execve_cmd(t_ms *ms, t_cmd *cmd, char **envp)
{
	if(ft_get_path(ms, cmd[0].arg_cmd[0], envp) == 0)
		ft_error_2(07, cmd, ms);
	else
		ft_execve(ms, cmd[0].arg_cmd, cmd);
	//ft_base_free(ms, cmd);
}

void	ft_command_split(t_ms *ms, t_cmd *cmd, char **envp)
{
	if(ms->n_pipe > 1)
	{
		cmd = (t_cmd *) malloc (ms->n_pipe * sizeof (t_cmd));
		cmd->base_list_cmd = ft_split_ms(ms->line, '|');
		ms->i = 0;
		while(ms->i != ms->n_pipe)
		{
			cmd[ms->i].arg_cmd = ft_split_ms(cmd->base_list_cmd[ms->i], ' ');
			ms->i++;
		}
	}
	else
	{
		ms->i = 0;
		cmd = (t_cmd *) malloc (ms->n_pipe * sizeof (t_cmd));
		cmd[ms->i].arg_cmd = ft_split_ms(ms->line, ' ');
	}
	ft_select(ms, cmd, envp);
}

int	ft_get_path(t_ms *ms, char *cmd, char **envp)
{
	ms->i = 0;
	while (envp[ms->i++])
	{
		if (!ft_strncmp(envp[ms->i], "PATH=", 5))
		{
			ms->path_list = ft_split(envp[ms->i], ':');
			ms->j = 0;
			while (ms->path_list[ms->j])
			{
				ms->temp = ft_strjoin(ms->path_list[ms->j], "/");
				ms->path_cmd = ft_strjoin(ms->temp, cmd);
				if (!access(ms->path_cmd, F_OK | X_OK))
				{
					ft_aux_path(ms, 0);
					return (1);
				}
				ft_aux_path(ms, 1);
				ms->j++;
			}
			ft_aux_path(ms, 2);
			return (0);
		}
	}
	return (0);
}

void	ft_aux_path(t_ms *ms, int number)
{
	free (ms->temp);
	ms->temp = NULL;
	if (number == 1)
	{
		free (ms->path_cmd);
		ms->path_cmd = NULL;
	}
	if (number == 0 || number == 2)
	{
		ms->k = 0;
		while (ms->path_list[ms->k])
		{
			free (ms->path_list[ms->k]);
			ms->path_list[ms->k] = NULL;
			ms->k++;
		}
		free(ms->path_list);
		ms->path_list = NULL;
	}
	if (number == 2)
	{
		free (ms->path_cmd);
		ms->path_cmd = NULL;
	}
}

void	ft_execve(t_ms *ms, char **cmd, t_cmd *cm)
{
	ms->pid = fork();
	if (ms->pid < 0)
		ft_error (2, ms);
	if (ms->pid == 0)
	{
		if ((execve(ms->path_cmd, cmd, NULL)) == -1)
			ft_error (3, ms);
	}
	if (ms->pid > 0)
	{
		wait(&ms->pid);
		ft_exit(ms, cm);
	}
}
