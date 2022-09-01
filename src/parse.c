/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 18:03:23 by lucasmar          #+#    #+#             */
/*   Updated: 2022/09/01 23:20:10 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_special(t_ms *ms)
{
	ms->i = 0;
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
				ms->i++;
		}
		if((ft_strchr(SPECIAL_CH, ms->line[ms->i])))
		{
			ft_printf("invalid character: %c\n", ms->line[ms->i]);
			return(1);
		}
		ms->i++;
	}
	return(0);
}

void	ft_check_pipe(t_ms *ms)
{
	ms->i = 0;
	ms->n_pipe = 1;
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
				ms->i++;
		}
		if(ms->line[ms->i] == '|')
			ms->n_pipe++;
		ms->i++;
	}
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

void	ft_comand_split(t_ms *ms, t_cmd *cmd)
{
	printf("numero de pipe: %d\n", ms->n_pipe);//apagar linha só check
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
			cmd[ms->i].list_cmd = ft_split_ms(cmd->base_list_cmd[ms->i], ' ');
			ms->i++;
		}

		//excluir este movimento só os printf.
		printf("\n_________Aqui começa o split do pipe __________\n");
		ms->i = 0;
		while(ms->i != ms->n_pipe)
		{
			printf("Struc cmd[%d]\n",ms->i);
			ms->j = 0;
			while(cmd[ms->i].list_cmd[ms->j])
			{
				//ft_change_pipe(ms, cmd[ms->i].list_cmd[ms->j], '\t', '|');
				printf("\tArg[%d]%s\n",ms->j,cmd[ms->i].list_cmd[ms->j]);
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
		cmd[ms->i].list_cmd = ft_split_ms(ms->line, ' ');

	//excluir este movimento.
		printf("\n_________Aqui começa o split __________\n");
		while(ms->i != ms->n_pipe)
		{
			ms->j = 0;
			while(cmd[ms->i].list_cmd[ms->j])
			{
				printf("Arg[%d]%s\n",ms->j,cmd[ms->i].list_cmd[ms->j]);
				ms->j++;
			}
			ms->i++;
		}
		printf("_________Aqui termina o split __________\n\n");
	}
}
