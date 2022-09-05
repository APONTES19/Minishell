/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 20:49:01 by ryoshio-          #+#    #+#             */
/*   Updated: 2022/09/05 21:39:48 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/minishell.h"


void	ft_error(int number, t_ms *ms)
{
	if (number == 0)
		ft_printf("Invalid arguments\n");
	if (number == 2)
		ft_printf("Erro no PID arguments\n");
	if (number == 3)
	{
		ft_printf("Erro na Execução do comando com a execve\n");
		exit(3);
	}
	if (number == 10)
	{
		ft_printf("Erro no Path Não Encontrado\n");
	}
	if (number == 11)
		ft_printf("invalid character: %c\n", ms->line[ms->i]);
	if (number == 9)
		ft_printf("-bash: syntax error near "
			"unexpected token `%c'\n", ms->line[ms->i]);
	if (number == 19)
		ft_printf("-bash: syntax error near "
			"unexpected token `%c%c'\n", ms->line[ms->i], ms->line[ms->i + 1]);
	if (number == 29)
		ft_printf("quote is missing\n");
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

// ao sair dar free nas alocações feitas para os comandos
// dar free no path_list gerado no get path
