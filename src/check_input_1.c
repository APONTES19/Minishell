/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 20:05:58 by lucasmar          #+#    #+#             */
/*   Updated: 2022/10/16 15:05:07 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_check_input(t_ms *ms, t_cmd *cmd)
{
	if (ft_check_quote(ms) == 1)
		return (1);
	if (ft_special(ms) == 1)
		return (1);
	if ((ft_check_redirection(ms)) != 0)
	{
		if (ft_redirection(ms) == 1)
			return (1);
	}
	if (ft_check_pipe(ms) == 1)
		return (1);
	if (ft_check_dolar(ms) != 0)
	{
		if (ft_set_line_dollar(ms) == 1)
			return (1);
	}
	if (ft_command_split(ms, cmd) == 1)
		return (1);
	return (0);
}

int	ft_check_quote(t_ms *ms)
{
	ms->i = -1;
	ms->quote = 0;
	while (ms->line[++ ms->i])
	{
		if (ms->line[ms->i] == '\'')
		{
			(ms->quote) = 1;
			ms->i ++;
			while (ms->line[ms->i] != '\'' && ms->line[ms->i])
				ms->i++;
		}
		if (ms->line[ms->i] == '\"')
		{
			ms->quote = 1;
			ms->i ++;
			while (ms->line[ms->i] != '\"' && ms->line[ms->i])
				ms->i++;
		}
		if (!ms->line[ms->i])
		{
			ft_error(01, ms, NULL);
			return (1);
		}
	}
	return (0);
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
			if (ft_next_pipe(ms) == 1)
				return (1);
			ms->n_pipe++;
		}
		ms->i++;
	}
	return (0);
}

int	ft_next_pipe(t_ms *ms)
{
	ms->k = ms->i+1;
	while (ms->line[ms->k] != '\0')
	{
		while (ms->line[ms->k] == ' ')
			ms->k++;
		break;
	}
	if (ms->line[ms->k] == '\0')
	{
		ft_error(24, ms, NULL);
		return(1);
	}
	if (ms->i == 0)
	{
		if (ms->line[ms->i + 1] == '|')
		{
			ft_error(04, ms, NULL);
			return (1);
		}
		else
		{
			ft_error(03, ms, NULL);
			return (1);
		}
	}
	else
		if (ft_next_pipe_2(ms) == 1)
			return (1);
	return (0);
}

int	ft_next_pipe_2(t_ms *ms)
{
	while (ms->line[ms->i +1] == ' ')
		ms->i++;
	if (ms->line[ms->i + 1] == '|')
	{
		if(ms->line[ms->i + 2] == '|')
		{
			ft_error(04, ms, NULL);
			return (1);
		}
		else
		{
			ms->n_pipe--;
			while (ms->line[ms->i])
			{
				ms->line[ms->i] = ' ';
				ms->i++;
			}
		}
	}
	return (0);
}
