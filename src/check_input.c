/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 20:05:58 by lucasmar          #+#    #+#             */
/*   Updated: 2022/09/09 22:16:55 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_check_input(t_ms *ms)
{
	if (ft_check_quote(ms) == 0)
		return (0);
	if (ft_special(ms) == 0)
		return (0);
	if (ft_check_pipe(ms) == 0)
		return (0);
	ft_check_$(ms);
	return (1);
}

int	ft_check_quote(t_ms *ms)
{
	ms->i = 0;
	while (ms->line[ms->i])
	{
		if (ms->line[ms->i] == '\'')
		{
			ms->i ++;
			while (ms->line[ms->i] != '\'' && ms->line[ms->i])
				ms->i++;
		}
		if (ms->line[ms->i] == '\"')
		{
			ms->i ++;
			while (ms->line[ms->i] != '\"' && ms->line[ms->i])
				ms->i++;
		}
		if (!ms->line[ms->i])
		{
			ft_error(01, ms);
			return (0);
		}
		ms->i ++;
	}
	return (1);
}

int	ft_check_pipe(t_ms *ms)
{
	ms->i = 0;
	ms->n_pipe = 1;
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
		if (ms->line[ms->i] == '|')
		{
			if (next_pipe(ms) == 0)
				return(0);
			ms->n_pipe++;
		}
		ms->i++;
	}
	return(1);
}

int	next_pipe(t_ms *ms)
{
	if (ms->i == 0)
	{
		if (ms->line[ms->i + 1] == '|')
		{
			ft_error(04, ms);
			return (0);
		}
		else
		{
			ft_error(03, ms);
			return (0);
		}
	}
	else if (ms->line[ms->i + 1] == '|')
	{
		//ms->pipe_d = 1;
		//ms->line[ms->i + 1] = ' ';
		ft_error(04, ms);
		return (0);
	}
	return(1);
}
