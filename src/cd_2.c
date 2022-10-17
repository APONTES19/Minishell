/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 00:20:50 by lucasmar          #+#    #+#             */
/*   Updated: 2022/10/17 00:31:28 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_valid_dir(char *path)
{
	struct stat	statbuf;

	if (stat(path, &statbuf) != 0)
		return (0);
	return (S_ISDIR(statbuf.st_mode));
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

void	ft_aux_cd_change(t_ms *ms, char *change)
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
