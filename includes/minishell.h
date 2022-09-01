/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 14:36:27 by lucasmar          #+#    #+#             */
/*   Updated: 2022/09/01 23:19:40 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "./define.h"
# include "./libs.h"
# include "./strutcs.h"


# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <fcntl.h> //access
# include <sys/wait.h>
# include <errno.h>
# include <signal.h>
//vars

void ft_cmd(t_ms *ms); // teste inicial

void	ft_error(int number);
void	ft_comand(char **env, char *comand, char *path);
int		ft_special(t_ms *ms);
void	ft_check_pipe(t_ms *ms);
void	ft_check_$(t_ms *ms);
void	ft_comand_split(t_ms *ms, t_cmd *cmd);
char	**ft_split_ms(char const *s, char c);

#endif
