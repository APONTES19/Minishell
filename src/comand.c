/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 20:04:05 by ryoshio-          #+#    #+#             */
/*   Updated: 2022/07/21 21:00:32 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"


void ft_comand(char **env, char *comand, char *path)
{

	int pid;

	pid = fork();
	
	
	if(pid>0)
	{
		wait(&pid);
		ft_printf("processo pai \n");
		
	}	
	if(pid == 0)
	{
		ft_printf("processo filho inicalizado \n");
			if(execve(path, &comand, env)==-1)
				ft_printf("\nErro\n");
	}

	ft_printf("processo comun \n");

	

			
	
	
}