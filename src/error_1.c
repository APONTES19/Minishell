/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 20:49:01 by ryoshio-          #+#    #+#             */
/*   Updated: 2022/10/24 10:53:39 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_error(int number, t_ms *ms, t_cmd *cm, char *cmd)
{
	dup2 (2, STDOUT);
	g_ms.exit_s = 127;
	printf("%d ", number);
	printf("-minishell: ");
	if (number == 0)
		printf("Invalid arguments\n");
	if (number == 1)
		printf("quote is missing\n");
	if (number == 2)
		printf("invalid character: %c\n", g_ms.line[ms->i]);
	if (number == 3)
		printf("syntax error near "
			"unexpected token `|'\n");
	if (number == 4)
		printf("syntax error near "
			"unexpected token `||'\n");
	if (number == 5)
		printf("malloc error\n");
	if (number == 6)
		printf("envp error\n");
	if (number == 8)
		printf("split line error\n");
	if (number == 9)
		printf("pipe error\n");
	ft_error_1(number, ms, cm, cmd);
}

void	ft_error_1(int number, t_ms *ms, t_cmd *cm, char *cmd)
{
	if (number == 10)
		printf("Erro no PID arguments\n");
	if (number == 11)
	{
		printf("Erro na Execução do comando com a execve\n");
		ft_free_exit(ms, cm);
		exit(g_ms.exit_s);
	}
	if (number == 12)
		printf("%s: No such file or directory\n", g_ms.path_infile);
	if (number == 13)
		printf("%s:  Permission denied\n", g_ms.path_outfile);
	if (number == 14)
	{
		g_ms.exit_s = 1;
		printf("cd: too many arguments\n");
	}
	if (number == 15)
	{
		g_ms.exit_s = 1;
		printf("cd: OLDPWD not set\n");
	}
	ft_error_2(number, ms, cm, cmd);
}

void	ft_error_2(int number, t_ms *ms, t_cmd *cm, char *cmd)
{
	if (number == 16)
		printf("Value Envp = NUll\n");
	if (number == 17)
	{
		printf ("Error while executing\n");
		ft_free_exit(ms, cm);
		exit(g_ms.exit_s);
	}
	if (number == 18)
	{
		printf("%s: command not found\n", cmd);
		ft_free_cmd(ms, cm);
		ft_free_exit(ms, cm);
		exit(g_ms.exit_s);
	}
	if (number == 19)
	{
		printf ("env: '%s': we don't configure for arguments\n", cmd);
	}
	if (number == 20)
		printf("export: '%s': não é um identificador válido\n", cmd);
	ft_error_3(number, ms, cm, cmd);
}

void	ft_error_3(int number, t_ms *ms, t_cmd *cm, char *cmd)
{
	(void)ms;
	(void)cm;
	if (number == 21)
	{
		g_ms.exit_s = 1;
		printf("cd: %s", cmd);
		if (access(cmd, F_OK) != 0)
			printf(": Not a directory\n");
		else
			printf(": No such file or directory\n");
	}
	if (number == 22)
	{
		printf("%s: command not found\n", cmd);
		ft_free_cmd(ms, cm);
		ft_free_exit(ms, cm);
		exit(g_ms.exit_s);
	}
	if (number == 23)
	{
		g_ms.exit_s = 1;
		printf("cd: HOME not set\n");
	}
	if (number == 24)
		printf("Error '|' void\n");
	ft_error_4(number, ms, cm, cmd);
}
