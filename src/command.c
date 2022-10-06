/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 20:21:10 by lucasmar          #+#    #+#             */
/*   Updated: 2022/10/06 18:41:41 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_command(t_ms *ms, t_cmd *cm, char **envp)
{
	ms->pid = fork();
	if (ms->pid < 0)
		ft_error (2, ms);



	if (ms->pid == 0)
	{
		//close(ms->pipe[0]);
		// if (ms->p < (ms->n_pipe - 1))
		// 	dup2(ms->pipe[1], STDOUT);
		// if (ms->p == (ms->n_pipe -1) && ms->path_outfile != NULL)
		// dup2(g_ms.fileout, STDOUT);
		// if (ms->p == 0 && ms->path_infile != NULL)
		// {
		// 	dup2(g_ms.filein, STDIN);
		// 	close(g_ms.filein);
		// }
		//close(ms->pipe[1]);
		if(ft_get_path(ms, cm[ms->p].arg_cmd[0], envp) == 0)
			ft_error_2(07, cm, ms);
		else
			if ((execve(ms->path_cmd, cm[ms->p].arg_cmd, NULL)) == -1)
				ft_error (3, ms);
	}





	//if (ms->pid > 0)
	//	ft_execve_parent(ms, cm);
}

// void	ft_execve_parent(t_ms *ms, t_cmd *cm)
// {
// 	(void) cm;
// 	if (ms->p == (ms->n_pipe - 1))
// 	{
// 		if (ms->n_pipe > 1)
// 			ft_close_fds(ms);
// 		//ft_exit(ms, cm);
// 	}
// }


