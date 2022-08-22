/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argument.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 08:50:05 by ryoshio-          #+#    #+#             */
/*   Updated: 2022/08/22 09:18:23 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	ft_check_quote(t_ms	*ms);
static int ft_check_special(t_ms	*ms);

static int	ft_check_quote(t_ms	*ms)
{
	int	i;

	i = 0;
	while (ms->cmd[i])
	{
		if (ms->cmd[i] == '\'')
		{
			i ++;
			while (ms->cmd[i] != '\'' && ms->cmd[i])
				i++;
		}
		if (ms->cmd[i] == '\"')
		{
			i ++;
			while (ms->cmd[i] != '\"' && ms->cmd[i])
				i++;
		}
		if (!ms->cmd[i])
			return (0);
		i ++;
	}
	return (1);
}

static int ft_check_special(t_ms	*ms)
{
	int	i;

	i = 0;
	while(ms->cmd[i])
	{
		if(ms->cmd[i] == '\'')
			i+= ft_strlen(&ms->cmd[i]) - ft_strlen(ft_strchr(&ms->cmd[i+1], '\'')) ;
		if(ms->cmd[i] == '\"')
			i+= ft_strlen(&ms->cmd[i]) - ft_strlen(ft_strchr(&ms->cmd[i+1], '\"'));
		if((ft_strchr(SPECIAL_CH, ms->cmd[i])))
			return(1);

		i++;
	}
	return(0);
}

int ft_check_argument(t_ms	*ms)
{
	if(!ft_check_quote(ms))
	{
		ft_printf("quote is missing");
		return (0);
	}
	if(ft_check_special(ms))
	{
		ft_printf("I have caracter especial");
		return (0);
	}
	return (1);
}
