/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strutcs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 10:02:36 by lucasmar          #+#    #+#             */
/*   Updated: 2022/09/10 04:53:11 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUTCS_H
# define STRUTCS_H

typedef struct minishell
{
	int		fd;
	char	*line;
	int		n_pipe;
	int		n_$;
	int		i;
	int		j;
	int		k;
	char	**path_list;
	char	*path_cmd;
	char	*temp;
	int		pid;
	char	**envp;
	int		pipe_d;
}	t_ms;

typedef struct comand
{
	char	**arg_cmd;
	char	**base_list_cmd;
}	t_cmd;


#endif
