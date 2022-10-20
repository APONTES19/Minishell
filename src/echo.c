/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 22:30:07 by lucasmar          #+#    #+#             */
/*   Updated: 2022/10/20 19:01:34 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

//echo
//echo -n
// echo lucas
// echo lucas bruna atena
// echo -n lucas bruna atena
// echo +n
// echo -m
// echo asdcasdvsdfvffffffffffffffffffffffffffffffffffffffffdsdddddddddddd
// echo 'lucas'
// echo ''atena''
// echo "'atena'"
// echo '"atena"'
// echo $HOME
// echo '$HOME' "$HOME" "'$HOME'" '"$HOME"'

void	ft_echo(t_ms *ms, t_cmd *cmd)
{
	ms->k = 1;
	if (cmd[g_ms.p].arg_cmd[1] == NULL)
		ft_printf("\n");
	else
		ft_echo_while (ms, cmd);
	g_ms.exit_s = 0;
	return ;
}

void	ft_echo_while(t_ms *ms, t_cmd *cmd)
{
	int	flag;

	flag = 0;
	while (cmd[g_ms.p].arg_cmd[ms->k])
	{
		if (ms->k == 1 && !ft_strncmp_m(cmd[g_ms.p].arg_cmd[ms->k], "-n"))
		{
			ms->k++;
			if (cmd[g_ms.p].arg_cmd[ms->k] == NULL)
				return ;
			flag++;
		}
		if (cmd[g_ms.p].arg_cmd[ms->k + 1])
			ft_printf("%s ", cmd[g_ms.p].arg_cmd[ms->k]);
		else
			ft_printf("%s", cmd[g_ms.p].arg_cmd[ms->k]);
		ms->k++;
	}
	if (flag == 0)
		ft_printf("\n");
}
