/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 21:41:14 by ryoshio-          #+#    #+#             */
/*   Updated: 2022/10/10 23:35:41 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_free_two_point(char **point)
{
	int	i;

	i = 0;
	while (point[i])
	{
		free(point[i]);
		point[i] = NULL;
		i++;
	}
	free(point);
	point = NULL;
}

void	ft_free_point(char *point)
{
	free(point);
	point = NULL;
}

void	ft_base_free(t_ms *ms, t_cmd *cmd)
{
	int	i;
	int	j;

	j = 0;
	while (j < ms->n_pipe)
	{
		if (ms->n_pipe > 1)
		{
			free(cmd[0].base_list_cmd[j]);
			cmd[0].base_list_cmd[j] = NULL;
		}
		i = 0;
		while (cmd[j].arg_cmd[i])
		{
			free(cmd[j].arg_cmd[i]);
			cmd[j].arg_cmd[i] = NULL;
			i ++;
		}
		free (cmd[j].arg_cmd);
		cmd[j].arg_cmd = NULL;
		j ++;
	}
	if (ms->n_pipe > 1)
		free(cmd[0].base_list_cmd);
	free(cmd);
}

void	ft_exit(t_ms *ms, t_cmd *cmd)
{
	ft_base_free(ms, cmd);
	free (ms->path_cmd);
	ms->path_cmd = NULL;
	if (ms->n_pipe > 1)
	{
		ms->i = 0;
		while (ms->fd[ms->i])
		{
			free(&ms->fd[ms->i]);
			ms->i++;
		}
	}
	free(ms->oldpwd);
	ms->oldpwd = NULL;
}
