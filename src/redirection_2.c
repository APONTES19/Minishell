/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 15:24:19 by lucasmar          #+#    #+#             */
/*   Updated: 2022/10/24 17:02:40 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_red_temp(t_ms *ms, int start, int end, char **path)
{
	ms->k = start;
	ms->m = 0;
	ms->t = '\'';
	while (ms->k <= end)
	{
		if (g_ms.line[ms->k] == '\'')
			ft_red_temp_aux1(ms);
		if (g_ms.line[ms->k] == '\"')
		{
			ms->t = '\"';
			ft_red_temp_aux1(ms);
		}
		if (ft_strchr("| ><", g_ms.line[ms->k]) == NULL)
			ms->m++;
		ms->k++;
	}
	ft_red_temp_aux2(ms, start, end, path);
}

void	ft_red_temp_aux1(t_ms *ms)
{
	ms->k++;
	ms->m++;
	while (g_ms.line[ms->k] != ms->t)
	{
		ms->m++;
		ms->k++;
	}
}

void	ft_red_temp_aux2(t_ms *ms, int start, int end, char **path)
{
	ms->t = '\'';
	*path = (char *)malloc((ms->m + 1) * sizeof(char *));
	ms->k = start;
	ms->m = 0;
	while (ms->k <= end)
	{
		if (g_ms.line[ms->k] == '\'')
			ft_red_temp_aux3(ms, path);
		if (g_ms.line[ms->k] == '\"')
		{
			ms->t = '\"';
			ft_red_temp_aux3(ms, path);
		}
		if (ft_strchr("| ><", g_ms.line[ms->k]) == NULL)
		{
			(*path)[ms->m] = g_ms.line[ms->k];
			ms->m++;
		}
		ms->k++;
	}
	(*path)[ms->m] = '\0';
	ft_red_copy_line(ms, start, end);
}

void	ft_red_temp_aux3(t_ms *ms, char **path)
{
	(*path)[ms->m] = g_ms.line[ms->k];
	ms->m++;
	ms->k++;
	while (g_ms.line[ms->k] != ms->t)
	{
		(*path)[ms->m] = g_ms.line[ms->k];
		ms->m++;
		ms->k++;
	}
}

void	ft_red_copy_line(t_ms *ms, int start, int end)
{
	ft_red_copy_line_aux(ms, start, end, 'i');
	ms->temp = (char *) malloc ((ms->m + 1) * sizeof(char *));
	ms->k = 0;
	ms->m = 0;
	while (g_ms.line[ms->k])
	{
		if (!(ms->k <= end && ms->k >= start))
		{
			if (ms->m == 0 && (ft_strchr("| ", g_ms.line[ms->k]) != NULL))
				ms->k++;
			if (g_ms.line[ms->k])
			{
				ms->temp[ms->m] = g_ms.line[ms->k];
				ms->m++;
			}
		}
		ms->k++;
	}
	ft_red_copy_line_aux(ms, start, end, 'f');
}
