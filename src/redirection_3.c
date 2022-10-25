/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 09:35:00 by lucasmar          #+#    #+#             */
/*   Updated: 2022/10/24 21:54:29 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	ft_ctrl_d(char *str);

void	ft_redirection_aux(t_ms *ms, char q)
{
	ms->i++;
	while (g_ms.line[ms->i] != q)
		ms->i++;
	if (g_ms.line[ms->i + 1])
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
		if (!line)
		{
			free (line);
			if (g_ms.open_hero_doc == 1)
				ft_ctrl_d(str);
			return (-1);
		}
		else if (ft_strncmp_m(line, str) == 1)
			ft_putendl_fd(line, g_ms.fo);
		else
		{
			ft_free_point(line);
			close(g_ms.fo);
			return (open(".hero_doc", O_RDONLY, 644));
		}
		ft_free_point(line);
	}
}

static void	ft_ctrl_d(char *str)
{
	close (g_ms.fo);
	printf (" warning: here-document delimited by"
		" end-of-file (wanted `%s')\n", str);
}

int	ft_set_out(t_ms *ms, int type)
{
	if (g_ms.path_outfile != NULL)
	{
		if (type == 1)
		{
			g_ms.fileout
				= open (g_ms.path_outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		}
		else
		{
			g_ms.fileout
				= open (g_ms.path_outfile, O_WRONLY | O_CREAT | O_APPEND, 0644);
		}
		if (g_ms.fileout == -1)
		{
			ft_free_point(g_ms.path_outfile);
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
		g_ms.filein = ft_here_doc_open(g_ms.path_infile);
		if (g_ms.filein == -1)
		{
			ft_free_point(g_ms.path_infile);
			return (1);
		}
		signal (SIGQUIT, ft_quit);
		g_ms.open_hero_doc = 0;
	}
	else
		g_ms.filein = open(g_ms.path_infile, O_RDONLY, 644);
	if (g_ms.filein == -1)
	{
		ft_error(12, ms, NULL, NULL);
		return (1);
	}
	return (0);
}
