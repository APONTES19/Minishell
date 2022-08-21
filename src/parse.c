/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 18:03:23 by lucasmar          #+#    #+#             */
/*   Updated: 2022/08/21 22:21:28 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_special(t_ms *ms)
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
		{
			ft_printf("invalid character: %c\n", ms->cmd[i]);
			return(1);
		}
		i++;
	}
	return(0);
}
