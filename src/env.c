/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 19:50:22 by lucasmar          #+#    #+#             */
/*   Updated: 2022/09/28 16:33:59 by ryoshio-         ###   ########.fr       */
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


void	ft_copy_envp(t_ms *ms, char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
		i++;
	ms->cpy_envp = (char **) malloc(i * sizeof(char **));
	i = 0;
	while (envp[i])
	{
		ms->cpy_envp[i] = ft_strdup(envp[i]);
		i++;
	}
	ms->cpy_envp[i] = NULL;
}

int	seach_variable_env(t_ms *ms, char *s)
{
	int	i;
	int	j;

	i = 0;
	while (ms->cpy_envp[i])
	{
		j = ft_strlen(ms->cpy_envp[i]) - ft_strlen(ft_strchr(ms->cpy_envp[i], '='));
		if(j == ft_strlen(s))
		{
			if (ft_strncmp(ms->cpy_envp[i], s, j)== 0)
				return (i);
		}
		i ++;
	}
	return (-1);
}
