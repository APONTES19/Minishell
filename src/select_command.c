/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 04:29:41 by lucasmar          #+#    #+#             */
/*   Updated: 2022/10/05 16:42:22 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_select(t_ms *ms, t_cmd *cmd, char **envp)
{
	if(ms->n_pipe > 1)
		ft_creat_pipe(ms);
	ms->p = 0;
	while(ms->p < ms->n_pipe)
	{
		ft_select_fd(ms);
		if (ms->quote == 1)
			ft_clean_quote(cmd);
		if (ft_select_arg_2(ms, cmd) == 1)
			ft_command(ms, cmd, envp);
		ms->p++;
	}
	waitpid(ms->pid, &ms->exit_s, 0);
}

void	ft_clean_quote(t_cmd *cmd)
{
	int	i;
	int	j;
	char	*c;

	c = malloc(ft_strlen(cmd[0].arg_cmd[0])+1);
	i = 0;
	j = 0;
	while (cmd[0].arg_cmd[0][i])
	{
		if(cmd[0].arg_cmd[0][i] == '\'' || cmd[0].arg_cmd[0][i] == '\"')
			i++;
		c[j] = cmd[0].arg_cmd[0][i];
		j++;
		i++;
	}
	c[j] = '\0';
	cmd[0].arg_cmd[0] = ft_strdup(c);
	free(c);
	c = NULL;
}

int	ft_select_arg_2(t_ms *ms, t_cmd *cmd)
{
	if (!ft_strncmp(cmd[ms->p].arg_cmd[0], "cd", 2))
	{
		ft_cd(ms, cmd);
		return (0);
	}
	else if (ft_strncmp(cmd[ms->p].arg_cmd[0], "env", 3) == 0)
	{
		ft_env(ms, cmd);
		return (0);
	}
	else if (!ft_strncmp(cmd[ms->p].arg_cmd[0], "export", 6))
	{
		ft_export(ms, cmd);
		return (0);
	}
	else if (!ft_strncmp(cmd[ms->p].arg_cmd[0], "unset", 5))
	{
		ft_unset(ms, cmd);
		return (0);
	}
	else if (!ft_strncmp(cmd[ms->p].arg_cmd[0], "pwd", 3))
	{
		ft_pwd();
		return (0);
	}
	else if (!ft_strncmp(cmd[ms->p].arg_cmd[0], "echo", 4))
	{
		ft_echo(ms, cmd);
		return (0);
	}
	return (1);
}
