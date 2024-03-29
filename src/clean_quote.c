/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 23:28:53 by lucasmar          #+#    #+#             */
/*   Updated: 2022/10/22 15:19:40 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_clean_quote(t_ms *ms, t_cmd *cmd)
{
	char	*temp;

	ms->i = 0;
	while (ms->i != ms->n_pipe)
	{
		ms->j = 0;
		while (cmd[ms->i].arg_cmd[ms->j])
		{
			temp = ft_strdup(cmd[ms->i].arg_cmd[ms->j]);
			ft_free_point(cmd[ms->i].arg_cmd[ms->j]);
			ft_clean_quote_aux_1(ms, &temp);
			cmd[ms->i].arg_cmd[ms->j] = (char *) malloc (ms->k * sizeof(char));
			ft_clean_quote_aux_2(ms, cmd, &temp, '\"');
			ft_free_point(temp);
			ms->j++;
		}
		ms->i++;
	}
}

void	ft_clean_quote_aux_1(t_ms *ms, char **temp)
{
	char	type;

	ms->k = 0;
	while ((*temp)[ms->k])
	{
		if ((*temp)[ms->k] == '\'' || (*temp)[ms->k] == '\"')
		{
			if ((*temp)[ms->k] == '\'')
				type = '\'';
			else
				type = '\"';
			ms->k++;
			while ((*temp)[ms->k] != type)
				ms->k++;
		}
		ms->k++;
	}
	ms->k++;
}

void	ft_clean_quote_aux_2(t_ms *ms, t_cmd *cmd, char **temp, char type)
{
	ms->k = 0;
	ms->p = 0;
	while ((*temp)[ms->k])
	{
		if ((*temp)[ms->k] == '\'' || (*temp)[ms->k] == '\"')
		{
			if ((*temp)[ms->k] == '\'')
				type = '\'';
			else
				type = '\"';
			ms->k++;
			while ((*temp)[ms->k] != type)
			{
				cmd[ms->i].arg_cmd[ms->j][ms->p] = (*temp)[ms->k];
				ms->p++;
				ms->k++;
			}
			ms->k++;
		}
		if ((*temp)[ms->k] && ft_strchr("\'\"", (*temp)[ms->k]) == NULL)
			cmd[ms->i].arg_cmd[ms->j][ms->p++] = (*temp)[ms->k++];
	}
	cmd[ms->i].arg_cmd[ms->j][ms->p] = '\0';
}
