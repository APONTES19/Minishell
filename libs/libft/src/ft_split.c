/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 15:07:58 by lucasmar          #+#    #+#             */
/*   Updated: 2021/10/03 12:03:47 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		set_size(const char *str, char c);
static char		*duplicate(const char *str, int start, int end);

char	**ft_split(char const *s, char c)
{
	size_t	counter;
	size_t	p;
	int		index;
	char	**result;

	result = malloc((set_size(s, c) + 1) * sizeof(char *));
	if (!s || !result)
		return (0);
	counter = 0;
	p = 0;
	index = -1;
	while (counter <= ft_strlen(s))
	{
		if (s[counter] != c && index < 0)
			index = counter;
		else if ((s[counter] == c || counter == ft_strlen(s)) && index >= 0)
		{
			result[p++] = duplicate(s, index, counter);
			index = -1;
		}
		counter++;
	}
	result[p] = 0;
	return (result);
}

static int	set_size(const char *str, char c)
{
	int	size;
	int	apart;

	size = 0;
	apart = 0;
	while (*str)
	{
		if (*str != c && apart == 0)
		{
			apart = 1;
			size++;
		}
		else if (*str == c)
			apart = 0;
		str++;
	}
	return (size);
}

static char	*duplicate(const char *str, int start, int end)
{
	char	*duplicate;
	int		counter;

	counter = 0;
	duplicate = malloc((end - start + 1) * sizeof(char));
	while (start < end)
	{
		duplicate[counter] = str[start];
		counter++;
		start++;
	}
	duplicate[counter] = '\0';
	return (duplicate);
}
