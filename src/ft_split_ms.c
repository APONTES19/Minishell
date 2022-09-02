/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_ms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 15:07:58 by lucasmar          #+#    #+#             */
/*   Updated: 2022/09/02 15:06:18 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int		set_size(const char *str, char c);
static char		*duplicate(const char *str, int start, int end);
static int		next_quote(const char *s, char **result);

char	**ft_split_ms(char const *s, char c)
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
		printf("Valor fora da \' P:%zu\n",p);
		if ((s[counter] == '\'' || s[counter] == '\"') && c == ' ')
		{
			counter += next_quote(&s[counter], &result[p++]);
			printf("Valor dentro da \' P:%zu\n",p);
		}
		if (s[counter] != c && index < 0)
			index = counter;
		else if (((s[counter] == c &&)|| counter == ft_strlen(s)) && index >= 0)
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
	char	type;

	size = 0;
	apart = 0;
	while (*str)
	{
		if (*str == '\'' || *str == '\"')
		{
			str++;
			type = '\'';
			if (*str == '\"')
				type = '\"';
			while(*str != type)
				str++;
			str++;
			apart = 1;
		}
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

static int	next_quote(const char *s, char **result)
{
	int	counter;
	char	type;

	counter = 1;
	type = '\'';
	if (s[counter] == '\"')
		type = '\"';
	while(s[counter] != type)
	{
		counter++;
	}
	*result = duplicate(s, 0, (counter+1));
	return (counter+1);
}
