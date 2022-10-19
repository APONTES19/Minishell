/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 19:21:39 by lucasmar          #+#    #+#             */
/*   Updated: 2022/10/19 00:08:46 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_command_split(t_ms *ms, t_cmd *cmd)
{
	if (ms->n_pipe > 1)
	{
		cmd = (t_cmd *) malloc (ms->n_pipe * sizeof (t_cmd));
		cmd->base_list_cmd = ft_split_ms(ms->line, '|');
		ms->i = 0;
		while (ms->i != ms->n_pipe)
		{
			cmd[ms->i].arg_cmd = ft_split_ms(cmd->base_list_cmd[ms->i], ' ');
			ms->i++;
		}
		ft_free_two_point(cmd->base_list_cmd);
	}
	else
	{
		ms->i = 0;
		cmd = (t_cmd *) malloc (ms->n_pipe * sizeof (t_cmd));
		cmd[ms->i].arg_cmd = ft_split_ms(ms->line, ' ');
	}
	ft_free_point(ms->line);
	if (cmd[0].arg_cmd[0] == NULL)
	{
		ft_error(8, ms, NULL, NULL);
		return (1);
	}
	if (ms->quote == 1)
		ft_clean_quote(ms,cmd);
	ft_main_while(ms, cmd);
	return (0);
}

void	ft_clean_quote(t_ms *ms, t_cmd *cmd)
{
	char *temp;
	char type;
	printf("\n_________Aqui começa o split do pipe __________\n");
	type = '\"';
	ms->i = 0;
	while(ms->i != ms->n_pipe)
	{
		printf("Struc cmd[%d]\n",ms->i);
		ms->j = 0;
		while(cmd[ms->i].arg_cmd[ms->j])
		{
		    printf("\tArg[%d]%s\n",ms->j,cmd[ms->i].arg_cmd[ms->j]);
			temp = ft_strdup(cmd[ms->i].arg_cmd[ms->j]);
			ft_free_point(cmd[ms->i].arg_cmd[ms->j]);
			ms->k = 0;
			ms->p = 0;
			while(temp[ms->k])
			{
				if (temp[ms->k] == '\'' || temp[ms->k] == '\"')
				{
					if (temp[ms->k] == '\'')
						type = '\'';
					ms->k++;
					ms->p+= 2;
					while(temp[ms->k] != type)
						ms->k++;
				}
				ms->k++;
			}
			cmd[ms->i].arg_cmd[ms->j] =
				(char *) malloc ((8) *sizeof(char *));
			ms->k = 0;
			ms->p = 0;
			while(temp[ms->k])
			{
				if (temp[ms->k] == '\'' || temp[ms->k] == '\"')
				{
					if (temp[ms->k] == '\'')
						type = '\'';
					ms->k++;
					while(temp[ms->k] != type)
					{
						cmd[ms->i].arg_cmd[ms->j][ms->p] = temp[ms->k];
						ms->p++;
						ms->k++;
					}
					ms->k++;
				}
				if (temp[ms->k])
				{
					cmd[ms->i].arg_cmd[ms->j][ms->p] = temp[ms->k];
					ms->p++;
					ms->k++;
				}
			}
			printf("%d", ms->p);
			cmd[ms->i].arg_cmd[ms->j][ms->p] = '\0';
			ft_free_point(temp);
			printf("\talterado-Arg[%d]%s\n",ms->j,cmd[ms->i].arg_cmd[ms->j]);
		    ms->j++;
		}
		ms->i++;
	}
	printf("_________Aqui termina o split do pipe __________\n\n");
}


int	ft_get_path(t_ms *ms, char *cmd)
{
	char	*path;

	path = NULL;
	path = ft_getenv("PATH");
	if (path == NULL)
		return (1);
	else
	{
		ms->path_list = ft_split(path, ':');
		ms->j = 0;
		while (ms->path_list[ms->j])
		{
			ms->temp = ft_strjoin(ms->path_list[ms->j], "/");
			ms->path_cmd = ft_strjoin(ms->temp, cmd);
			if (!access(ms->path_cmd, F_OK | X_OK))
			{
				ft_aux_path(ms, 0);
				return (0);
			}
			ft_aux_path(ms, 1);
			ms->j++;
		}
		ft_aux_path(ms, 2);
		return (1);
	}
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
