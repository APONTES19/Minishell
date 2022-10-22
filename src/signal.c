/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 20:36:51 by lucasmar          #+#    #+#             */
/*   Updated: 2022/10/22 17:47:51 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void    ft_quit(int signum)
{
    int     i;
    (void)signum;

    i = 0;
    //printf("quit");
    printf("\n ignal qui \n");
    while(i < g_ms.n_pipe && g_ms.command_on == 1)
    {
        if (g_ms.pid[i] > 0 )
        {
            kill(g_ms.pid[i], SIGKILL);
            ft_putstr_fd("Quit\n", 1);
        }
        i ++;
    }
}

void    ft_kill_loop(int signum)
{
    int     i;
    (void)signum;
 //printf("valor do comand %d", g_ms.command_on);
    if (g_ms.open_hero_doc > 0)
    {
        //printf("valor do comand %d", g_ms.command_on);

        //unlink(".h
        close(g_ms.command_on);

        g_ms.open_hero_doc =-1;
    }

    if(g_ms.command_on == 1)
    {
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
    if (g_ms.command_on == 0)
    {
        write (1, "\n", 1);
        rl_on_new_line();
        rl_replace_line("", 0);
        rl_redisplay();
    }


    g_ms.exit_s = 130;
}
