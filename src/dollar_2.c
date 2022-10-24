/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 19:42:26 by lucasmar          #+#    #+#             */
/*   Updated: 2022/10/24 10:17:56 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_change_line_dollar(t_ms *ms, char **dollar)
{
	char	*temp;
	char	*temp1;
	char	*temp2;

	temp = ft_substr(g_ms.line, 0, (ms->i));
	if (g_ms.line[ms->k] != '\0')
	{
		temp1 = ft_substr(g_ms.line, ms->k, ft_strlen(&g_ms.line[ms->k]));
		ft_free_point(g_ms.line);
		temp2 = ft_strjoin(temp, *dollar);
		g_ms.line = ft_strjoin(temp2, temp1);
		ft_free_point(temp1);
		ft_free_point(temp2);
	}
	else
	{
		ft_free_point(g_ms.line);
		g_ms.line = ft_strjoin(temp, *dollar);
	}
	ft_free_point(temp);
}
