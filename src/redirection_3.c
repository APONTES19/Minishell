/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 09:35:00 by lucasmar          #+#    #+#             */
/*   Updated: 2022/10/13 19:34:56 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_redirection_aux(t_ms *ms, char q)
{
	ms->i++;
	while (ms-> line[ms->i] != q)
		ms->i++;
}

int	ft_here_doc_open(char *str)
{
	char	*line;
	int		fd;

	fd = open(".hero_doc", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	while (1)
	{
		line = readline(">");
		if (ft_strncmp(line, str, ft_strlen(line)) != 0)
		{
			write (fd, line, ft_strlen(line));
			write (fd, "\n", 1);
		}
		else
		{
			free (line);
			line = NULL;
			close(fd);
			return (open(".hero_doc", O_RDONLY, 644));
		}
		free(line);
	}
	return (-1);
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
			ft_error(13, ms, NULL);
			return(1);
		}
	}
	return(0);
}

int	ft_set_in(t_ms *ms, int type)
{
	if (type == 2)
	{
		g_ms.filein = ft_here_doc_open(ms->path_infile);
		unlink(".hero_doc");
	}
	else
		g_ms.filein = open(ms->path_infile, O_RDONLY, 644);
	if (g_ms.filein == -1)
	{
		ft_error(12, ms, NULL);
		return(1);
	}
	return(0);
}
