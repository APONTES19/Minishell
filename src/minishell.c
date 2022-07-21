/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 18:03:23 by lucasmar          #+#    #+#             */
/*   Updated: 2022/07/21 19:50:05 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int main(int argc, char **argv)
{
	char	*cmd;

	(void )argv;

	if(argc == 1)
	{
		while(1)
		{
			//ft_printf(" Minishell~~$");
			cmd = ft_cmd();
			ft_printf(" :cmd%s\n ", cmd);
		}
	}
	else
		ft_error(0);
	return (0);
}

char	*ft_cmd(void)
{
	char	*cmd;

	cmd = readline("Minishell~~$");

	if (ft_strncmp(cmd, "exit", 4) == 0)
	{
		exit(EXIT_SUCCESS);
		free(cmd);
	}
				
	return(cmd);
}

void	ft_error(int number)
{
	if (number == 0)
		ft_printf("Invalid arguments\n");
}
