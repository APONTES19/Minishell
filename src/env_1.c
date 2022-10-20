/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 19:50:22 by lucasmar          #+#    #+#             */
/*   Updated: 2022/10/20 19:16:03 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_env(t_ms *ms, t_cmd *cmd)
{
	if (cmd[g_ms.p].arg_cmd[1] != NULL)
		ft_error(18, ms, cmd, cmd[g_ms.p].arg_cmd[1]);
	else
	{
		ms->i = 0;
		while (g_ms.envp[ms->i])
		{
			ft_printf ("%s\n", g_ms.envp[ms->i]);
			ms->i++;
		}
	}
	g_ms.exit_s = 0;
	return ;
}

void	ft_copy_envp(char **envp)
{
	int	i;
	int c;

	i = 0;
	c = 0;
	while (envp[i])
		i++;
	g_ms.envp = (char **) malloc((i + 1) * sizeof(char **));
	i = 0;
	c = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "OLDPWD=", 7) == 0)
			i++;
		else
		{
			g_ms.envp[c] = ft_strdup(envp[i]);
			c++;
			i++;
		}
	}
	g_ms.envp[c] = NULL;
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
