/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 20:30:07 by lucasmar          #+#    #+#             */
/*   Updated: 2022/10/17 01:56:22 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_exit_m(t_ms *ms, t_cmd *cmd)
{
	(void)cmd;
	(void)ms;
	rl_clear_history();
	ft_free_two_point(g_ms.envp);
	exit(g_ms.exit_s);
}
