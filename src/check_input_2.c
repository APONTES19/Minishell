/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 20:58:37 by lucasmar          #+#    #+#             */
/*   Updated: 2022/09/09 21:16:34 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_special(t_ms *ms)
{
	ms->i = 0;
	while (ms->line[ms->i])
	{
		if (ms->line[ms->i] == '\'')
		{
			ms->i++;
			while (ms->line[ms->i] != '\'')
				ms->i++;
		}
		if (ms->line[ms->i] == '\"')
		{
			ms->i++;
			while (ms->line[ms->i] != '\"')
				ms->i++;
		}
		if ((ft_strchr(SPECIAL_CH, ms->line[ms->i])))
		{
			ft_error(02, ms);
			return (0);
		}
		ms->i++;
	}
	return (1);
}

void	ft_check_$(t_ms *ms)
{
	ms->i = 0;
	ms->n_$ = 0;
	while(ms->line[ms->i])
	{
		if (ms->line[ms->i] == '\'')
		{
			ms->i++;
			while(ms->line[ms->i] != '\'')
				ms->i++;
		}
		if (ms->line[ms->i] == '\"')
		{
			ms->i++;
			while(ms->line[ms->i] != '\"')
			{
				if(ms->line[ms->i] == '$')
					ms->n_$++;
				ms->i++;
			}
		}
		ms->i++;
	}
}
