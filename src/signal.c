/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 20:36:51 by lucasmar          #+#    #+#             */
/*   Updated: 2022/10/23 04:54:20 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_quit(int signum)
{
	int	i;
	(void)signum;

	i = 0;
	while(i < g_ms.p && g_ms.command_on == 1)
	{
		if (g_ms.pid[i] > 0 )
			kill(g_ms.pid[i], SIGKILL);
		i ++;
	}
	if (g_ms.command_on == 1)
		ft_putstr_fd("Quit\n", 1);
}

void    ft_kill_loop(int signum)
{
    int     i;

    (void)signum;
    
    if (g_ms.open_hero_doc == 1)
	{
		dup2(g_ms.fo, STDIN);
		close(STDIN);
        write (1, "\n", 1);
        rl_replace_line("", 0);
        rl_redisplay();
        return ;
	}

    if (g_ms.command_on == 0)
    {
      
      
        
        rl_replace_line("", 0);
         write (1, "\n", 1);
        rl_on_new_line();
        rl_redisplay();
    }

    
    if(g_ms.command_on == 1)
    {
        printf("Estamos aqui?");
        ft_putstr_fd("\n", 1);
        i =0;
        while(i < g_ms.n_pipe )
        {
            if (g_ms.pid[i] > 0 )
            {
                kill(g_ms.pid[i], SIGKILL);
            }
      	  i ++;
        }
    }



    g_ms.exit_s = 130;
}
