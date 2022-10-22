/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 00:54:30 by lucasmar          #+#    #+#             */
/*   Updated: 2022/10/22 15:28:05 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_error_4(int number, t_ms *ms, t_cmd *cm, char *cmd)
{
	if (number == 25)
	{
		g_ms.exit_s = 1;
		ft_printf(" cd: %s: No such file or directory\n", ms->temp);
	}
	if (number == 26)
	{
		g_ms.exit_s = 2;
		ft_printf("syntax error near unexpected token `newline'\n");
	}
	if (number == 27)
	{
		g_ms.exit_s = 2;
		ft_printf("exit: %s: numeric argument required\n", cmd);
	}
	if (number == 28)
	{
		g_ms.exit_s = 1;
		ft_printf("exit: too many arguments\n");
	}
	if (number == 29)
		ft_printf("Error init minishell\n");
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
		ft_printf("syntax error near unexpected token\n");
	}
}
