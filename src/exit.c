/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 20:30:07 by lucasmar          #+#    #+#             */
/*   Updated: 2022/10/16 19:20:51 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_exit_m(t_ms *ms, t_cmd *cmd)
{
	(void)cmd;
	rl_clear_history();
	ft_free_point(ms->head);
	ft_free_point(ms->line);
	exit(g_ms.exit_s);
}
