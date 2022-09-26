/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 19:50:11 by lucasmar          #+#    #+#             */
/*   Updated: 2022/09/26 20:18:38 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_cd(t_ms *ms, t_cmd *cmd)
{
	char	*temp;

	if ( ms->n_pipe == 1)
	{
		if (g_ms.cd == 0)
			ms->oldpwd = (char *) malloc(1024 * sizeof(char));
		if (cmd[ms->p].arg_cmd[2] != NULL && cmd[ms->p].arg_cmd[1] != NULL)
			ft_error(16, ms);
		else if (cmd[ms->p].arg_cmd[1] == NULL ||
			ft_strncmp(cmd[ms->p].arg_cmd[1], "~", 1) == 0)
		{
			getcwd(ms->oldpwd, 1024);
			chdir(getenv("HOME"));
			g_ms.cd++;
		}
		else if (ft_strncmp(cmd[ms->p].arg_cmd[1], "-", 1) == 0)
		{
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
		else if (access(cmd[ms->p].arg_cmd[1], F_OK) == 0
			&& ft_valid_dir(cmd[ms->p].arg_cmd[1]) == 1)
		{
			getcwd(ms->oldpwd, 1024);
			chdir (cmd[ms->p].arg_cmd[1]);
			g_ms.cd++;
		}
		else
			ft_cd_error(ms, cmd);
	}
	ft_printf("");
}

int	ft_valid_dir(char *path)
{
	struct stat	statbuf;

	if (stat(path, &statbuf) != 0)
		return (0);
	return (S_ISDIR(statbuf.st_mode));
}
