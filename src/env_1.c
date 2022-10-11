/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 19:50:22 by lucasmar          #+#    #+#             */
/*   Updated: 2022/10/10 21:34:28 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_env(t_ms *ms, t_cmd *cmd)
{
	if (cmd[ms->p].arg_cmd[1] != NULL)
		ft_error_2(18, cmd, ms);
	else
	{
		ms->i = 0;
		while (g_ms.envp[ms->i])
		{
			ft_printf ("%s\n", g_ms.envp[ms->i]);
			ms->i++;
		}
	}
	return ;
}

void	ft_copy_envp(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
		i++;
	g_ms.envp = (char **) malloc((i + 1) * sizeof(char **));
	i = 0;
	while (envp[i])
	{
		g_ms.envp[i] = ft_strdup(envp[i]);
		i++;
	}
	g_ms.envp[i] = NULL;
}

char	*ft_getenv(char *s)
{
	int		i;
	size_t	j;
	int		k;

	i = 0;
	while (g_ms.envp[i])
	{
		j = ft_strlen(g_ms.envp[i]) - ft_strlen(ft_strchr(g_ms.envp[i], '='));
		if (j == ft_strlen(s))
		{
			if (ft_strncmp(g_ms.envp[i], s, j) == 0)
			{
				k = 0;
				while (g_ms.envp[i][k])
				{
					if (g_ms.envp[i][k] == '=')
						return (&g_ms.envp[i][k + 1]);
					k++;
				}
			}
		}
		i ++;
	}
	return (NULL);
}
