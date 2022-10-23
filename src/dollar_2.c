/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 19:42:26 by lucasmar          #+#    #+#             */
/*   Updated: 2022/10/23 20:14:37 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_change_line_dollar(t_ms *ms, char **dollar)
{
	char	*temp;
	char	*temp1;
	char	*temp2;

	temp = ft_substr(ms->line, 0, (ms->i));
	if (ms->line[ms->k] != '\0')
	{
		temp1 = ft_substr(ms->line, ms->k, ft_strlen(&ms->line[ms->k]));
		ft_free_point(ms->line);
		temp2 = ft_strjoin(temp, *dollar);
		ms->line = ft_strjoin(temp2, temp1);
		ft_free_point(temp1);
		ft_free_point(temp2);
	}
	else
	{
		ft_free_point(ms->line);
		ms->line = ft_strjoin(temp, *dollar);
	}
	ft_free_point(temp);
}
