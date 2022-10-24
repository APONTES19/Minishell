/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 00:54:30 by lucasmar          #+#    #+#             */
/*   Updated: 2022/10/24 11:18:20 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_error_4(int number, t_ms *ms, t_cmd *cm, char *cmd)
{
	if (number == 25)
	{
		g_ms.exit_s = 1;
		printf(" cd: %s: No such file or directory\n", ms->temp);
	}
	if (number == 26)
	{
		g_ms.exit_s = 2;
		ft_free_point(g_ms.path_infile);
		ft_free_point(g_ms.path_outfile);
		ft_free_point(g_ms.line);
		printf("syntax error near unexpected token `newline'\n");
	}
	if (number == 27)
	{
		g_ms.exit_s = 2;
		printf("exit: %s: numeric argument required\n", cmd);
	}
	if (number == 28)
	{
		g_ms.exit_s = 1;
		printf("exit: too many arguments\n");
	}
	if (number == 29)
		printf("Error init minishell\n");
	ft_error_5(number, ms, cm, cmd);
}

void	ft_error_5(int number, t_ms *ms, t_cmd *cm, char *cmd)
{
	(void)cm;
	(void)ms;
	(void)cmd;
	if (number == 30)
	{
		g_ms.exit_s = 2;
		printf("syntax error near unexpected token\n");
	}
	if (number == 31)
	{
		g_ms.exit_s = 127;
		printf("%s: command not found\n", cmd);
	}
}
