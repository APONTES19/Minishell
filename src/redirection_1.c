/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 21:32:22 by lucasmar          #+#    #+#             */
/*   Updated: 2022/10/25 10:53:53 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	ft_aux_redirection(t_ms *ms);

int	ft_redirection(t_ms *ms)
{
	ft_aux_redirection(ms);
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
			if (g_ms.path_infile != NULL)
				ft_free_point(g_ms.path_infile);
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

static void	ft_aux_redirection(t_ms *ms)
{
	ms->type = 1;
	ms->i = 0;
	ms->q = '\'';
}

int	ft_redirection_2(t_ms *ms)
{
	ms->t = '\'';
	ms->i = 0;
	ms->type = 1;
	while (g_ms.line[ms->i])
	{
		if (g_ms.line[ms->i] == ms->t || g_ms.line[ms->i] == '\"')
		{
			if (g_ms.line[ms->i] == '\"')
				ms->t = '\"';
			ft_redirection_aux(ms, ms->t);
		}
		if (g_ms.line[ms->i] == '>')
		{
			if (ft_red_check_next(ms) == 1)
				return (1);
			if (g_ms.path_outfile != NULL)
				ft_free_point(g_ms.path_outfile);
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
