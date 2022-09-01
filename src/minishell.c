/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 18:03:23 by lucasmar          #+#    #+#             */
/*   Updated: 2022/09/02 00:00:04 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int main(int argc, char **argv, char **envp)
{
	t_ms	ms;
	t_cmd	cmd;

	(void )argv;
	(void )envp;

	ft_memset(&ms, '0', sizeof(ms));
	if(argc == 1)
	{
		while(1)
		{
			ft_cmd(&ms);
			add_history(ms.line);
			ft_special(&ms);
			ft_check_pipe(&ms);
			ft_comand_split(&ms, &cmd);
			//ft_check_$(&ms);
			ft_printf("%s\n", ms.line);
			free(ms.line);
		}
	}
	else
		ft_error(0);
	return (0);
}

void ft_cmd(t_ms * ms)
{
	ms->line = readline("Minishell~$ ");

	if (ft_strncmp(ms->line, "exit", 4) == 0)
	{
		rl_clear_history();
		free(ms->line);
		exit(EXIT_SUCCESS);
	}
}
