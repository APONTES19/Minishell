/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 19:50:27 by lucasmar          #+#    #+#             */
/*   Updated: 2022/10/10 22:07:43 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_export(t_ms *ms, t_cmd *cmd)
{
	if (cmd[ms->p].arg_cmd[1] == NULL
		|| ft_strncmp(cmd[ms->p].arg_cmd[1], "#", 1) == 0)
		ft_print_export();
	else if (ft_strchr(cmd[ms->p].arg_cmd[1], '=') != 0)
	{
		if (ft_isalpha(cmd[ms->p].arg_cmd[1][0]) == 0 ||
			ft_export_special(ms, cmd) == 1)
			ft_error_2(20, cmd, ms);
		else
			ft_set_export(cmd, ms);
	}
	return ;
}

int	ft_export_special(t_ms *ms, t_cmd *cmd)
{
	ms->i = 0;
	while (cmd[ms->p].arg_cmd[1][ms->i] != '\0'
		&& cmd[ms->p].arg_cmd[1][ms->i] != '=')
	{
		if (ft_isalnum(cmd[ms->p].arg_cmd[1][ms->i]) == 0 &&
			cmd[ms->p].arg_cmd[1][ms->i] != '_')
			return (1);
		ms->i++;
	}
	return (0);
}

void	ft_set_export(t_cmd *cmd, t_ms *ms)
{
	char	*s;

	s = ft_substr(cmd[ms->p].arg_cmd[1], 0,
			ft_strlen(cmd[ms->p].arg_cmd[1])
			- ft_strlen(ft_strchr(cmd[ms->p].arg_cmd[1], '=')));
	if (ft_getenv(s) == NULL)
	{
		ft_add_envp(cmd[ms->p].arg_cmd[1]);
	}
	else
	{
		ft_change_envp(s, cmd[ms->p].arg_cmd[1]);
	}
}
