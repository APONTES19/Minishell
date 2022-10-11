/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 01:31:52 by ryoshio-          #+#    #+#             */
/*   Updated: 2022/10/11 04:06:23 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	free_head(t_head *head);

void	ft_get_line(t_ms *ms)
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
	free(ms->head);
}

void	ft_get_head_line(t_ms *ms)
{
	t_head	*head;

	head = malloc(sizeof(t_head));
	head->user = ft_strdup(getenv("USER"));
	if (!head->user)
		head->user = ft_strdup("coder");
	head->temp1 = ft_three_join("\x1b[38;2;255;255;0m", head->user, "@");
	if (ft_strchr(getenv("SESSION_MANAGER"), '/'))
	{
		head->temp2 = ft_strdup(ft_strchr(getenv("SESSION_MANAGER"), '/') + 1);
			head->machine = ft_substr(head->temp2, 0,
				((ft_strchr(head->temp2, ':')) - head->temp2));
		free(head->temp2);
	}
	else
		head->machine = ft_strdup("Workspace");
	head->temp3 = ft_three_join (head->temp1, head->machine, "\x1b[0m:");
	head->pwd = ft_strdup(getenv("PWD"));
	if (ft_strrchr(head->pwd, '/'))
		head->path = ft_strjoin(ft_strrchr(head->pwd, '/'), "~");
	else
		head->path = ft_strdup ("~");
	head->temp4 = ft_three_join(head->path, "\x1b[38;2;255;69;0m", "\x1b[0m\n%");
	ms->head = ft_strjoin(head->temp3, head->temp4);
	free_head(head);
}

char	*ft_three_join(char *s1, char *s2, char *s3)
{
	char	*tmp2;
	char	*tmp1;

	tmp1 = ft_strjoin(s1, s2);
	tmp2 = ft_strjoin(tmp1, s3);
	free (tmp1);
	return (tmp2);
}

void	free_head(t_head *head)
{
	free (head->temp1);
	free (head->machine);
	free (head->user);
	free (head->temp3);
	free (head->temp4);
	free (head->path);
	free (head->pwd);
	free (head);
}
