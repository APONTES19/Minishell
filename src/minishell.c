/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 18:03:23 by lucasmar          #+#    #+#             */
/*   Updated: 2022/09/28 15:41:00 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_ms	g_ms;
void	ft_get_head_line(t_ms *ms);
int main(int argc, char **argv, char **envp)
{
	t_ms	ms;
	t_cmd	cmd;

	(void )argv;
	if(argc == 1)
	{
		if (envp == NULL)
			ft_error(06, &ms);
		ft_memset(&ms, '0', sizeof(ms));
		ft_memset(&cmd, '0', sizeof(cmd));
		g_ms.cd = 0;
		ft_copy_envp(&ms, envp);
		while(1)
		{
			ft_get_line(&ms);
			add_history(ms.line);
			if (ft_check_input(&ms) != 0)
				ft_command_split(&ms, &cmd, envp);
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
	char *path;

	temp = (char *) malloc (1024 * sizeof(char));
	getcwd(temp, 1024);
	temp1 = ft_strchr(ft_strchr(temp + 1 , '/') + 1, '/');
	if(!temp1)
		path = ft_strdup("$ ");
	else
		path= ft_strjoin(temp1, "$ ");


	temp =ft_strjoin(getenv("USER"),"@" );
	temp1 =ft_strjoin(temp, getenv("LOGNAME"));

	temp = ft_strjoin(temp1,":~" );
	ms->head = ft_strjoin(temp, path);
	free(temp);
	free(temp1);
// printf ("\x1b[38;2;32;209;139m a menssagem \x1b[0m\n")
}
