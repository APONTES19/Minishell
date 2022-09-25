/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 20:58:37 by lucasmar          #+#    #+#             */
/*   Updated: 2022/09/23 22:52:35 by lucasmar         ###   ########.fr       */
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

int	ft_check_redirection(t_ms *ms)
{
	ms->i = 0;
	ms-> redirection = 0;
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
	return(ms->redirection);
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
			break;
		}
		else if (ms->line[i] == ' ' && j == 0)
			k++;
		i++;
	}
	i = 0;
	while(ms->line[k] != '\0')
	{
		ms->line[i] = ms->line[k];
		k++;
		i++;
	}
	ms->line[i] = '\0';
}

void	ft_copy_envp(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
		i++;
	g_envp = (char **) malloc(i * sizeof(char **));
	i = 0;
	while (envp[i])
	{
		g_envp[i] = ft_strdup(envp[i]);
		i++;
	}
	g_envp[i] = NULL;
}
