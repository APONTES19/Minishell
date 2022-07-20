/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 18:03:23 by lucasmar          #+#    #+#             */
/*   Updated: 2022/07/20 16:45:28 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int main(int argc, char **argv)
{
	char	*cmd;

	ft_printf("%s",argv[0]);

	if(argc == 1)
	{
		while(1)
		{
			ft_printf("Minishell~~$");
			cmd = ft_cmd();
			ft_printf("%s\n", cmd);
		}
	}
	else
		ft_error(0);
	return (0);
}

char	*ft_cmd(void)
{
	char	*cmd;

	cmd = readline();

	if (ft_strncmp(cmd, "exit", 4) == 0)
				exit(EXIT_SUCCESS);
	return(cmd);
}

char	ft_error(int number)
{
	if (number == 0)
		ft_printf("Invalid arguments\n");
}
