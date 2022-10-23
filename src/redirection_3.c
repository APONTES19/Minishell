/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 09:35:00 by lucasmar          #+#    #+#             */
/*   Updated: 2022/10/23 09:15:12 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_redirection_aux(t_ms *ms, char q)
{
	ms->i++;
	while (ms-> line[ms->i] != q)
		ms->i++;
	if (ms-> line[ms->i + 1])
		ms->i++;
}

int	ft_here_doc_open(char *str)
{
	char	*line;

	signal (SIGQUIT, SIG_IGN);
	g_ms.fo = open(".hero_doc", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	while (1)
	{

		line = readline(">");
		if(!line)
			return(-1);
		else if (ft_strncmp_m(line, str) == 1)
		{
			write (g_ms.fo, line, ft_strlen(line));
			write (g_ms.fo, "\n", 1);
		}
		else
		{
			ft_free_point(line);
			close(g_ms.fo);
			return (open(".hero_doc", O_RDONLY, 644));
		}
		ft_free_point(line);
	}
}

int	ft_set_out(t_ms *ms, int type)
{
	if (ms->path_outfile != NULL)
	{
		if (type == 1)
		{
			g_ms.fileout
				= open (ms->path_outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		}
		else
		{
			g_ms.fileout
				= open (ms->path_outfile, O_WRONLY | O_CREAT | O_APPEND, 0644);
		}
		if (g_ms.fileout == -1)
		{
			ft_error(13, ms, NULL, NULL);
			return (1);
		}
	}
	return (0);
}

int	ft_set_in(t_ms *ms, int type)
{
	if (type == 2)
	{
		g_ms.open_hero_doc = 1;
		signal (SIGQUIT, SIG_IGN);
		g_ms.filein = ft_here_doc_open(ms->path_infile);
		if (g_ms.filein == -1)
		{
			return (1);
		}
		signal (SIGQUIT, ft_quit);
		g_ms.open_hero_doc = 0;
	}
	else
		g_ms.filein = open(ms->path_infile, O_RDONLY, 644);
	if (g_ms.filein == -1)
	{
		ft_error(12, ms, NULL, NULL);
		return (1);
	}
	return (0);
}

void	ft_red_copy_line_aux(t_ms **ms, int start, int end, char t)
{
	if (t == 'i')
	{
		(*ms)->k = 0;
		(*ms)->m = 0;
		while ((*ms)->line[(*ms)->k])
		{
			if (!((*ms)->k >= start && (*ms)->k <= end))
				(*ms)->m++;
			(*ms)->k++;
		}
	}
	else if (t == 'f')
	{
		(*ms)->temp[(*ms)->m] = '\0';
		ft_free_point((*ms)->line);
		(*ms)->line = ft_strdup((*ms)->temp);
		ft_free_point((*ms)->temp);
	}
}
