/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 19:50:22 by lucasmar          #+#    #+#             */
/*   Updated: 2022/09/30 19:07:55 by ryoshio-         ###   ########.fr       */
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
	g_ms.envp = (char **) malloc(i * sizeof(char **));
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
	int	i;
	size_t	j;
	int	k;

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

void	ft_change_envp(char *variable, char *value)
{
	int	i;
	size_t	j;
	char	*tmp;
	char	*temp_2;

	i = 0;
	while (g_ms.envp[i++])
	{
		j = ft_strlen(g_ms.envp[i]) - ft_strlen(ft_strchr(g_ms.envp[i], '='));
		if (j == ft_strlen(variable))
		{
			if (ft_strncmp(g_ms.envp[i], variable, j) == 0)
				break ;
		}
	}
	tmp = ft_strjoin(variable, "=");
	temp_2 = ft_strjoin(tmp, value);
	g_ms.envp[i] = ft_strjoin(temp_2, value);
	free(tmp);
	free(temp_2);
}

void	ft_add_envp (char *variable)
{
	char	**temp_envp;
	int	i;
	int	j;

	i = 0;
	while(g_ms.envp[i])
		i++;
	temp_envp = (char **) malloc((i + 2) * sizeof(char **));
	i = 0;
	while (g_ms.envp[i])
	{
		temp_envp[i] = ft_strdup(g_ms.envp[i]);
		i++;
	}
	temp_envp[i] = ft_strdup(variable);
	temp_envp[i+1] = NULL;
	j = i+1;
	i = 0;
	printf("passei\n");
	//while(g_ms.envp[i] != NULL)
	//{
		free(g_ms.envp);
		g_ms.envp = NULL;
	//	i++;
	//}
	g_ms.envp = (char **) malloc(j * sizeof(char **));
	i = 0;
	while (g_ms.envp[i])
	{
		g_ms.envp[i] = ft_strdup(temp_envp[i]);
		i++;
	}
	while(temp_envp[i])
	{
		free(temp_envp[i]);
		temp_envp[i] = NULL;
		i++;
	}
}
