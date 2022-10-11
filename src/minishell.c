/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 18:03:23 by lucasmar          #+#    #+#             */
/*   Updated: 2022/10/11 01:32:36 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_ms	g_ms;
int	main(int argc, char **argv, char **envp)
{
	t_ms	ms;
	t_cmd	cmd;

	(void )argv;
	if(argc == 1)
	{
		if (envp == NULL)
			ft_error(06, &ms);
		ft_copy_envp(envp);
		ft_memset(&ms, '0', sizeof(ms));
		ft_memset(&cmd, '0', sizeof(cmd));
		g_ms.cd = 0;
		g_ms.stdin = dup(STDIN);
		g_ms.stdout = dup(STDOUT);
		while(1)
		{
			ft_get_line(&ms);
			add_history(ms.line);
			if (ft_check_input(&ms) != 0)
				ft_command_split(&ms, &cmd, envp);
			dup2(g_ms.stdin, STDIN);
			dup2(g_ms.stdout, STDOUT);
		}
	}
	else
		ft_error(0, &ms);
	return (g_ms.exit_s);
}

