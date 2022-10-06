/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 15:24:19 by lucasmar          #+#    #+#             */
/*   Updated: 2022/10/06 11:44:41 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_select_fd(t_ms *ms)
{
	if (ms->n_pipe == 1)
		ft_change_fd(ms->fd_in, ms->fd_out, ms);
	else
	{
		if(ms->p == 0)
			ft_change_fd(ms->fd_in, ms->fd[1], ms);
		if(ms->p > 0 && ms->p < (ms->n_pipe - 1))
			ft_change_fd(ms->fd[(2 * ms->p) - 2],
				ms->fd[(2 * ms->p) + 1], ms);
		if(ms->p == (ms->n_pipe - 1))
			ft_change_fd(ms->fd[(2 * ms->p) - 2] , ms->fd_out, ms);
	}
}

void	ft_change_fd(int input, int output, t_ms *ms)
{
	(void)input;
	//if (dup2(input, 0) == -1)
	//	ft_error(10, ms);
	if (dup2(output, 1) == -1)
		ft_error(10, ms);
}

// void	ft_creat_pipe(t_ms *ms)
// {
// 	int	i;

// 	i = 0;
// 	ms->fd = malloc(2 * (ms->n_pipe - 1) * sizeof(ms->pipe));
// 	while(i < (ms->n_pipe - 1))
// 	{
// 		ms->pipe = pipe(ms->fd + (2 * i));
// 		if (ms->pipe == -1)
// 			ft_error(9, ms);
// 		i++;
// 	}
// }

void	ft_close_fds(t_ms *ms)
{
		int	i;
		if(ms->n_pipe == 1)
		{
			close(ms->fd_out);
		}
		else
		{
			i = (((ms->n_pipe - 1) * 2) - 1 );
			while (i != -1)
			{
				close(ms->fd[i]);
				i--;
			}
		}
}
