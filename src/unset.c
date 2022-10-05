/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 19:50:33 by lucasmar          #+#    #+#             */
/*   Updated: 2022/10/05 17:07:11 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_unset(t_ms *ms, t_cmd *cmd)
{
    int i;

    i = 1;
    while (cmd[ms->p].arg_cmd[i])
    {
        ft_unset2(cmd[ms->p].arg_cmd[i]);
        i ++;
    }

}

void    ft_unset2(char *src)
{
    char    **temp;
    size_t   index;
    size_t    i;
    size_t     j;

    if(!ft_index_envp(src))
        return ;
    index = ft_index_envp(src);
    temp = ft_strstrdup(g_ms.envp);
    ft_strstrfree(g_ms.envp);
    g_ms.envp = (char **) malloc((ft_strstrlen(temp)) * sizeof(char **));
    i = 0;
    j = 0;
    while(temp[i])
    {
        if(i != index)
        {
            g_ms.envp[j] =  ft_strdup(temp[i]);
            j++;
        }
        i ++;
    }
    g_ms.envp[j] = NULL;
    ft_strstrfree(temp);
}


int	ft_index_envp(char *src)
{
    int i;
    size_t j;

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
    return(-1);
}

