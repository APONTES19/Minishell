/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 20:49:01 by ryoshio-          #+#    #+#             */
/*   Updated: 2022/09/09 23:57:16 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/minishell.h"


void	ft_error(int number, t_ms *ms)
{
	if (number == 00)
		ft_printf("Invalid arguments\n");
	if (number == 01)
		ft_printf("quote is missing\n");
	if (number == 02)
		ft_printf("invalid character: %c\n", ms->line[ms->i]);
	if (number == 03)
		ft_printf("syntax error near "
			"unexpected token `%c'\n", ms->line[ms->i]);
	if (number == 04)
		ft_printf("syntax error near "
			"unexpected token `%c%c'\n", ms->line[ms->i], ms->line[ms->i + 1]);
	if (number == 05)
		ft_printf("malloc error\n");
	if (number == 06)
		ft_printf("envp error\n");
	if (number == 12)
		ft_printf("Erro no PID arguments\n");
	if (number == 13)
	{
		ft_printf("Erro na Execução do comando com a execve\n");
		exit(3);
	}

}

void	ft_error_2(int number, t_cmd *cmd)
{
	if (number == 07)
		ft_printf("%s: command not found\n", cmd[0].arg_cmd[0]);
}

void	ft_base_free(t_ms *ms, t_cmd *cmd)
{
	ms->i = 0;
	while(ms->i != ms->n_pipe)
	{
		free(cmd->base_list_cmd[ms->i]);
		ms->i++;
	}
	cmd->base_list_cmd = NULL;

}

// if (ms->n_pipe > 1)
// {
// 	cmd->base_list_cmd
// 	cmd[ms->i].arg_cmd
// }
// else
// {
// 	cmd[0].arg_cmd;
// }

// ao sair dar free nas alocações feitas para os comandos
// dar free no path_list gerado no get path
