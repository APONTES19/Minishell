/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 14:27:22 by lucasmar          #+#    #+#             */
/*   Updated: 2022/10/16 16:21:27 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_set_line_dollar(t_ms *ms)
{
	ms->i = 0;
	while(ms->line[ms->i])
	{
		if (ms->line[ms->i] == '$')
		{
			if (ft_strchr(" |", ms->line[ms->i + 1]) != NULL)
				ms->i++;
			else
			{
				//ft_change_line_dollar(ms);
				ms->i = -1;
			}
		}
		ms->i++;
	}
	return(0);
}

// int	ft_change_line_dollar()
// {
// 	//primeira coisa definir a palavra que tem depois do $ limitadores são | ' '
// 	ms->start = ms->i+1;
// 	ms->k = ms->start;
// 	while(ft_strchr(" |", ms->line[ms->i + 1]) != NULL)
// 	{
// 		ms->k++;
// 	}
// }

// echo $HOME
	// echo /home/lucas

// echo $jsnd
	// echo

// echo $
	// echo $

// echo '$HOME' "$HOME" $PWD
	//ENTRA NA FUNÇÃO POIS A PRIMIEIRA QUE VERIFICA SE TEM OU NÃO $ DEU POSITIVO
	// RESULTADO DA LINHA
		// echo '$HOME' /home/lucas $PWD
		// echo '$HOME' /home/lucas .\42
