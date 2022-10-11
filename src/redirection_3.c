/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 09:35:00 by lucasmar          #+#    #+#             */
/*   Updated: 2022/10/10 23:41:48 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_here_doc_open(char *str)
{
	char	*line;
	int		fd;

	fd = open(".hero_doc", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	while (1)
	{
		line = readline(">");
		if (ft_strncmp(line, str, ft_strlen(line)) != 0)
		{
			write (fd, line, ft_strlen(line));
			write (fd, "\n", 1);
		}
		else
		{
			free (line);
			line = NULL;
			close(fd);
			return (open(".hero_doc", O_RDONLY, 644));
		}
		free(line);
	}
	return (-1);
}
