/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 21:41:14 by ryoshio-          #+#    #+#             */
/*   Updated: 2022/10/17 01:24:13 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_free_two_point(char **point)
{
	int	i;

	if (point[0] != NULL)
	{
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
}

void	ft_free_point(char *point)
{
	if (point != NULL)
	{
		free(point);
		point = NULL;
	}
}

void	ft_base_free(t_ms *ms, t_cmd *cmd)
{
	int	j;

	j = 0;
	while (j < ms->n_pipe)
	{
		ft_free_two_point(cmd[j].arg_cmd);
		j ++;
	}
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
	//free(ms->head);
	free(ms->oldpwd);
	ms->oldpwd = NULL;
}
