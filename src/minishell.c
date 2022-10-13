/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 18:03:23 by lucasmar          #+#    #+#             */
/*   Updated: 2022/10/13 17:16:53 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_ms	g_ms;
int	main(int argc, char **argv, char **envp)
{
	t_ms	ms;
	t_cmd	cmd;

	(void )argv;
	if(argc == 1)
	{
		if (ft_set_parameters(&ms, envp) == 0)
			while(1)
			{
				ft_set_init(&ms, &cmd);
				ft_get_line(&ms);
				add_history(ms.line);
				if (ft_check_input(&ms) == 0)
					ft_command_split(&ms, &cmd, envp);
				dup2(g_ms.stdin, STDIN);
				dup2(g_ms.stdout, STDOUT);
			}
	}
	else
		ft_error(0, &ms, &cmd);
	return (g_ms.exit_s);
}

int	ft_set_parameters(t_ms *ms, char **envp)
{
		if (envp == NULL)
		{
			ft_error(06, ms, NULL);
			return (1);
		}
		ms->oldpwd = NULL;
		g_ms.envp = NULL;
		ft_copy_envp(envp);
		if (g_ms.envp == NULL)
			return (1);
		g_ms.exit_s = 0;
		g_ms.cd = 0;
		g_ms.stdin = dup(STDIN);
		g_ms.stdout = dup(STDOUT);
	return (0);
}

void	ft_set_init(t_ms *ms, t_cmd *cmd)
{
	ft_memset(ms, '0', sizeof(ms));
	ft_memset(cmd, '0', sizeof(cmd));
	ms->path_infile = NULL;
	ms->path_outfile = NULL;
}
