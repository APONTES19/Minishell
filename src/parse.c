/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 18:03:23 by lucasmar          #+#    #+#             */
/*   Updated: 2022/09/10 05:18:59 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_comand_split(t_ms *ms, t_cmd *cmd, char **envp)
{
	(void )envp;
	if(ms->n_pipe > 1)
	{
		cmd = (t_cmd *) malloc (ms->n_pipe * sizeof (t_cmd));
		cmd->base_list_cmd = ft_split_ms(ms->line, '|');
		ms->i = 0;
		while(ms->i != ms->n_pipe)
		{
			cmd[ms->i].arg_cmd = ft_split_ms(cmd->base_list_cmd[ms->i], ' ');
			ms->i++;
		}
	}
	else
	{
		ms->i = 0;
		cmd = (t_cmd *) malloc (ms->n_pipe * sizeof (t_cmd));
		cmd[ms->i].arg_cmd = ft_split_ms(ms->line, ' ');
	}
	ft_central(ms, cmd);


	//if(ft_get_path(ms, cmd[0].arg_cmd[0], envp) == 0)
	//	ft_error_2(07, cmd, ms);
	//else
	//	ft_execve(ms, cmd[0].arg_cmd, cmd);
	//ft_base_free(ms, cmd);
	return (1);
}
