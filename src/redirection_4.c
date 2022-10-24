/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 15:22:52 by lucasmar          #+#    #+#             */
/*   Updated: 2022/10/24 20:00:47 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_red_copy_line_aux(t_ms *ms, int start, int end, char t)
{
	if (t == 'i')
	{
		ms->k = 0;
		ms->m = 0;
		while (g_ms.line[ms->k])
		{
			if (!(ms->k >= start && ms->k <= end))
				ms->m++;
			ms->k++;
		}
	}
	else if (t == 'f')
	{
		ms->temp[ms->m] = '\0';
		ft_free_point(g_ms.line);
		g_ms.line = ft_strdup(ms->temp);
		ft_free_point(ms->temp);
	}
}

int	ft_red_check_next(t_ms *ms)
{
	int	i;

	i = 1;
	if (g_ms.line[ms->i + i])
	{
		if (ft_strchr("<>", g_ms.line[ms->i + i]) != NULL)
		{
			i++;
			ms->type = 2;
		}
		while (g_ms.line[ms->i + i] == ' ')
			i++;
		if (ft_strchr("|><", g_ms.line[ms->i + i]) != NULL)
		{
			ft_error(30, ms, NULL, NULL);
			return (1);
		}
	}
	else
	{
		ft_error(30, ms, NULL, NULL);
		return (1);
	}
	return (0);
}
