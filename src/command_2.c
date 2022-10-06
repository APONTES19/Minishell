/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 19:21:39 by lucasmar          #+#    #+#             */
/*   Updated: 2022/10/06 20:46:10 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_command_split(t_ms *ms, t_cmd *cmd, char **envp)
{
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
	if (cmd[0].arg_cmd[0] == NULL)
	{
		ft_error(8, ms);
		return(0);
	}

	// printf("\n_________Aqui começa o split do pipe __________\n");
	// ms->i = 0;
	// while(ms->i != ms->n_pipe)
	// {
	// 	printf("Struc cmd[%d]\n",ms->i);
	// 	ms->j = 0;
	// 	while(cmd[ms->i].arg_cmd[ms->j])
	// 	{
	// 		if (cmd[ms->i].arg_cmd[ms->j][0] == '>')
	// 		{
	// 			if(cmd[ms->i].arg_cmd[ms->j][1] =='/0')
	// 				printf("lucas\n");
	// 		}
	// 		if (ft_strncmp(cmd[ms->i].arg_cmd[ms->j], "<", 1) == 0)
	// 			printf("porra\n");
	// 		printf("\tArg[%d]%s\n",ms->j,cmd[ms->i].arg_cmd[ms->j]);
	// 		ms->j++;
	// 	}
	// 	ms->i++;
	// }
	// printf("_________Aqui termina o split do pipe __________\n\n");
	ft_main_while(ms, cmd, envp);
	return(1);
}

int	ft_get_path(t_ms *ms, char *cmd, char **envp)
{
	ms->i = 0;
	while (envp[ms->i++])
	{
		if (!ft_strncmp(envp[ms->i], "PATH=", 5))
		{
			ms->path_list = ft_split(envp[ms->i], ':');
			ms->j = 0;
			while (ms->path_list[ms->j])
			{
				ms->temp = ft_strjoin(ms->path_list[ms->j], "/");
				ms->path_cmd = ft_strjoin(ms->temp, cmd);
				if (!access(ms->path_cmd, F_OK | X_OK))
				{
					ft_aux_path(ms, 0);
					return (1);
				}
				ft_aux_path(ms, 1);
				ms->j++;
			}
			ft_aux_path(ms, 2);
			return (0);
		}
	}
	return (0);
}

void	ft_aux_path(t_ms *ms, int number)
{
	free (ms->temp);
	ms->temp = NULL;
	if (number == 1)
	{
		free (ms->path_cmd);
		ms->path_cmd = NULL;
	}
	if (number == 0 || number == 2)
	{
		ms->k = 0;
		while (ms->path_list[ms->k])
		{
			free (ms->path_list[ms->k]);
			ms->path_list[ms->k] = NULL;
			ms->k++;
		}
		free(ms->path_list);
		ms->path_list = NULL;
	}
	if (number == 2)
	{
		free (ms->path_cmd);
		ms->path_cmd = NULL;
	}
}
