/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 14:27:22 by lucasmar          #+#    #+#             */
/*   Updated: 2022/10/24 10:17:56 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_set_line_dollar(t_ms *ms)
{
	ms->i = 0;
	while (g_ms.line[ms->i])
	{
		if (g_ms.line[ms->i] == '\'')
			ft_redirection_aux(ms, '\'');
		if (g_ms.line[ms->i] == '\"')
			ft_aux_dollar_1(ms);
		if (ms->i >= 0 && g_ms.line[ms->i] == '$')
		{
			if (ft_strchr(" |", g_ms.line[ms->i + 1]) != NULL)
			{
				if (g_ms.line[ms->i + 1])
					ms->i++;
			}
			else
			{
				ft_get_path_dollar(ms);
				ms->i = -1;
			}
		}
		ms->i++;
	}
	return (0);
}

void	ft_aux_dollar_1(t_ms *ms)
{
	ms->i++;
	while (g_ms.line[ms->i] != '\"')
	{
		if (g_ms.line[ms->i] == '$')
		{
			if (ft_strchr(" |", g_ms.line[ms->i + 1]) != NULL)
			{
				if (g_ms.line[ms->i + 1] != '\0')
				{
					if (g_ms.line[ms->i + 1] != '\0')
						ms->i++;
				}
			}
			else
			{
				ft_get_path_dollar(ms);
				ms->i = -1;
				break ;
			}
		}
		ms->i++;
	}
}

void	ft_get_path_dollar(t_ms *ms)
{
	char	*temp;
	char	*temp2;

	ms->start = ms->i + 1;
	ms->k = ms->start;
	ms->j = 0;
	while (ft_strchr(" |\"\'", g_ms.line[ms->k]) == NULL)
		ms->k++;
	ms->end = (ms->k - ms->start);
	temp = ft_substr(g_ms.line, ms->start, ms->end);
	temp2 = NULL;
	ft_aux_dollar_2(ms, &temp, &temp2);
	ft_change_line_dollar(ms, &temp2);
	if (ms->j == 0)
		ft_free_point(temp2);
	ft_free_point(temp);
}

void	ft_aux_dollar_2(t_ms *ms, char **temp, char **temp2)
{
	if (ft_strncmp_m(*temp, "0") == 0)
	{
		*temp2 = ft_strdup("-minishell");
	}
	else if (ft_strncmp_m(*temp, "PWD") == 0)
	{
		*temp2 = ft_getenv(*temp);
		if (*temp2 == NULL)
		{
			*temp2 = (char *) malloc (1024 * sizeof(char));
			getcwd(*temp2, 1024);
		}
		else
			*temp2 = ft_strdup (ft_getenv(*temp));
	}
	ft_aux_dollar_3(ms, temp, temp2);
}

void	ft_aux_dollar_3(t_ms *ms, char **temp, char **temp2)
{
	if (ft_strncmp_m(*temp, "?") == 0)
		*temp2 = ft_itoa(g_ms.exit_s);
	else if (*temp2 == NULL)
	{
		*temp2 = ft_getenv(*temp);
		if (*temp2 == NULL)
			*temp2 = ft_strdup("");
		else
			ms->j = -1;
	}
}
