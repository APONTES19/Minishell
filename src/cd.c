/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 19:50:11 by lucasmar          #+#    #+#             */
/*   Updated: 2022/09/26 22:57:07 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_cd(t_ms *ms, t_cmd *cmd)
{
	if ( ms->n_pipe == 1)
	{
		if (g_ms.cd == 0)
			ms->oldpwd = (char *) malloc(1024 * sizeof(char));
		if (cmd[ms->p].arg_cmd[2] != NULL && cmd[ms->p].arg_cmd[1] != NULL)
			ft_error(16, ms);
		else if (cmd[ms->p].arg_cmd[1] == NULL ||
			ft_strncmp(cmd[ms->p].arg_cmd[1], "~", 1) == 0)
			ft_change_cd(ms, "HOME");
		else if (ft_strncmp(cmd[ms->p].arg_cmd[1], "-", 1) == 0)
			ft_minus_cd(ms);
		else if (access(cmd[ms->p].arg_cmd[1], F_OK) == 0
			&& ft_valid_dir(cmd[ms->p].arg_cmd[1]) == 1)
			ft_change_cd(ms, cmd[ms->p].arg_cmd[1]);
		else
			ft_cd_error(ms, cmd);
	}
	return ;
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
	getcwd(ms->oldpwd, 1024);
	if (ft_strncmp(change, "HOME", 4) == 0)
		chdir(getenv(change));
	else
		chdir(change);
	g_ms.cd++;
}

void	ft_minus_cd(t_ms *ms)
{
	char	*temp;

	if (g_ms.cd == 0)
		ft_error(17, ms);
	else
	{
		temp = ft_strdup(ms->oldpwd);
		getcwd(ms->oldpwd, 1024);
		ft_printf("%s\n", temp);
		chdir(temp);
		free(temp);
	}
}
