/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 18:03:23 by lucasmar          #+#    #+#             */
/*   Updated: 2022/08/19 21:08:44 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int main(int argc, char **argv, char **envp)
{
	t_ms  ms;
	
	ft_memset(&ms, '0', sizeof(ms));

	(void )argv;
	(void )envp;

	if(argc == 1)
	{
		while(1)
		{
			ft_cmd(&ms);
			ft_printf("%s\n ", ms.cmd);
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
		free(ms->cmd);
		//free(ms);
		exit(EXIT_SUCCESS);
		
	}

}

