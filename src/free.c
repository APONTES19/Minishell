/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 21:41:14 by ryoshio-          #+#    #+#             */
/*   Updated: 2022/10/20 18:48:41 by lucasmar         ###   ########.fr       */
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

void	ft_free_cmd(t_ms *ms, t_cmd *cmd)
{
	int	j;

	j = 0;
	while (j < ms->n_pipe)
	{
		ft_free_two_point(cmd[j].arg_cmd);
		j ++;
	}
	free(cmd);
	free(g_ms.pid);
	g_ms.pid = NULL;
}

void	ft_free_exit(t_ms *ms, t_cmd *cmd)
{
	(void)ms;
	(void)cmd;

	rl_clear_history();
	ft_free_two_point(g_ms.envp);
}
