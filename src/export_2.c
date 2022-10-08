/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 21:08:18 by lucasmar          #+#    #+#             */
/*   Updated: 2022/10/08 14:30:29 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_print_export(void)
{
	int	*sort;
	int	i;

	sort = ft_sort_envp();
	i = 0;
	while(g_ms.envp[i])
	{
		ft_printf("declare -x ");
		ft_printf("%s\n", g_ms.envp[sort[i]]);
		i ++;
	}
	free(sort);
}

int	*ft_sort_envp(void)
{
	t_sort sort;

	ft_initializing_sort(&sort);
	sort.i = 0;
	while (g_ms.envp[sort.i])
	{
		sort.k=0;
		while(sort.catch[sort.k]==0 && g_ms.envp[sort.k])
			sort.k++;
		sort.j = -1;
		while(g_ms.envp[++sort.j])
			if(ft_strncmp(g_ms.envp[sort.k], g_ms.envp[sort.j],
				ft_strlen(g_ms.envp[sort.k])) > 0 && sort.catch[sort.j] == 1)
				sort.k = sort.j;
		sort.sort[sort.i] = sort.k;
		sort.catch[sort.k] = 0;
		sort.i ++;
	}
	free(sort.catch);
	return(sort.sort);
}

void	ft_initializing_sort(t_sort *sort)
{
	sort->i = 0;
	while(g_ms.envp[sort->i])
		sort->i++;
	sort->sort = malloc(sizeof(int) * sort->i);
	sort->catch = malloc(sizeof(int) * sort->i);
	sort->i = 0;
	while(g_ms.envp[sort->i])
	{
		sort->catch[sort->i] = 1;
		sort->i ++;
	}
}
