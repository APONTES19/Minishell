/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 14:36:27 by lucasmar          #+#    #+#             */
/*   Updated: 2022/10/11 01:49:25 by ryoshio-         ###   ########.fr       */
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
# include <sys/types.h>
# include <sys/stat.h>

//CHECK INPUT 1
int		ft_check_input(t_ms *ms);
int		ft_check_quote(t_ms	*ms);
int		ft_check_pipe(t_ms *ms);

//CHECK INPUT 2
int		ft_special(t_ms *ms);
void	ft_check_dolar(t_ms *ms);
void	ft_check_space(t_ms *ms);
int		next_pipe(t_ms *ms);
int		ft_check_redirection(t_ms *ms);

// COMMAND 1
void	ft_execve(t_ms *ms, t_cmd *cm, char **envp);

// COMMAND 2
int		ft_command_split(t_ms *ms, t_cmd *cmd, char **envp);
int		ft_get_path(t_ms *ms, char *cmd, char **envp);
void	ft_aux_path(t_ms *ms, int number);

//ECHO
void	ft_quote_echo(t_ms *ms, t_cmd *cmd);
void	ft_echo(t_ms *ms, t_cmd *cmd);
void	ft_print_var(t_ms *ms, t_cmd *cmd);

// ENV 1
void	ft_env(t_ms *ms, t_cmd *cmd);
void	ft_copy_envp(char **envp);
char	*ft_getenv(char *s);

// ENV 2
void	ft_change_envp(char *variable, char *value);
void	ft_add_envp(char *variable);
char	**ft_copy_temp_envp(char **base, char *variable);

// EXPORT 1
void	ft_export(t_ms *ms, t_cmd *cmd);
void	ft_set_export(t_cmd *cmd, t_ms *ms);
int		ft_export_special(t_ms *ms, t_cmd *cmd);

// EXPORT 2
void	ft_print_export(void);
int		*ft_sort_envp(void);
void	ft_initializing_sort(t_sort *sort);

// SPLIT
char	**ft_split_ms(char const *s, char c);

//pwd
void	ft_pwd(void);

//ft_get_line 
void	ft_get_line(t_ms *ms);
void	ft_get_head_line(t_ms *ms);
char	*ft_three_join(char *s1, char *s2, char *s3);

//SELLECT
void	ft_main_while(t_ms *ms, t_cmd *cmd, char **envp);
void	ft_clean_quote(t_cmd *cmd);
void	ft_select_build(t_ms *ms, t_cmd *cmd);
int		ft_check_build(t_ms *ms, t_cmd *cmd);
void	ft_set_fd_1(t_ms *ms);
void	ft_set_fd_2(t_ms *ms);

//UNSET 1
void	ft_unset(t_ms *ms, t_cmd *cmd);
void	ft_unset2(char *src);
int		ft_index_envp(char *src);
size_t	ft_strstrlen(char **src);
char	**ft_strstrdup(char **src);

//cd
void	ft_cd(t_ms *ms, t_cmd *cmd);
int		ft_valid_dir(char *path);
void	ft_change_cd(t_ms *ms, char *change);
void	ft_minus_cd(t_ms *ms);

//REDIRECTION
void	ft_redirection(t_ms *ms);
void	ft_red_point(t_ms *ms, int type, char **path);
void	ft_red_point_aux(t_ms *ms, char f, int type);
int		ft_set_out(t_ms *ms, int type);
int		ft_set_in(t_ms *ms, int type);

//REDIRECTION2
void	ft_red_temp(t_ms *ms, int start, int end, char **path);
void	ft_red_temp_aux1(t_ms *ms);
void	ft_red_temp_aux2(t_ms *ms, int start, int end, char **path);
void	ft_red_temp_aux3(t_ms *ms, char **path);
void	ft_red_copy_line(t_ms *ms, int start, int end);

//REDIRECTION3
int		ft_here_doc_open(char *str);

//ERROR
void	ft_error(int number, t_ms *ms);
void	ft_error_2(int number, t_cmd *cmd, t_ms *ms);
void	ft_base_free(t_ms *ms, t_cmd *cmd);
void	ft_exit(t_ms *ms, t_cmd *cmd);
void	ft_free_two_point(char **point);
void	ft_free_point(char *point);
void	ft_cd_error(t_ms *ms, t_cmd *cmd);

#endif
