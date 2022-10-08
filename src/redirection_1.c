/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 21:32:22 by lucasmar          #+#    #+#             */
/*   Updated: 2022/10/08 16:49:45 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_redirection(t_ms *ms)
{
	int	type;

	ms->path_infile = NULL;
	ms->path_outfile = NULL;
	type = 1;
	ms->i = 0;
	while(ms->line[ms->i])
	{
		if (ms-> line[ms->i] == '>')
		{
			if (ms-> line[ms->i + 1] == '>')
				type = 2;
			ft_red_point(ms, type, &ms->path_outfile);
			ms->i = -1;
		}
		if (ms-> line[ms->i] == '<')
		{
			if (ms-> line[ms->i + 1] == '<')
				type = 2;
			ft_red_point(ms, type, &ms->path_infile);
			ms->i = -1;
		}
		ms->i++;
	}
	printf("|%s| -> |%s|\n", ms->path_infile,ms->path_outfile);
	if (ms->path_infile != NULL)
		ft_set_in(ms);
	if (ms->path_outfile != NULL)
		ft_set_out(ms, type);
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
			ms->end = ms->k;
		}
		if (ms->line[ms->k] == '\'')
			ft_red_point_aux(ms, 'a', type);
		if (ms->line[ms->k] == '\"')
		{
			ms->t = '\"';
			ft_red_point_aux(ms, 'a', type);
		}
		if (ms->line[ms->k] == ' ' || ms->line[ms->k] == '|')
			break;
		ms->end++;
		ms->k++;
	}
	ms->start = ms->start - type;
	ms->end = ms->end + ms->start;
	ft_red_temp(ms, ms->start, ms->end, path);
}

void	ft_red_point_aux(t_ms *ms, char f, int type)
{
	if (f == 'i')
	{
		ms->start = (ms->i + type);
		ms->k = ms->start;
		ms->end = 0;
		ms->t = '\'';
	}
	else
	{
		ms->k++;
		ms->end++;
		while(ms->line[ms->k] != ms->t)
		{
			ms->k++;
			ms->end++;
		}
	}
}

int	ft_set_out(t_ms *ms, int type)
{
	if(ms->path_outfile != NULL)
	{
		if (type == 1)
		{
			g_ms.fileout =
				open(ms->path_outfile,O_WRONLY | O_CREAT | O_TRUNC, 0644);
		}
		else
		{
			g_ms.fileout =
				open(ms->path_outfile,O_WRONLY  | O_CREAT | O_APPEND, 0644);
		}
		if (g_ms.fileout == -1)
		{
			ft_error(15, ms);
			return(1);
		}
	}
	return(0);
}

int	ft_set_in(t_ms *ms)
{
	if (type == 1)
	{
		g_ms.filein = open(ms->path_infile, O_RDONLY, 644);
		if (g_ms.filein == -1)
		{
			ft_error(14, ms);
			return(1);
		}
	}
	else
		// chamar função de herodoc
	return(0);
}
