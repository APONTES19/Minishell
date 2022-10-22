/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 20:58:37 by lucasmar          #+#    #+#             */
/*   Updated: 2022/10/21 23:04:40 by lucasmar         ###   ########.fr       */
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
			ft_error(02, ms, NULL, NULL);
			return (1);
		}
		ms->i++;
	}
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
			ft_error (01, ms, NULL, NULL);
			return (1);
		}
	}
	return (0);
}

int	ft_check_dolar(t_ms *ms)
{
	ms->i = 0;
	ms->n_dollar = 0;
	while (ms->line[ms->i])
	{
		if (ms->line[ms->i] == '$')
			ms->n_dollar++;
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
			{
				if (ms->line[ms->i] == '$')
					ms->n_dollar++;
				ms->i++;
			}
		}
		ms->i++;
	}
	return (ms->n_dollar);
}

void	ft_check_space(t_ms *ms)
{
	int	i;
	int	k;
	int	j;

	i = 0;
	k = 0;
	j = 0;
	while (ms->line[i] != '\0')
	{
		if (ms->line[i] != ' ')
		{
			j++;
			break ;
		}
		else if (ms->line[i] == ' ' && j == 0)
			k++;
		i++;
	}
	i = 0;
	while (ms->line[k] != '\0')
	{
		ms->line[i++] = ms->line[k];
		k++;
	}
	ms->line[i] = '\0';
}

int	ft_check_redirection(t_ms *ms)
{
	ms->i = 0;
	ms->redirection = 0;
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
		if (ms->line[ms->i] == '>' || ms->line[ms->i] == '<')
			ms->redirection++;
		ms->i++;
	}
	return (ms->redirection);
}
