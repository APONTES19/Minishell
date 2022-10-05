# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    echo.c                                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/04 22:28:00 by lucasmar          #+#    #+#              #
#    Updated: 2022/10/04 22:28:19 by lucasmar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#include "../includes/minishell.h"

void	ft_echo(t_ms *ms, t_cmd *cmd)
{
	int	flag;

	flag = 0;
	ms->k = 1;
	if (cmd[ms->p].arg_cmd[1][0] == '$')
		ft_print_var(ms, cmd);
	else if (ms->k > 1)
	{
		while (cmd[ms->p].arg_cmd[ms->k])
		{
			if (ms->quote == 1)
				ft_quote_echo(ms, cmd);
			if( ms->k == 1 && !ft_strncmp(cmd[ms->p].arg_cmd[ms->k],"-n",2))
			{
				ms->k++;
				flag++;
			}
			if(cmd[ms->p].arg_cmd[ms->k + 1])
				ft_printf("%s ", cmd[ms->p].arg_cmd[ms->k]);
			else
				ft_printf("%s", cmd[ms->p].arg_cmd[ms->k]);
			ms->k++;
		}
	}
	if (flag == 0)
		ft_printf("\n");
	exit(3);
}

void	ft_quote_echo(t_ms *ms, t_cmd *cmd)
{
	int	i;
	int	j;
	char	*c;
	char	s;

	c = malloc(ft_strlen(cmd[ms->p].arg_cmd[ms->k])+1);
	i = 0;
	j = 0;
	while (cmd[ms->p].arg_cmd[ms->k][i])
	{
		if(cmd[ms->p].arg_cmd[ms->k][i] == '\'' || cmd[ms->p].arg_cmd[ms->k][i] == '\"')
		{
			s = cmd[ms->p].arg_cmd[ms->k][i];
			i++;
			while(cmd[ms->p].arg_cmd[ms->k][i] != s)
			{
				c[j] = cmd[ms->p].arg_cmd[ms->k][i];
				j++;
				i++;
			}
			i++;
		}
		else
		{
			c[j] = cmd[ms->p].arg_cmd[ms->k][i];
			i++;
			j++;
		}
	}
	c[j] = '\0';
	cmd[ms->p].arg_cmd[ms->k] = ft_strdup(c);
	free(c);
	c = NULL;
}

void	ft_print_var(t_ms *ms, t_cmd *cmd)
{
	char	*s;

	s = ft_getenv(cmd[ms->p].arg_cmd[1]+1);
	if (s != NULL)
		ft_printf("%s\n", s);
	ft_printf("\n");
}
