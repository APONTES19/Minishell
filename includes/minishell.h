/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 14:36:27 by lucasmar          #+#    #+#             */
/*   Updated: 2022/09/21 22:14:58 by lucasmar         ###   ########.fr       */
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
# include <fcntl.h>
# include <sys/wait.h>
# include <errno.h>
# include <signal.h>

void	ft_get_line(t_ms *ms);
void	ft_check_space(t_ms *ms);
void	ft_error(int number, t_ms *ms);
void	ft_error_2(int number, t_cmd *cmd, t_ms *ms);
int		ft_special(t_ms *ms);
int		ft_check_pipe(t_ms *ms);
void	ft_check_$(t_ms *ms);
int		ft_command_split(t_ms *ms, t_cmd *cmd, char **envp);
char	**ft_split_ms(char const *s, char c);
int		ft_get_path(t_ms *ms, char *cmd, char **envp);
void	ft_base_free(t_ms *ms, t_cmd *cmd);
int		ft_check_input(t_ms *ms);
int		next_pipe(t_ms *ms);
int		ft_check_quote(t_ms	*ms);
void	ft_aux_path(t_ms *ms, int number);
void	ft_command(t_ms *ms, t_cmd *cm, char **envp);
void	ft_exit(t_ms *ms, t_cmd *cmd);
void	ft_select (t_ms *ms, t_cmd *cmd, char **envp);
void	ft_select_arg(t_ms *ms, t_cmd *cmd, char **envp);
void	ft_echo(t_ms *ms, t_cmd *cmd);
void	ft_quote_echo(t_ms *ms, t_cmd *cmd);
void	ft_clean_quote(t_cmd *cmd);
void	ft_creat_pipe(t_ms *ms);
void	ft_close_fds(t_ms *ms);
void	ft_change_fd(int input, int output, t_ms *ms);
void	ft_execve_parent(t_ms *ms, t_cmd *cm);
void	ft_select_fd(t_ms *ms);
int		ft_check_redirection(t_ms *ms);
int		ft_redirection(t_ms *ms);
int		ft_path_output(t_ms *ms);
void	ft_dup_path(int end, int start, char *path, t_ms *ms);
int		ft_set_out_in(t_ms *ms);
void	ft_aux_dup_path(t_ms *ms, int start, int end);
#endif
