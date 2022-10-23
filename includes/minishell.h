/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 14:36:27 by lucasmar          #+#    #+#             */
/*   Updated: 2022/10/23 09:15:31 by lucasmar         ###   ########.fr       */
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

int		ft_check_input(t_ms *ms, t_cmd *cmd);
int		ft_check_quote(t_ms	*ms);
int		ft_check_pipe(t_ms *ms);
int		ft_next_pipe(t_ms *ms);
int		ft_next_pipe_2(t_ms *ms);
int		ft_special(t_ms *ms);
int		ft_check_dolar(t_ms *ms);
void	ft_check_space(t_ms *ms);
int		ft_check_redirection(t_ms *ms);
void	ft_clean_quote_aux_1(t_ms *ms, char **temp);
void	ft_clean_quote_aux_2(t_ms *ms, t_cmd *cmd, char **temp, char type);
void	ft_clean_quote(t_ms *ms, t_cmd *cmd);
int		ft_set_line_dollar(t_ms *ms);
void	ft_get_path_dollar(t_ms *ms);
void	ft_change_line_dollar(t_ms *ms, char *dollar);
void	ft_aux_dollar_1(t_ms *ms);
void	ft_aux_dollar_2(t_ms *ms, char **temp, char **temp2);
void	ft_aux_dollar_3(t_ms *ms, char **temp, char **temp2);
int		ft_strncmp_m(const char *str1, const char *str2);
void	ft_exit_m(t_ms *ms, t_cmd *cmd);
void	ft_execve(t_ms *ms, t_cmd *cm);
int		ft_command_split(t_ms *ms, t_cmd *cmd);
int		ft_command_split_aux(t_ms *ms, t_cmd *cmd);
int		ft_get_path(t_ms *ms, char *cmd);
void	ft_aux_path(t_ms *ms, int number);
void	ft_echo(t_ms *ms, t_cmd *cmd);
void	ft_echo_while(t_ms *ms, t_cmd *cmd);
void	ft_env(t_ms *ms, t_cmd *cmd);
void	ft_copy_envp(char **envp);
char	*ft_getenv(char *s);
void	ft_change_envp(char *variable, char *value);
void	ft_add_envp(char *variable);
char	**ft_copy_temp_envp(char **base, char *variable);
void	ft_export(t_ms *ms, t_cmd *cmd);
void	ft_set_export(t_cmd *cmd);
int		ft_export_special(t_ms *ms, t_cmd *cmd);
void	ft_print_export(void);
int		*ft_sort_envp(void);
void	ft_initializing_sort(t_sort *sort);
char	**ft_split_ms(char const *s, char c);
void	ft_pwd(void);
int		ft_set_parameters(t_ms *ms, char **envp);
void	ft_set_init(t_ms *ms, t_cmd *cmd);
void	ft_set_end(t_ms *ms, t_cmd *cmd);
void	ft_get_line(t_ms *ms);
void	ft_get_head_line(t_ms *ms);
void	ft_main_while(t_ms *ms, t_cmd *cmd);
void	ft_check_build(t_ms *ms, t_cmd *cmd);
void	ft_set_fd_1(t_ms *ms);
void	ft_set_fd_2(t_ms *ms);
void	ft_unset(t_cmd *cmd);
void	ft_unset2(char *src);
int		ft_index_envp(char *src);
size_t	ft_strstrlen(char **src);
char	**ft_strstrdup(char **src);
void	ft_cd(t_ms *ms, t_cmd *cmd);
int		ft_valid_dir(char *path);
void	ft_change_cd(t_ms *ms, char *change);
int		ft_minus_cd(t_ms *ms);
int		ft_cd_home(t_ms *ms, t_cmd *cmd);
void	ft_update_pwd(t_ms *ms);
void	ft_aux_cd_change(t_ms *ms, char *change);
int		ft_redirection(t_ms *ms);
int		ft_redirection_2(t_ms *ms);
int		ft_redirection_3(t_ms *ms, int type);
void	ft_red_point(t_ms *ms, int type, char **path);
void	ft_red_point_aux(t_ms *ms, char f, int type);
void	ft_red_temp(t_ms *ms, int start, int end, char **path);
void	ft_red_temp_aux1(t_ms *ms);
void	ft_red_temp_aux2(t_ms *ms, int start, int end, char **path);
void	ft_red_temp_aux3(t_ms *ms, char **path);
void	ft_red_copy_line(t_ms *ms, int start, int end);
void	ft_redirection_aux(t_ms *ms, char q);
int		ft_here_doc_open(char *str);
int		ft_set_out(t_ms *ms, int type);
int		ft_set_in(t_ms *ms, int type);
void	ft_red_copy_line_aux(t_ms **ms, int start, int end, char t);
void	ft_error(int number, t_ms *ms, t_cmd *cm, char *cmd);
void	ft_error_1(int number, t_ms *ms, t_cmd *cm, char *cmd);
void	ft_error_2(int number, t_ms *ms, t_cmd *cm, char *cmd);
void	ft_error_3(int number, t_ms *ms, t_cmd *cm, char *cmd);
void	ft_error_4(int number, t_ms *ms, t_cmd *cm, char *cmd);
void	ft_error_5(int number, t_ms *ms, t_cmd *cm, char *cmd);
void	ft_free_cmd(t_ms *ms, t_cmd *cmd);
void	ft_free_two_point(char **point);
void	ft_free_point(char *point);
void	ft_free_exit(t_ms *ms, t_cmd *cmd);
int		ft_str_isnum(char *str);
void	ft_quit(int signum);
void	ft_main_while_aux(t_ms *ms);
int		ft_red_check_next(t_ms *ms);
void	ft_free_crtl_d(t_ms *ms);
void	ft_kill_loop(int signum);

#endif
