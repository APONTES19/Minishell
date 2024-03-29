/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 19:50:27 by lucasmar          #+#    #+#             */
/*   Updated: 2022/10/20 19:05:18 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_export(t_ms *ms, t_cmd *cmd)
{
	if (cmd[g_ms.p].arg_cmd[1] == NULL
		|| ft_strncmp_m(cmd[g_ms.p].arg_cmd[1], "#") == 0)
		ft_print_export();
	else if (ft_strchr(cmd[g_ms.p].arg_cmd[1], '=') != 0)
	{
		if (ft_isalpha(cmd[g_ms.p].arg_cmd[1][0]) == 0 ||
			ft_export_special(ms, cmd) == 1)
			ft_error(20, ms, cmd, cmd[g_ms.p].arg_cmd[1]);
		else
			ft_set_export(cmd);
	}
	g_ms.exit_s = 0;
	return ;
}

int	ft_export_special(t_ms *ms, t_cmd *cmd)
{
	ms->i = 0;
	while (cmd[g_ms.p].arg_cmd[1][ms->i] != '\0'
		&& cmd[g_ms.p].arg_cmd[1][ms->i] != '=')
	{
		if (ft_isalnum(cmd[g_ms.p].arg_cmd[1][ms->i]) == 0 &&
			cmd[g_ms.p].arg_cmd[1][ms->i] != '_')
			return (1);
		ms->i++;
	}
	return (0);
}

void	ft_set_export(t_cmd *cmd)
{
	char	*s;

	s = ft_substr(cmd[g_ms.p].arg_cmd[1], 0,
			ft_strlen(cmd[g_ms.p].arg_cmd[1])
			- ft_strlen(ft_strchr(cmd[g_ms.p].arg_cmd[1], '=')));
	if (ft_getenv(s) == NULL)
	{
		ft_add_envp(cmd[g_ms.p].arg_cmd[1]);
	}
	else
	{
		ft_change_envp(s, cmd[g_ms.p].arg_cmd[1]);
	}
	ft_free_point(s);
}
