/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strutcs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 10:02:36 by lucasmar          #+#    #+#             */
/*   Updated: 2022/09/26 22:18:41 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUTCS_H
# define STRUTCS_H

typedef struct minishell
{
	int		*fd;
	int		pipe;
	int		p;
	int		n_pipe;
	int		pipe_d;
	char	*line;
	int		n_$;
	int		redirection;
	int		i;
	int		j;
	int		k;
	char	**path_list;
	char	*path_cmd;
	char	*path_outfile;
	char	*path_infile;
	int		fd_out;
	int		fd_in;
	char	*temp;
	int		pid;
	int		pid1;
	char	**envp;
	int		quote;
	int		std_out;
	int		std_in;
	int		exit_s;
	int		cd;
	char	*oldpwd;
	char	*head;
}	t_ms;

typedef struct comand
{
	char	**arg_cmd;
	char	**base_list_cmd;
}	t_cmd;

extern	t_ms g_ms;
#endif
