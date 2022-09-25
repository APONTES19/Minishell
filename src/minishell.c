/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 18:03:23 by lucasmar          #+#    #+#             */
/*   Updated: 2022/09/23 23:16:21 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char **g_envp;

int main(int argc, char **argv, char **envp)
{
	t_ms	ms;
	t_cmd	cmd;


	(void )argv;
	if(argc == 1)
	{
		if (envp == NULL)
			ft_error(06, &ms);
		ft_memset(&ms, '0', sizeof(ms));
		ft_memset(&cmd, '0', sizeof(cmd));
		ft_copy_envp(envp);
		while(1)
		{
			ft_get_line(&ms);
			add_history(ms.line);
			if (ft_check_input(&ms) != 0)
			{
				// ms.pid1 = fork();
				// if (ms.pid1 == -1)
				// 	ft_error(10, &ms);
				// else if (ms.pid1 == 0)
				// {
				ft_command_split(&ms, &cmd, envp);
				// 	exit(1);
				// }
				// else
				// 	wait(&ms.pid1);
			}
			//int i;

			//i = 0;
			//while(g_envp[i++])
			//	printf("|%s|\n",g_envp[i]);
		}
	}
	else
		ft_error(0, &ms);
	return (0);
}

void ft_get_line(t_ms * ms)
{
	ms->line = readline("Minishell~$ ");
	if (ms->line[0] == ' ')
		ft_check_space(ms);
	if (ms->line == NULL || ft_strncmp(ms->line, "", 1) == 0)
		ft_get_line(ms);
	if (ft_strncmp(ms->line, "exit", 4) == 0)
	{
		rl_clear_history();
		free(ms->line);
		ms->line = NULL;

		exit(EXIT_SUCCESS);
	}
}
