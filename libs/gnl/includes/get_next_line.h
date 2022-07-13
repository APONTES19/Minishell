/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 15:14:14 by lucasmar          #+#    #+#             */
/*   Updated: 2022/03/07 12:12:09 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

char	*get_next_line(int fd);
void	read_doc(int fd, char **buffer, char **bytes_read, char **result);
void	line(char **bytes_read, char **result);

#endif
