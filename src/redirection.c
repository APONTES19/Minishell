/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 21:32:22 by lucasmar          #+#    #+#             */
/*   Updated: 2022/09/21 21:51:44 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_redirection(t_ms *ms)
{
	ms->path_outfile = NULL;
	ms->path_infile = NULL;
	ms->i = 0;
	while(ms->line[ms->i] != '\0')
	{
		if (ms->line[ms->i] == '>')
			ms->i = (ft_path_output(ms));
		if (ms->line[ms->i] == '<')
			ms->i = (ft_path_output(ms));
		ms->i++;
	}
	printf("line=%s\n", ms->line);
	return(ft_set_out_in(ms));
}

int	ft_path_output(t_ms *ms)
{
	int	start;
	int	j;
	int	i;

	start = ms->i;
	i = start;
	j = 0;
	while (ms->line[i] != '\0')
	{
		if ((ms->line[i] == ' ' && j > 1) || ms->line[i] == '|')
			break;
		j++;
		i++;
	}
	if(ms->line[i] == '|')
		j--;
	if(ms->line[ms->i] == '>')
	{
		ms->path_outfile = malloc (j * sizeof(char));
		ft_dup_path(j, start, ms->path_outfile, ms);
	}
	else
	{
		ms->path_infile = malloc (j * sizeof(char));
			ft_dup_path(j, start, ms->path_infile, ms);
	}
	return(0);
}

void	ft_dup_path(int end, int start, char *path, t_ms *ms)
{
	int i;
	int	s;

	i = 0;
	ms->k = 0;
	ms->j = 1;
	s = start;
	while (ms->k <= end)
	{
		printf("k=%d e line=%c\n", ms->k, ms->line[start]);
		if(ms->line[start] != ' ' && ms->line[start] != '>'
			&& ms->line[start] != '<')
		{
			path[i] = ms->line[start];
			i++;
		}
		start++;
		ms->k++;
	}
	path[i] = '\0';
	ft_aux_dup_path(ms, s, end);
}

void	ft_aux_dup_path(t_ms *ms, int start, int end)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (ms->line[i] != '\0')
	{
		if (i == start)
			i += (end + 1);
		if(ms->line[i] == '|' && k == 0)
			i++;
		ms->line[k] = ms->line[i];
		k++;
		i++;
	}
	ms->line[k] = '\0';
}

int	ft_set_out_in(t_ms *ms)
{
	if(ms->path_infile != NULL)
	{
		printf("|%s|\n", ms->path_infile);
		ms->fd_in = open(ms->path_infile, O_RDONLY, 644);
		if (ms->fd_in == -1)
		{
			ft_error(14, ms);
			return(1);
		}
	}
	if(ms->path_outfile != NULL)
	{
		printf("|%s|\n", ms->path_outfile);
		ms->fd_out = open(ms->path_outfile,O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (ms->fd_out == -1)
		{
			ft_error(15, ms);
			return(1);
		}
	}
	return(0);
}
