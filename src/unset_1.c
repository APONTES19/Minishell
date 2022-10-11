/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 19:50:33 by lucasmar          #+#    #+#             */
/*   Updated: 2022/10/10 23:29:18 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_unset(t_ms *ms, t_cmd *cmd)
{
	int	i;

	i = 1;
	while (cmd[ms->p].arg_cmd[i])
	{
		ft_unset2(cmd[ms->p].arg_cmd[i]);
		i ++;
	}
}

void	ft_unset2(char *src)
{
	char	**temp;
	size_t	index;
	size_t	i;
	size_t	j;

	if (!ft_index_envp(src))
		return ;
	index = ft_index_envp(src);
	temp = ft_strstrdup(g_ms.envp);
	ft_free_two_point(g_ms.envp);
	g_ms.envp = (char **) malloc((ft_strstrlen(temp)) * sizeof(char **));
	i = 0;
	j = 0;
	while (temp[i])
	{
		if (i != index)
		{
			g_ms.envp[j] = ft_strdup(temp[i]);
			j++;
		}
		i ++;
	}
	g_ms.envp[j] = NULL;
	ft_free_two_point(temp);
}

int	ft_index_envp(char *src)
{
	int		i;
	size_t	j;

	i = 0;
	while (g_ms.envp[i])
	{
		j = ft_strlen(g_ms.envp[i]) - ft_strlen(ft_strchr(g_ms.envp[i], '='));
		if (j == ft_strlen(src))
		{
			if (ft_strncmp(g_ms.envp[i], src, j) == 0)
				return (i);
		}
		i ++;
	}
	return (-1);
}

size_t	ft_strstrlen(char **src)
{
	size_t	i;

	i = 0;
	while (src[i])
		i ++;
	return (i);
}

char	**ft_strstrdup(char **src)
{
	char	**dst;
	int		i;

	dst = (char **) malloc((ft_strstrlen(src) + 1) * sizeof(char **));
	if (dst == NULL)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dst[i] = ft_strdup(src[i]);
		i ++;
	}
	dst[i] = NULL;
	return (dst);
}
