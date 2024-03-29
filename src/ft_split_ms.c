/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_ms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 19:28:36 by lucasmar          #+#    #+#             */
/*   Updated: 2022/10/24 14:21:30 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int		set_size(const char *str, char c);
static char		*duplicate(const char *str, int start, int end);
static void		next_quote(const char *s, t_var *var);
static int		init_var(t_var *var, char const *s, char c);

char	**ft_split_ms(char const *s, char c)
{
	t_var	var;

	init_var(&var, s, c);
	while (var.i <= ft_strlen(s))
	{
		if (s[var.i] == '\'' || s[var.i] == '\"')
		{
			if (var.quote == 0)
				next_quote(s, &var);
			var.quote++;
			if (var.quote == var.n_q)
				var.quote = 0;
		}
		if ((s[var.i] != c || var.quote > 0) && var.index < 0)
			var.index = var.i;
		else if (((s[var.i] == c && var.quote == 0) || \
			var.i == ft_strlen(s)) && var.index >= 0)
		{
			var.result[var.p++] = duplicate(s, var.index, var.i);
			var.index = -1;
		}
		var.i++;
	}
	var.result[var.p] = NULL;
	return (var.result);
}

static int	init_var(t_var *var, char const *s, char c)
{
	ft_memset(var, 0, sizeof var);
	var->i = 0;
	var->p = 0;
	var->index = -1;
	var->quote = 0;
	var->len_s = ft_strlen(s);
	var->result = malloc((set_size(s, c) + 1) * sizeof(char *));
	if (!s || !var->result)
		return (0);
	return (1);
}

static int	set_size(const char *str, char c)
{
	int	size;
	int	apart;
	int	quote;

	quote = 0;
	size = 0;
	apart = 0;
	while (*str)
	{
		if (*str == '\'' || *str == '\"')
		{
			quote++;
			if (quote > 1)
				quote = 0 ;
		}
		if (*str != c && apart == 0)
		{
			apart = 1;
			size++;
		}
		else if (*str == c && quote == 0)
			apart = 0;
		str++;
	}
	return (size);
}

static char	*duplicate(const char *str, int start, int end)
{
	char	*duplicate;
	int		i;

	i = 0;
	duplicate = malloc((end - start + 1) * sizeof(char));
	while (start < end)
	{
		duplicate[i] = str[start];
		i++;
		start++;
	}
	duplicate[i] = '\0';
	return (duplicate);
}

static void	next_quote(const char *s, t_var *var)
{
	int		i;
	char	type;

	type = s[var->i];
	i = 1;
	var->n_q = 1;
	while (s[i])
	{
		if (s[i] == type)
		{
			var->n_q++;
			break ;
		}
		i++;
	}
}
