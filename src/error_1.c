/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 20:49:01 by ryoshio-          #+#    #+#             */
/*   Updated: 2022/10/16 11:19:52 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_error(int number, t_ms *ms, t_cmd *cmd)
{
	dup2 (2, STDOUT);
	g_ms.exit_s = 127;
	ft_printf("%d ", number);//excluir
	ft_printf("-minishell: ");

	if (number == 0)
		ft_printf("Invalid arguments\n");
	if (number == 1)
		ft_printf("quote is missing\n");
	if (number == 2)
		ft_printf("invalid character: %c\n", ms->line[ms->i]);
	if (number == 3)
		ft_printf("syntax error near "
			"unexpected token `%c'\n", ms->line[ms->i]);
	if (number == 4)
		ft_printf("syntax error near "
			"unexpected token `%c%c'\n", ms->line[ms->i], ms->line[ms->i + 1]);
	if (number == 5)
		ft_printf("malloc error\n");
	if (number == 6)
		ft_printf("envp error\n");
	if (number == 8)
		ft_printf("split line error\n");
	if (number == 9)
		ft_printf("pipe error\n");
	ft_error_1(number, ms, cmd);
}

void	ft_error_1(int number, t_ms *ms, t_cmd *cmd)
{
	if (number == 10)
		ft_printf("Erro no PID arguments\n");
	if (number == 11)
	{
		ft_printf("Erro na Execução do comando com a execve\n");
		exit(3);
	}
	if (number == 12)
		ft_printf("%s: No such file or directory\n", ms->path_infile);
	if (number == 13)
		ft_printf("%s:  Permission denied\n", ms->path_outfile);
	if (number == 14)
	{
		g_ms.exit_s = 1;
		ft_printf("cd: too many arguments\n");
	}
	if (number == 15)
	{
		g_ms.exit_s = 1;
		ft_printf("cd: OLDPWD not set\n");
	}
	if (number == 16)
		ft_printf("Value Envp = NUll\n");
	if (number == 17)
	{
		ft_printf ("Error while executing\n");
		exit(1);
	}
	//
	ft_error_2(number, ms , cmd);
}

void	ft_error_2(int number, t_ms *ms, t_cmd *cmd)
{
	if (number == 18)
	{
		ft_printf("%s: command not found\n", cmd[ms->p].arg_cmd[0]);
		exit(1);
	}
	if (number == 19)
	{
		ft_printf ("env: '%s': we don't configure for arguments\n",
			cmd[ms->p].arg_cmd[1]);
	}
	if (number == 20)
		ft_printf("export: '%s': não é um identificador válido\n",
			cmd[ms->p].arg_cmd[1]);
	if (number == 21)
	{
		g_ms.exit_s = 1;
		ft_printf("cd: %s", cmd[ms->p].arg_cmd[1]);
		if (access(cmd[ms->p].arg_cmd[1], F_OK) == 0)
			ft_printf(": Not a directory\n");
		else
			ft_printf(": No such file or directory\n");
	}
	if (number == 22)
	{
		ft_printf("%s: command not found\n", cmd[ms->p].arg_cmd[0]);
		exit(1);
	}
}
