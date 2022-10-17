/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 19:50:11 by lucasmar          #+#    #+#             */
/*   Updated: 2022/10/17 13:04:15 by lucasmar         ###   ########.fr       */
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
			ft_error(14, ms, cmd, cmd[ms->p].arg_cmd[1]);
		else if (ft_cd_home(ms ,cmd) == 0)
				ft_change_cd(ms, "HOME");
		else if (ft_strncmp_m(cmd[ms->p].arg_cmd[1], "-") == 0)
			ft_minus_cd(ms);
		else if (access(cmd[ms->p].arg_cmd[1], X_OK) == 0
			&& ft_valid_dir(cmd[ms->p].arg_cmd[1]) == 1)
			ft_change_cd(ms, cmd[ms->p].arg_cmd[1]);
		else
			ft_error(21, ms, cmd, cmd[ms->p].arg_cmd[1]);
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
		ft_aux_cd_change(ms, change);
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
		ft_error(15, ms, NULL, NULL);
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

