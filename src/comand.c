/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 20:21:10 by lucasmar          #+#    #+#             */
/*   Updated: 2022/09/05 22:41:10 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_get_path(t_ms *ms, char *cmd, char **envp)
{
	ms->i = 0;
	while (envp[ms->i++])
	{
		printf("envp\n");
		if (!ft_strncmp(envp[ms->i], "PATH=", 5))
		{
			ms->path_list = ft_split(envp[ms->i], ':');
			ms->j = 0;
			printf("entrei no path\n");
			printf("%s",ms->path_list[ms->j]);
			printf("entrei no path\n");
			while (ms->path_list[ms->j])
			{
				ms->temp = ft_strjoin(ms->path_list[ms->j], "/");
				ms->path_cmd = ft_strjoin(ms->temp, cmd);
				printf("Path_cmd[%d]=%s\n",ms->j,ms->path_cmd);
				if (!access(ms->path_cmd, F_OK | X_OK))
				{
					ft_aux_path(ms, 0);
					return (0);
				}
				ft_aux_path(ms, 1);
				ms->j++;
			}
			return (1);
		}
	}
	return (1);
}

void	ft_aux_path(t_ms *ms, int number)
{
	if (number == 1)
	{
		free (ms->temp);
		ms->temp = NULL;
		free (ms->path_cmd);
		ms->path_cmd = NULL;
	}
	if (number == 0)
	{
		free (ms->temp);
		ms->temp = NULL;
		free(ms->path_list);
	}
}

void	ft_execve(t_ms *ms, char **cmd)
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
		wait(&ms->pid);
}
