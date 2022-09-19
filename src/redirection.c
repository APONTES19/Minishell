/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 21:32:22 by lucasmar          #+#    #+#             */
/*   Updated: 2022/09/19 22:41:10 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_redirection(t_ms *ms, t_cmd *cmd)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while(i < ms->n_pipe)
	{
		j= 0;
		while(cmd[i].arg_cmd[j])
		{
			k = 0;
			while(cmd[i].arg_cmd[j][k])
			{
				printf("CMD[%d].ARG[%d:%d]|%c|\n",i,j,k,cmd[i].arg_cmd[j][k]);
				k++;
			}

			j++;
		}
		i++;
	}
}
