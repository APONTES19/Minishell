/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 15:22:52 by lucasmar          #+#    #+#             */
/*   Updated: 2022/10/25 10:53:56 by lucasmar         ###   ########.fr       */
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

void	ft_red_point(t_ms *ms, int type, char **path)
{
	ft_red_point_aux(ms, 'i', type);
	while (g_ms.line[ms->k])
	{
		if (ms->k == ms->start)
		{
			while (g_ms.line[ms->k] == ' ')
				ms->k++;
		}
		if (g_ms.line[ms->k] == '\'')
			ft_red_point_aux(ms, 'a', type);
		if (g_ms.line[ms->k] == '\"')
		{
			ms->t = '\"';
			ft_red_point_aux(ms, 'a', type);
		}
		if (ft_strchr("| ><", g_ms.line[ms->k]) != NULL)
			break ;
		ms->k++;
	}
	ms->start = ms->start - type;
	ms->end = ms->k;
	ms->end--;
	ft_red_temp(ms, ms->start, ms->end, path);
}

void	ft_red_point_aux(t_ms *ms, char f, int type)
{
	if (f == 'i')
	{
		ms->start = (ms->i + type);
		ms->k = ms->start;
		ms->end = ms->k;
		ms->t = '\'';
	}
	else
	{
		ms->k++;
		while (g_ms.line[ms->k] != ms->t)
			ms->k++;
	}
}
