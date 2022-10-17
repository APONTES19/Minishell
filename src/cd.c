/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 19:50:11 by lucasmar          #+#    #+#             */
/*   Updated: 2022/10/16 23:12:31 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_cd(t_ms *ms, t_cmd *cmd)
{
	g_ms.exit_s = 0;
	ms->k = 0;
	if (ms->n_pipe == 1)
	{
		if (g_ms.cd == 0 && ms->oldpwd == NULL)
			ms->oldpwd = (char *) malloc(1024 * sizeof(char));
		if (cmd[ms->p].arg_cmd[2] != NULL && cmd[ms->p].arg_cmd[1] != NULL)
		{
			ft_error(14, ms, cmd);
			return ;
		}
		else if (ft_cd_home(ms ,cmd) == 0)
				ft_change_cd(ms, "HOME");
		else if (ft_strncmp_m(cmd[ms->p].arg_cmd[1], "-") == 0)
		{
			if(ft_minus_cd(ms) == 1)
				return ;
		}
		else if (access(cmd[ms->p].arg_cmd[1], X_OK) == 0
			&& ft_valid_dir(cmd[ms->p].arg_cmd[1]) == 1)
			ft_change_cd(ms, cmd[ms->p].arg_cmd[1]);
		else
		{
			ft_error(21, ms, cmd);
			return ;
		}
	}
	return ;
}

int	ft_cd_home(t_ms *ms, t_cmd *cmd)
{
	ms->k = 0;
	if (cmd[ms->p].arg_cmd[1] == NULL)
		return(0);
	if(ft_strncmp_m(cmd[ms->p].arg_cmd[1], "~") == 0)
	{
		ms->k = -890;
		return (0);
	}
	if(ft_strncmp_m(cmd[ms->p].arg_cmd[1], "~/") == 0)
	{
		ms->k = -890;
		return (0);
	}
	return (1);
}

int	ft_valid_dir(char *path)
{
	struct stat	statbuf;

	if (stat(path, &statbuf) != 0)
		return (0);
	return (S_ISDIR(statbuf.st_mode));
}

void	ft_change_cd(t_ms *ms, char *change)
{
	char	*temp;
	char	*temp2;

	getcwd(ms->oldpwd, 1024);
	temp = ft_getenv("OLDPWD");
	if (temp == NULL)
	{
		temp = ft_strjoin (ft_strdup("OLDPWD="), ms->oldpwd);
		ft_add_envp(temp);
		ft_free_point(temp);
	}
	temp2 = ft_strjoin (ft_strdup("OLDPWD="), ms->oldpwd);
	ft_change_envp("OLDPWD", temp2);
	if (ft_strncmp_m(change, "HOME") == 0)
	{
		ms->temp = ft_getenv(change);
		if (ms->k == -890)
			chdir(getenv(change));
		else if (ms->temp == NULL)
			ft_error(23, ms , NULL);
		else
			if (chdir(ft_getenv(change)) == -1)
				ft_error(25, ms, NULL);
	}
	else
		chdir(change);
	ft_free_point(temp2);
	ft_update_pwd(ms);
	g_ms.cd++;
}

int	ft_minus_cd(t_ms *ms)
{
	char	*temp;
	char	*temp2;

	if (g_ms.cd == 0)
	{
		ft_error(15, ms, NULL);
		return (1);
	}
	else
	{
		temp = ft_strdup(ms->oldpwd);
		getcwd(ms->oldpwd, 1024);
		temp2 = ft_strjoin("OLDPWD=", ms->oldpwd);
		ft_change_envp("OLDPWD", temp2);
		ft_printf("%s\n", temp);
		chdir(temp);
		ft_free_point(temp);
		ft_free_point(temp2);
	}
	ft_update_pwd(ms);
	return (0);
}

void	ft_update_pwd(t_ms *ms)
{
	char *temp2;

	ms->pwd = (char *) malloc(1024 * sizeof(char));
	getcwd(ms->pwd, 1024);
	temp2 = ft_strjoin("PWD=", ms->pwd);
	ft_change_envp("PWD", temp2);
	ft_free_point(ms->pwd);
	ft_free_point(temp2);
}
