/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 18:03:23 by lucasmar          #+#    #+#             */
/*   Updated: 2022/09/12 20:13:11 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

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
		while(1)
		{
			ft_get_line(&ms);
			add_history(ms.line);
			if (ft_check_input(&ms) != 0)
			{
				ft_command_split(&ms, &cmd, envp);
			}
		}
	}
	else
		ft_error(0, &ms);
	return (0);
}

void ft_get_line(t_ms * ms)
{
	ms->line = readline("Minishell~$ ");
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
