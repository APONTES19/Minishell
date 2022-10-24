/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 21:32:22 by lucasmar          #+#    #+#             */
/*   Updated: 2022/10/24 17:07:18 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_redirection(t_ms *ms)
{
	ms->type = 1;
	ms->i = 0;
	ms->q = '\'';
	while (g_ms.line[ms->i])
	{
		if (g_ms.line[ms->i] == ms->q || g_ms.line[ms->i] == '\"')
		{
			if (g_ms.line[ms->i] == '\"')
				ms->q = '\"';
			ft_redirection_aux(ms, ms->q);
		}
		if (g_ms.line[ms->i] == '<')
		{
			if (ft_red_check_next(ms) == 1)
				return (1);
			ft_red_point(ms, ms->type, &g_ms.path_infile);
			if (ft_redirection_3(ms, ms->type) == 1)
				return (1);
			ms->i = -1;
		}
		ms->i++;
	}
	if (ft_redirection_2(ms) == 1)
		return (1);
	return (0);
}

int	ft_redirection_2(t_ms *ms)
{
	char	q;

	q = '\'';
	ms->i = 0;
	ms->type = 1;
	while (g_ms.line[ms->i])
	{
		if (g_ms.line[ms->i] == q || g_ms.line[ms->i] == '\"')
		{
			if (g_ms.line[ms->i] == '\"')
				q = '\"';
			ft_redirection_aux(ms, q);
		}
		if (g_ms.line[ms->i] == '>')
		{
			if (ft_red_check_next(ms) == 1)
				return (1);
			ft_red_point(ms, ms->type, &g_ms.path_outfile);
			if (ft_redirection_3(ms, ms->type) == 1)
				return (1);
			ms->i = -1;
		}
		ms->i++;
	}
	return (0);
}

int	ft_redirection_3(t_ms *ms, int type)
{
	if (g_ms.path_infile != NULL)
	{
		if (ft_strncmp_m(g_ms.line, "") == 0
			&& ft_strncmp_m(g_ms.path_infile, "") == 0)
		{
			ft_error(26, ms, NULL, NULL);
			return (1);
		}
		else if (ft_set_in(ms, type) == 1)
			return (1);
	}
	if (g_ms.path_outfile != NULL)
	{
		if (ft_strncmp_m(g_ms.line, "") == 0
			&& ft_strncmp_m(g_ms.path_outfile, "") == 0)
		{
			ft_error(26, ms, NULL, NULL);
			return (1);
		}
		else if (ft_set_out(ms, type) == 1)
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
