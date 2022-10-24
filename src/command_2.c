/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 19:21:39 by lucasmar          #+#    #+#             */
/*   Updated: 2022/10/24 18:20:15 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_command_split(t_ms *ms, t_cmd *cmd)
{
	if (ms->n_pipe > 1)
	{
		cmd = (t_cmd *) malloc (ms->n_pipe * sizeof (t_cmd));
		cmd->base_list_cmd = ft_split_ms(g_ms.line, '|');
		ms->i = 0;
		while (ms->i != ms->n_pipe)
		{
			cmd[ms->i].arg_cmd = ft_split_ms(cmd->base_list_cmd[ms->i], ' ');
			ms->i++;
		}
		ft_free_two_point(cmd->base_list_cmd);
	}
	else
	{
		ms->i = 0;
		cmd = (t_cmd *) malloc (ms->n_pipe * sizeof (t_cmd));
		cmd[ms->i].arg_cmd = ft_split_ms(g_ms.line, ' ');
	}
	if (ft_command_split_aux(ms, cmd) == 1)
		return (1);
	ft_main_while(ms, cmd);
	return (0);
}

int	ft_command_split_aux(t_ms *ms, t_cmd *cmd)
{
	ft_free_point(g_ms.line);
	if (cmd[0].arg_cmd[0] == NULL)
	{
		ft_error(8, ms, NULL, NULL);
		return (1);
	}
	if (ms->quote == 1)
		ft_clean_quote(ms, cmd);
	return (0);
}

int	ft_get_path(t_ms *ms, char *cmd)
{
	char	*path;

	path = NULL;
	path = ft_getenv("PATH");
	if (path == NULL)
		return (1);
	ms->path_list = ft_split(path, ':');
	ms->j = -1;
	while (ms->path_list[++ms->j])
	{
		ms->temp = ft_strjoin(ms->path_list[ms->j], "/");
		if (cmd == NULL)
			ms->path_cmd = ft_strdup(ms->temp);
		else
			ms->path_cmd = ft_strjoin(ms->temp, cmd);
		if (!access(ms->path_cmd, F_OK | X_OK))
		{
			ft_aux_path(ms, 0);
			return (0);
		}
		ft_aux_path(ms, 1);
	}
	ft_aux_path(ms, 2);
	return (1);
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
