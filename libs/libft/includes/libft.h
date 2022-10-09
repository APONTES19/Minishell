/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 16:58:00 by lucasmar          #+#    #+#             */
/*   Updated: 2022/10/08 20:30:52 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "./libs.h"
# include <stddef.h>

int		ft_atoi(const char *str);
void	*ft_bzero(void *str, size_t n);
void	*ft_calloc(size_t num, size_t size);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_toupper(int str);
int		ft_tolower(int str);
char	*ft_strrchr( const char *str, int ch);
char	*ft_strnstr(const char *big, const char *small, size_t len);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *to, const char *from, size_t tosize);
size_t	ft_strlcat(char *to, const char *from, size_t tosize);
char	*ft_strdup(const char *str);
char	*ft_strchr( const char *str, int ch);
void	*ft_memset(void *str, int c, size_t n);
void	*ft_memmove(void *to, void *from, size_t n);
void	*ft_memcpy(void *dest, const void *str, size_t n);
int		ft_memcmp(void *str1, void *str2, size_t n);
void	*ft_memchr(const void *str, int ch, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(const char *s1, const char *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(long int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
char	*get_next_line(int fd);

#endif
