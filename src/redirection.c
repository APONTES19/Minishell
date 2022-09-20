/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 21:32:22 by lucasmar          #+#    #+#             */
/*   Updated: 2022/09/21 00:38:25 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_redirection(t_ms *ms)
{
	ms->i = 0;
	while(ms->line[ms->i] != '\0')
	{
		if (ms->line[ms->i] == '>')
			ms->i += (ft_path_output(ms));
		if (ms->line[ms->i] == '<')
			ms->i += (ft_path_output(ms));
		if (ms->line[ms->i] != '\0')
			ms->i++;
	}
	printf("|%s|\n", ms->path_outfile);
	printf("|%s|\n", ms->path_infile);
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
		if (ms->line[i] == ' ' && j > 1)
			break;
		j++;
		i++;
	}
	if(ms->line[ms->i] == '>')
		ms->path_outfile = malloc (j * sizeof(char) + 1);
	else
		ms->path_infile = malloc (j * sizeof(char) + 1);
	ft_dup_path(j, start, ms);
	return(j);
}

void	ft_dup_path(int end, int start, t_ms *ms)
{
	int	i;
	int	k;
	int j;

	i = 0;
	k = 0;
	j = 1;
	if(start == 0)
		j = 0;
	while (k <= end)
	{
		if(ms->line[start] != ' ' && ms->line[start] != '>'
			&& ms->line[start] != '<')
		{
			ms->path_outfile[i] = ms->line[start];
			i++;
		}
		if(j == 1)
			ms->line[start] = '\0';
		start++;
		k++;
	}
	i++;
	ms->path_outfile[i] = '\0';
	if (j == 0)
	{
		while (ms->line[end] != '\0')
		{
			end++;
			ms->line[j] = ms->line[end];
			j++;
		}
		ms->line[j] = '\0';
	}
}
