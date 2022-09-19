/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 19:21:39 by lucasmar          #+#    #+#             */
/*   Updated: 2022/09/19 19:23:11 by lucasmar         ###   ########.fr       */
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
	ft_select(ms, cmd, envp);
	return(1);
}

void	ft_change_fd(int input, int output, t_ms *ms)
{
	if (dup2(input, 0) == -1)
		ft_error(10, ms);
	if (dup2(output, 1) == -1)
		ft_error(10, ms);
}

void	ft_close_fds(t_ms *ms)
{
		int	i;
		i = (((ms->n_pipe - 1) * 2) - 1 );
		while (i != -1)
		{
			close(ms->fd[i]);
			i--;
		}
}
