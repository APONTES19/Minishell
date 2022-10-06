/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 18:03:23 by lucasmar          #+#    #+#             */
/*   Updated: 2022/10/06 11:50:16 by lucasmar         ###   ########.fr       */
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
		if (envp == NULL)
			ft_error(06, &ms);
		ft_copy_envp(envp);
		ft_memset(&ms, '0', sizeof(ms));
		ft_memset(&cmd, '0', sizeof(cmd));
		g_ms.cd = 0;
		g_ms.stdin = dup(STDIN);
		g_ms.stdout = dup(STDOUT);
		while(1)
		{
			ft_get_line(&ms);
			add_history(ms.line);
			if (ft_check_input(&ms) != 0)
				ft_command_split(&ms, &cmd, envp);
			dup2(g_ms.stdin, STDIN);
			dup2(g_ms.stdout, STDOUT);
		}
	}
	else
		ft_error(0, &ms);
	return (0);
}

void ft_get_line(t_ms * ms)
{
	ft_get_head_line(ms);
	ms->line = readline(ms->head);
	if (ms->line[0] == ' ')
		ft_check_space(ms);
	if (ms->line == NULL || ft_strncmp(ms->line, "", 1) == 0)
		ft_get_line(ms);
	if (ft_strncmp(ms->line, "exit", 4) == 0)
	{
		rl_clear_history();
		free(ms->head);
		ms->head = NULL;
		free(ms->line);
		ms->line = NULL;
		exit(EXIT_SUCCESS);
	}
}

void	ft_get_head_line(t_ms *ms)
{
	char *temp;
	char *temp1;
	char *temp2;
	char *temp3;
	char *path;

	temp = ft_strjoin("\x1b[38;2;255;255;0m", getenv("USER"));
	temp1 = ft_strjoin(temp, "@");
	temp = ft_strchr(getenv("SESSION_MANAGER"), '/') + 1;
	temp2 = ft_substr(temp, 0, ((ft_strchr(temp, ':')) - temp));
	temp = ft_strjoin (temp1, temp2);
	temp3 = ft_strjoin(temp, "\x1b[0m:");
	ft_free_point(temp);
	ft_free_point(temp1);
	ft_free_point(temp2);
	temp = (char *) malloc (1024 * sizeof(char));
	getcwd(temp, 1024);
	temp1 = ft_strchr(ft_strchr(temp + 1 , '/') + 1, '/');
	if(!temp1)
		temp = ft_strdup("~");
	else
		temp = ft_strjoin("~", temp1);
	temp1 = ft_strjoin("\x1b[38;2;255;69;0m", temp);
	temp = ft_strjoin(temp1, "\x1b[0m\n% ");
	path = ft_strjoin(temp3, temp);
	ms->head = path;
}
