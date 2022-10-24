/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 20:36:51 by lucasmar          #+#    #+#             */
/*   Updated: 2022/10/24 10:28:03 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	ft_kill_loop_utils(void);

void	ft_quit(int signum)
{
	int	i;

	(void)signum;
	i = 0;
	while (i < g_ms.p && g_ms.command_on == 1)
	{
		if (g_ms.pid[i] > 0)
			kill(g_ms.pid[i], SIGKILL);
		i ++;
	}
	if (g_ms.command_on == 1)
		ft_putstr_fd("Quit\n", 1);
}

void	ft_kill_loop(int signum)
{
	(void)signum;
	if (g_ms.open_hero_doc == 1)
	{
		g_ms.open_hero_doc = 0;
		g_ms.exit_s = 130;
		dup2(g_ms.fo, STDIN);
		close(STDIN);
		ft_free_point(g_ms.line);
		ft_free_point(g_ms.path_infile);
		write (1, "\n", 1);
		rl_replace_line("", 0);
		rl_redisplay();
		return ;
	}
	if (g_ms.command_on == 0)
	{
		write (1, "\n", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
		g_ms.exit_s = 130;
		return ;
	}
	ft_kill_loop_utils();
}

static void	ft_kill_loop_utils(void)
{
	int	i;

	if (g_ms.command_on == 1)
	{
		i = 0;
		while (i < g_ms.n_pipe)
		{
			if (g_ms.pid[i] > 0)
				kill(g_ms.pid[i], SIGKILL);
			i ++;
		}
		g_ms.command_on = 0;
	}
	g_ms.exit_s = 130;
}
