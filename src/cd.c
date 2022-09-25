/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 19:50:11 by lucasmar          #+#    #+#             */
/*   Updated: 2022/09/26 00:18:25 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_cd(t_ms *ms, t_cmd *cmd)
{
	printf("cd:%d\n",ms->cd);
	if ( ms->n_pipe == 1)
	{
		if (cmd[ms->p].arg_cmd[2] != NULL && cmd[ms->p].arg_cmd[1] != NULL)
			ft_error(16, ms);
		else if (cmd[ms->p].arg_cmd[1] == NULL ||
			ft_strncmp(cmd[ms->p].arg_cmd[1], "~", 1) == 0)
		{
			chdir(getenv("HOME"));
			ms->cd++;
		}
		else if (ft_strncmp(cmd[ms->p].arg_cmd[1], "-", 1) == 0)
		{
			if (ms->cd == 0)
				ft_error(17, ms);
			ft_printf("%s\n",getenv("PWD"));
			chdir(getenv("OLDPWD"));
		}
		else if (access(cmd[ms->p].arg_cmd[1], F_OK) == 0
			&& ft_valid_dir(cmd[ms->p].arg_cmd[1]) == 1)
		{
			chdir (cmd[ms->p].arg_cmd[1]);
			ms->cd++;
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
