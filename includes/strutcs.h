/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strutcs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 10:02:36 by lucasmar          #+#    #+#             */
/*   Updated: 2022/10/18 16:08:00 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUTCS_H
# define STRUTCS_H

typedef struct minishell
{
	int		*fd;
	int		pipe[2];
	int		p;
	int		n_pipe;
	int		pipe_d;
	char	*line;
	int		n_dollar;
	int		i;
	int		j;
	int		k;
	char	t;
	int		m;
	int		start;
	int		end;
	int		home_i;
	char	**path_list;
	char	*path_cmd;
	char	*path_outfile;
	char	*path_infile;
	int		fd_out;
	int		fd_in;
	char	*temp;
	int		*pid;
	int		pid1;
	int		quote;
	int		stdout;
	int		stdin;
	int		exit_s;
	int		cd;
	char	*oldpwd;
	char	*pwd;
	char	*head;
	char	**envp;
	int		fileout;
	int		filein;
	int		redirection;
	int		cmd;
}	t_ms;

typedef struct comand
{
	char	**arg_cmd;
	char	**base_list_cmd;
}	t_cmd;

typedef struct sort
{
	int	*sort;
	int	*catch;
	int	i;
	int	j;
	int	k;
}	t_sort;

typedef struct _var
{
	size_t	i;
	size_t	p;
	int		index;
	char	**result;
	int		quote;
	int		len_s;
	int		n_q;
}t_var;

extern t_ms	g_ms;
#endif
