/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 20:05:58 by lucasmar          #+#    #+#             */
/*   Updated: 2022/09/05 21:49:52 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_check_input(t_ms *ms)
{
	if (!ft_check_quote(ms))
	{
		ft_error(29, ms);
			return (1);
	}
	if (ft_special(ms) == 1)
		return (1);
	ft_check_pipe(ms);
	ft_check_$(ms);
	return (0);
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
			return (0);
		ms->i ++;
	}
	return (1);
}

void	ft_check_pipe(t_ms *ms)
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
			next_pipe(ms);
			ms->n_pipe++;
		}
		ms->i++;
	}
}

void	next_pipe(t_ms *ms)
{
	if (ms->i == 0)
	{
		if (ms->line[ms->i + 1] == '|')
			ft_error(19, ms);
		else
			ft_error(9, ms);
	}
	else
	{
		if (ms->line[ms->i + 1] == '|')
			ms->pipe_d = 1;
		//verificar como fazer isso
	}
}
