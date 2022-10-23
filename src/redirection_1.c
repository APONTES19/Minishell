/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 21:32:22 by lucasmar          #+#    #+#             */
/*   Updated: 2022/10/23 18:52:01 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_redirection(t_ms *ms)
{
	ms->type = 1;
	ms->i = 0;
	ms->q = '\'';
	while (ms->line[ms->i])
	{
		if (ms-> line[ms->i] == ms->q || ms-> line[ms->i] == '\"')
		{
			if (ms-> line[ms->i] == '\"')
				ms->q = '\"';
			ft_redirection_aux(ms, ms->q);
		}
		if (ms-> line[ms->i] == '<')
		{
			if (ft_red_check_next(ms) == 1)
				return (1);
			ft_red_point(ms, ms->type, &ms->path_infile);
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
	while (ms->line[ms->i])
	{
		if (ms-> line[ms->i] == q || ms-> line[ms->i] == '\"')
		{
			if (ms-> line[ms->i] == '\"')
				q = '\"';
			ft_redirection_aux(ms, q);
		}
		if (ms-> line[ms->i] == '>')
		{
			if (ft_red_check_next(ms) == 1)
				return (1);
			ft_red_point(ms, ms->type, &ms->path_outfile);
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
	if (ms->path_infile != NULL)
	{
		if (ft_strncmp_m(ms->line, "") == 0
			&& ft_strncmp_m(ms->path_infile, "") == 0)
		{
			ft_error(26, ms, NULL, NULL);
			return (1);
		}
		else if (ft_set_in(ms, type) == 1)
			return (1);
	}
	if (ms->path_outfile != NULL)
	{
		if (ft_strncmp_m(ms->line, "") == 0
			&& ft_strncmp_m(ms->path_outfile, "") == 0)
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
	while (ms->line[ms->k])
	{
		if (ms->k == ms->start)
		{
			while (ms->line[ms->k] == ' ')
				ms->k++;
		}
		if (ms->line[ms->k] == '\'')
			ft_red_point_aux(ms, 'a', type);
		if (ms->line[ms->k] == '\"')
		{
			ms->t = '\"';
			ft_red_point_aux(ms, 'a', type);
		}
		if (ft_strchr("| ><", ms->line[ms->k]) != NULL)
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
		while (ms->line[ms->k] != ms->t)
			ms->k++;
	}
}
