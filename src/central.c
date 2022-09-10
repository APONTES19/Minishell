/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   central.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 04:29:41 by lucasmar          #+#    #+#             */
/*   Updated: 2022/09/10 05:17:54 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_central(t_ms *ms, t_cmd *cmd)
{
	if (ms->n_pipe == 1)
		ft_arg(ms, cmd);
}

void	ft_arg(t_ms *ms, t_cmd *cmd)
{
	if (ft_strncmp(cmd[0].arg_cmd[0], "env", 3) == 0)
		ft_printf("ENV\n");
	else if (!ft_strncmp(cmd[0].arg_cmd[0], "export", 6))
		ft_printf("EXPORT\n");
	else if (!ft_strncmp(cmd[0].arg_cmd[0], "cd", 2))
		ft_printf("CD\n");
	else if (!ft_strncmp(cmd[0].arg_cmd[0], "pwd", 3))
		ft_printf("PWD\n");
	else if (!ft_strncmp(cmd[0].arg_cmd[0], "unset", 5))
		ft_printf("UNSET\n");
	else if (!ft_strncmp(cmd[0].arg_cmd[0], "echo", 4))
		ft_printf("ECHO\n");
	else
		ft_printf("EXECVE%d\n",ms->i);
}

