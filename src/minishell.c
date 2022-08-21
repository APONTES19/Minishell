/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 18:03:23 by lucasmar          #+#    #+#             */
/*   Updated: 2022/08/21 22:21:28 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int main(int argc, char **argv, char **envp)
{
	t_ms  ms;
	(void )argv;
	(void )envp;

	ft_memset(&ms, '0', sizeof(ms));
	if(argc == 1)
	{
		while(1)
		{
			ft_cmd(&ms);
			add_history(ms.cmd);
			ft_special(&ms);
			ft_printf("%s\n", ms.cmd);
			free(ms.cmd);
		}
	}
	else
		ft_error(0);
	return (0);
}

void ft_cmd(t_ms * ms)
{
	ms->cmd = readline("Minishell~$");

	if (ft_strncmp(ms->cmd, "exit", 4) == 0)
	{
		rl_clear_history();
		free(ms->cmd);
		exit(EXIT_SUCCESS);
	}
}
