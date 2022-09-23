/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 19:50:11 by lucasmar          #+#    #+#             */
/*   Updated: 2022/09/23 19:58:51 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_cd(t_ms *ms, t_cmd *cmd)
{
	char	*s;

	s = malloc(100 * sizeof(char));
	getcwd(s, 100);
	if (cmd[ms->p].arg_cmd[1] == NULL)
	{
		chdir("~");
		printf("entrei na raiz\n");
	}
	else
	{
		if(chdir(cmd[ms->p].arg_cmd[1]) != 1)
			ft_error(19, ms);
	}
	free(s);
}




// static void	no_dir_error(char **cmd)
// {
// 	g_data->exit_code = 1;
// 	ft_putstr_fd("cd: ", STDERR);
// 	ft_putstr_fd(cmd[1], STDERR);
// 	if (access(cmd[1], F_OK) == 0)
// 		ft_putstr_fd(": Not a directory\n", STDERR);
// 	else
// 		ft_putstr_fd(": No such file or directory\n", STDERR);
// }

// static void	cd_to_oldpwd(void)
// {
// 	if (find_env("OLDPWD") == NULL)
// 	{
// 		ft_putstr_fd("cd: OLDPWD not set\n", STDERR);
// 		return ;
// 	}
// 	chdir(find_env("OLDPWD"));
// 	ft_putstr_fd(find_env("OLDPWD"), STDOUT);
// 	write (1, "\n", 1);
// }

// static void	change_pwd(void)
// {
// 	char	*buf;
// 	char	*old_pwd;
// 	char	*cwd;

// 	if (find_env("PWD") == NULL)
// 		return ;
// 	buf = malloc (1024);
// 	old_pwd = ft_my_strjoin(ft_strdup("OLDPWD="), find_env("PWD"));
// 	cwd = ft_my_strjoin(ft_strdup("PWD="), getcwd(buf, 1024));
// 	do_export(cwd);
// 	do_export(old_pwd);
// 	free (cwd);
// 	free (old_pwd);
// 	free (buf);
// }

// void	cd_built_in(char **cmd)
// {
// 	g_data->exit_code = 0;
// 	if (cmd[1] == NULL || ft_str_check(cmd[1], "~"))
// 	{
// 		if (find_env("HOME") == NULL)
// 			return ;
// 		chdir (find_env("HOME"));
// 		change_pwd();
// 	}
// 	else if (cmd[2] != NULL)
// 	{
// 		g_data->exit_code = 1;
// 		ft_putstr_fd("cd: too many arguments\n", STDERR);
// 	}
// 	else
// 	{
// 		if (ft_str_check(cmd[1], "-"))
// 			cd_to_oldpwd();
// 		else if (access(cmd[1], F_OK) == 0 && check_dir(cmd[1]) == 1)
// 			chdir(cmd[1]);
// 		else
// 			no_dir_error(cmd);
// 		change_pwd();
// 	}
// }
