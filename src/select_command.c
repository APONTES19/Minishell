/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 04:29:41 by lucasmar          #+#    #+#             */
/*   Updated: 2022/09/13 22:10:36 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_select(t_ms *ms, t_cmd *cmd, char **envp)
{
	if(ms->n_pipe > 1)
		ft_creat_pipe(ms);
	ms->p = 0;
	while(ms->n_pipe > ms->p)
	{
		printf("while ! \n");
		if (ms->quote == 1)
			ft_clean_quote(cmd);
		ft_arg(ms, cmd, envp);
		ms->p++;
	}
}

void	ft_arg(t_ms *ms, t_cmd *cmd, char **envp)
{
	printf("ARG:|%s|\n",cmd[ms->p].arg_cmd[0]);
	if (ft_strncmp(cmd[ms->p].arg_cmd[0], "env", 3) == 0)
		ft_printf("ENV\n");
	else if (!ft_strncmp(cmd[ms->p].arg_cmd[0], "export", 6))
		ft_printf("EXPORT\n");
	else if (!ft_strncmp(cmd[ms->p].arg_cmd[0], "cd", 2))
		ft_printf("CD\n");
	else if (!ft_strncmp(cmd[ms->p].arg_cmd[0], "pwd", 3))
		ft_printf("PWD\n");
	else if (!ft_strncmp(cmd[ms->p].arg_cmd[0], "unset", 5))
		ft_printf("UNSET\n");
	else if (!ft_strncmp(cmd[ms->p].arg_cmd[0], "echo", 4))
		ft_echo(ms, cmd);
	else
	{
		ft_execve_cmd(ms, cmd, envp);
	}
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

void	ft_creat_pipe(t_ms *ms)
{
	int	i;

	i = 0;
	while(i < ms->n_pipe - 1)
	{
		ms->pipe = pipe(ms->fd + (2 * i));
		if (ms->pipe == -1)
			ft_error(9, ms);
		i++;
	}
}
