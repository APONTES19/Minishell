/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 19:50:11 by lucasmar          #+#    #+#             */
/*   Updated: 2022/10/24 10:53:39 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_cd(t_ms *ms, t_cmd *cmd)
{
	g_ms.exit_s = 0;
	ms->k = 0;
	if (cmd[g_ms.p].arg_cmd[1] != NULL && cmd[g_ms.p].arg_cmd[2] != NULL)
		ft_error(14, ms, cmd, cmd[g_ms.p].arg_cmd[1]);
	else if (ft_cd_home(ms, cmd) == 0)
		ft_change_cd(ms, "HOME");
	else if (ft_strncmp_m(cmd[g_ms.p].arg_cmd[1], "-") == 0)
		ft_minus_cd(ms);
	else if (access(cmd[g_ms.p].arg_cmd[1], X_OK) == 0
		&& ft_valid_dir(cmd[g_ms.p].arg_cmd[1]) == 1)
		ft_change_cd(ms, cmd[g_ms.p].arg_cmd[1]);
	else
		ft_error(21, ms, cmd, cmd[g_ms.p].arg_cmd[1]);
	return ;
}

int	ft_cd_home(t_ms *ms, t_cmd *cmd)
{
	ms->k = 0;
	if (cmd[g_ms.p].arg_cmd[1] == NULL)
		return (0);
	if (ft_strncmp_m(cmd[g_ms.p].arg_cmd[1], "~") == 0)
	{
		ms->k = -890;
		return (0);
	}
	if (ft_strncmp_m(cmd[g_ms.p].arg_cmd[1], "~/") == 0)
	{
		ms->k = -890;
		return (0);
	}
	return (1);
}

void	ft_change_cd(t_ms *ms, char *change)
{
	char	*temp;
	char	*temp2;

	if (ms->n_pipe == 1)
	{
		ms->oldpwd = (char *) malloc(1024 * sizeof(char));
		getcwd(ms->oldpwd, 1024);
		temp = ft_getenv("OLDPWD");
		if (temp == NULL)
		{
			temp = ft_strjoin ("OLDPWD=", ms->oldpwd);
			ft_add_envp(temp);
			ft_free_point(temp);
		}
		temp2 = ft_strjoin ("OLDPWD=", ms->oldpwd);
		ft_change_envp("OLDPWD", temp2);
		if (ft_strncmp_m(change, "HOME") == 0)
			ft_aux_cd_change(ms, change);
		else
			chdir(change);
		ft_update_pwd(ms);
		ft_free_point(ms->oldpwd);
		ft_free_point(temp2);
		g_ms.cd++;
	}
}

int	ft_minus_cd(t_ms *ms)
{
	char	*get_old;
	char	*new_old;
	char	*old;

	get_old = ft_getenv("OLDPWD");
	if (get_old == NULL)
	{
		ft_error(15, ms, NULL, NULL);
		return (1);
	}
	else
	{
		old = ft_strdup(get_old);
		ms->temp = (char *) malloc (1024 * sizeof(char));
		getcwd(ms->temp, 1024);
		new_old = ft_strjoin("OLDPWD=", ms->temp);
		ft_change_envp("OLDPWD", new_old);
		printf("%s\n", old);
		chdir(old);
		ft_update_pwd(ms);
		ft_free_point(new_old);
		ft_free_point(old);
		ft_free_point(ms->temp);
	}
	return (0);
}
