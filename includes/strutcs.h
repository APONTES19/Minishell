/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strutcs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 10:02:36 by lucasmar          #+#    #+#             */
/*   Updated: 2022/09/01 21:04:21 by lucasmar         ###   ########.fr       */
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
}	t_ms;

typedef struct comand
{
	char	**list_cmd;
	char	**base_list_cmd;
}	t_cmd;


#endif
