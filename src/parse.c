/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 18:03:23 by lucasmar          #+#    #+#             */
/*   Updated: 2022/09/05 22:21:18 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_comand_split(t_ms *ms, t_cmd *cmd, char **envp)
{
	if(ms->n_pipe > 1)
	{
		cmd = (t_cmd *) malloc (ms->n_pipe * sizeof (t_cmd));
		cmd->base_list_cmd = ft_split_ms(ms->line, '|');

		//excluir debug
		ms->i = 0;
		printf("\n__________Base list__________\n");
		while(ms->i != ms->n_pipe)
		{
			printf("arg[%d]%s\n",ms->i,cmd->base_list_cmd[ms->i]);
			ms->i++;
		}
		printf("\n__________Fim Base list__________\n");

		ms->i = 0;
		while(ms->i != ms->n_pipe)
		{
			cmd[ms->i].arg_cmd = ft_split_ms(cmd->base_list_cmd[ms->i], ' ');
			ms->i++;
		}

		//excluir este movimento só os printf.
		printf("\n_________Aqui começa o split do pipe __________\n");
		ms->i = 0;
		while(ms->i != ms->n_pipe)
		{
			printf("Struc cmd[%d]\n",ms->i);
			ms->j = 0;
			while(cmd[ms->i].arg_cmd[ms->j])
			{
				//ft_change_pipe(ms, cmd[ms->i].arg_cmd[ms->j], '\t', '|');
				printf("\tArg[%d]%s\n",ms->j,cmd[ms->i].arg_cmd[ms->j]);
				ms->j++;
			}
			ms->i++;
		}
		printf("_________Aqui termina o split do pipe __________\n\n");
	}
	else
	{
		ms->i = 0;
		cmd = (t_cmd *) malloc (ms->n_pipe * sizeof (t_cmd));
		cmd[ms->i].arg_cmd = ft_split_ms(ms->line, ' ');

	//excluir este movimento.
		printf("\n_________Aqui começa o split __________\n");
		while(ms->i != ms->n_pipe)
		{
			ms->j = 0;
			while(cmd[ms->i].arg_cmd[ms->j])
			{
				printf("Arg[%d]%s\n",ms->j,cmd[ms->i].arg_cmd[ms->j]);
				ms->j++;
			}
			ms->i++;
		}
		printf("_________Aqui termina o split __________\n\n");
	}
	if(ft_get_path(ms, cmd[0].arg_cmd[0], envp) != 0)
		ft_error(10, ms);
	else
		ft_execve(ms, cmd[0].arg_cmd);
	//ft_base_free(ms, cmd);
}
