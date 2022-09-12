/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 19:50:18 by lucasmar          #+#    #+#             */
/*   Updated: 2022/09/12 22:03:12 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_echo(t_ms *ms, t_cmd *cmd)
{
	int	flag;

	flag = 0;
	ms->k = 1;
	while(cmd[0].arg_cmd[ms->k])
	{
		if (ms->quote == 1)
			ft_quote_echo(ms, cmd);
		if( ms->k == 1 && !ft_strncmp(cmd[0].arg_cmd[ms->k],"-n",2))
		{
			ms->k++;
			flag++;
		}
		if(cmd[0].arg_cmd[ms->k + 1])
			printf("%s ", cmd[0].arg_cmd[ms->k]);
		else
			printf("%s", cmd[0].arg_cmd[ms->k]);
		ms->k++;
	}
	if (flag == 0)
		printf("\n");
}

// void	ft_quote_echo(t_ms *ms, t_cmd *cmd)
// {
// 	char	*c;
// 	if(cmd[0].arg_cmd[ms->k][0] == '\'' || cmd[0].arg_cmd[ms->k][0] == '\"')
// 	{

// 		c = malloc(ft_strlen(cmd[0].arg_cmd[ms->k]) - 1);
// 		ft_strlcpy(c, cmd[0].arg_cmd[ms->k] + 1, ft_strlen(cmd[0].arg_cmd[ms->k]) -1);
// 		cmd[0].arg_cmd[ms->k] = ft_strdup(c);
// 		free(c);
// 	}
// }

void	ft_quote_echo(t_ms *ms, t_cmd *cmd)
{
	int	i;
	int	j;
	char	*c;
	char	s;

	c = malloc(ft_strlen(cmd[0].arg_cmd[ms->k])+1);
	i = 0;
	j = 0;
	while (cmd[0].arg_cmd[ms->k][i])
	{
		if(cmd[0].arg_cmd[ms->k][i] == '\'' || cmd[0].arg_cmd[ms->k][i] == '\"')
		{
			s = cmd[0].arg_cmd[ms->k][i];
			i++;
			while(cmd[0].arg_cmd[ms->k][i] != s)
			{
				c[j] = cmd[0].arg_cmd[ms->k][i];
				j++;
				i++;
			}
			i++;
		}
		else
		{
			c[j] = cmd[0].arg_cmd[ms->k][i];
			i++;
			j++;
		}
	}
	c[j] = '\0';
	cmd[0].arg_cmd[ms->k] = ft_strdup(c);
	free(c);
	c = NULL;
}
