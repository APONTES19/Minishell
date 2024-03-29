/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:34:27 by lucasmar          #+#    #+#             */
/*   Updated: 2022/10/20 23:45:19 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_change_envp(char *variable, char *value)
{
	int		i;
	size_t	j;

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
	free(g_ms.envp[i]);
	g_ms.envp[i] = NULL;
	g_ms.envp[i] = ft_strdup(value);
}

void	ft_add_envp(char *variable)
{
	char	**temp_envp;

	temp_envp = ft_copy_temp_envp(g_ms.envp, variable);
	ft_free_two_point(g_ms.envp);
	g_ms.envp = ft_copy_temp_envp(temp_envp, NULL);
	ft_free_two_point(temp_envp);
}

char	**ft_copy_temp_envp(char **base, char *variable)
{
	int		i;
	char	**copy;

	i = 0;
	while (base[i])
		i++;
	if (variable == NULL)
		copy = (char **) malloc((i + 1) * sizeof(char **));
	else
		copy = (char **) malloc((i + 2) * sizeof(char **));
	i = 0;
	while (base[i])
	{
		copy[i] = ft_strdup(base[i]);
		i++;
	}
	if (variable != NULL)
	{
		copy[i] = ft_strdup(variable);
		copy[i + 1] = NULL;
	}
	else
		copy[i] = NULL;
	return (copy);
}
