/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 15:22:52 by lucasmar          #+#    #+#             */
/*   Updated: 2022/10/24 10:17:56 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_red_check_next(t_ms *ms)
{
	int	i;

	i = 1;
	if (g_ms.line[ms->i + i])
	{
		if (ft_strchr("<>", g_ms.line[ms->i + i]) != NULL)
		{
			i++;
			ms->type = 2;
		}
		while (g_ms.line[ms->i + i] == ' ')
			i++;
		if (ft_strchr("|><", g_ms.line[ms->i + i]) != NULL)
		{
			ft_error(30, ms, NULL, NULL);
			return (1);
		}
	}
	return (0);
}
