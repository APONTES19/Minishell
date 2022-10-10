/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 16:02:24 by lucasmar          #+#    #+#             */
/*   Updated: 2022/10/10 20:41:04 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	line(char **bytes_read, char **result);
static void	read_doc(int fd, char **buffer, char **bytes_read, char **result);

char	*get_next_line(int fd)
{
	static char	*bytes_read = NULL;
	char		*buffer;
	char		*result;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	buffer = (char *) malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	if (read (fd, buffer, 0) < 0)
	{
		free (buffer);
		buffer = NULL;
		return (NULL);
	}
	read_doc (fd, &buffer, &bytes_read, &result);
	free (buffer);
	buffer = NULL;
	if (result == NULL)
		return (NULL);
	return (result);
}

void	read_doc(int fd, char **buffer, char **bytes_read, char **result)
{
	int		r;
	char	*temp;

	if (!*bytes_read)
	{
		*bytes_read = ft_strdup("");
	}
	r = 1;
	while (r && !ft_strrchr(*bytes_read, '\n'))
	{
		r = (read(fd,*buffer, BUFFER_SIZE));
		(*buffer)[r] = '\0';
		temp = *bytes_read;
		*bytes_read = ft_strjoin(temp, *buffer);
		free(temp);
		temp = NULL;
	}
	line(bytes_read, result);
	if (!**result)
	{
		free(*result);
		*result = NULL;
	}
}

void	line(char **bytes_read, char **result)
{
	int		counter;
	char	*temp;

	counter = 0;
	while ((*bytes_read)[counter] != '\n' && (*bytes_read)[counter])
		counter++;
	if ((*bytes_read)[counter] == '\n')
	{
		*result = ft_substr(*bytes_read, 0, counter + 1);
		temp = *bytes_read;
		*bytes_read = ft_strdup(temp + counter + 1);
		free(temp);
		temp = NULL;
	}
	else
	{
		*result = ft_strdup(*bytes_read);
		free(*bytes_read);
		*bytes_read = NULL;
	}
}
