/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_evolution.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 21:52:35 by ryoshio-          #+#    #+#             */
/*   Updated: 2022/10/04 23:06:20 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"


size_t  ft_strstrlen(char **src)
{
    size_t i;

    i  = 0;
    while(src[i])
        i ++;
    return(i);
}
 

char	**ft_strstrdup(char **src)
{
	char	**dst;
    int     i;

	dst =  (char **) malloc((ft_strstrlen(src) + 1)*sizeof(char **) );
	if (dst == NULL)
		return (NULL);
    
    i = 0;
    while(src[i])
    {
        dst[i] = ft_strdup(src[i]);
        i ++;
    }
	dst[i] = NULL;
	return (dst);
}

void ft_strstrfree(char **src)
{
    size_t  i;

    i = 0;
    while(src[i])
    {
        free(src[i]);
        i ++;
    }
}