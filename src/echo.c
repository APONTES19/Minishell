/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 22:30:07 by lucasmar          #+#    #+#             */
/*   Updated: 2022/10/14 17:32:01 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	echo_while(t_ms *ms, t_cmd *cmd);

void	ft_echo(t_ms *ms, t_cmd *cmd)
{
	ms->k = 1;
	if (cmd[ms->p].arg_cmd[1] == NULL)
		ft_printf("\n");
	else if (cmd[ms->p].arg_cmd[1][0] == '$' &&
		 cmd[ms->p].arg_cmd[1][1] != '\0')
		ft_print_var(ms, cmd);
	else
		echo_while (ms, cmd);
	return ;
}

void	ft_quote_echo(t_ms *ms, t_cmd *cmd)
{
	int		i;
	int		j;
	char	*c;
	char	s;

	c = malloc(ft_strlen(cmd[ms->p].arg_cmd[ms->k]) + 1);
	i = 0;
	j = 0;
	while (cmd[ms->p].arg_cmd[ms->k][i])
	{
		if (cmd[ms->p].arg_cmd[ms->k][i] == '\'' ||
			cmd[ms->p].arg_cmd[ms->k][i] == '\"')
		{
			s = cmd[ms->p].arg_cmd[ms->k][i ++];
			while (cmd[ms->p].arg_cmd[ms->k][i] != s)
				c[j++] = cmd[ms->p].arg_cmd[ms->k][i++];
			i++;
		}
		else
			c[j++] = cmd[ms->p].arg_cmd[ms->k][i++];
	}
	c[j] = '\0';
	cmd[ms->p].arg_cmd[ms->k] = ft_strdup(c);
	free(c);
	c = NULL;
}

void	ft_print_var(t_ms *ms, t_cmd *cmd)
{
	char	*s;

	s = ft_getenv(cmd[ms->p].arg_cmd[1] + 1);
	if (ft_strncmp(cmd[ms->p].arg_cmd[1], "$?",
		 ft_strlen(cmd[ms->p].arg_cmd[1])) == 0)
		ft_printf("%d\n", g_ms.exit_s);
	else if (s != NULL)
		ft_printf("%s\n", s);
	else
		ft_printf("\n");
}

static void	echo_while(t_ms *ms, t_cmd *cmd)
{
	int	flag;

	flag = 0;
	while (cmd[ms->p].arg_cmd[ms->k])
	{
		if (ms->quote == 1)
			ft_quote_echo(ms, cmd);
		if (ms->k == 1 && !ft_strncmp(cmd[ms->p].arg_cmd[ms->k], "-n", 2))
		{
			ms->k++;
			if (cmd[ms->p].arg_cmd[ms->k] == NULL)
				return ;
			flag++;
		}
		if (cmd[ms->p].arg_cmd[ms->k + 1])
			ft_printf("%s ", cmd[ms->p].arg_cmd[ms->k]);
		else
			ft_printf("%s", cmd[ms->p].arg_cmd[ms->k]);
		ms->k++;
	}
	if (flag == 0)
		ft_printf("\n");
}
