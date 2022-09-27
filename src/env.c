/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 19:50:22 by lucasmar          #+#    #+#             */
/*   Updated: 2022/09/27 20:27:15 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_env(t_ms *ms, t_cmd *cmd, char **envp)
{
	if (cmd[ms->p].arg_cmd[1] != NULL)
		ft_error_2(18, cmd, ms);
	else
	{
		ms->i = 0;
		while(envp[ms->i])
		{
			printf("%s\n", envp[ms->i]);
			ms->i++;
			if (envp[ms->i] == NULL)
			{
				envp[ms->i] = ft_strdup("NOME=lUCAS");
				envp[ms->i + 1] = NULL;
				break;
			}
		}
	}
	return ;
}
