/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 14:27:22 by lucasmar          #+#    #+#             */
/*   Updated: 2022/10/16 17:57:42 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_set_line_dollar(t_ms *ms)
{
	ms->i = 0;
	while(ms->line[ms->i])
	{

		if (ms->line[ms->i] == '\'')
			ft_redirection_aux(ms, '\'');
		if (ms->line[ms->i] == '$')
		{
			if (ft_strchr(" |", ms->line[ms->i + 1]) != NULL)
				ms->i++;
			else
			{
				ft_get_path_dollar(ms);
				ms->i = -1;
			}
		}
		ms->i++;
	}
	return(0);
}

void	ft_get_path_dollar(t_ms *ms)
{
	char	*temp;
	char	*temp2;
	ms->start = ms->i+1;
	ms->k = ms->start;
	while(ft_strchr(" |\"", ms->line[ms->k]) == NULL)
		ms->k++;
	ms->end = (ms->k - ms->start);


	printf("VALOR DO FIM K = %d\n", ms->k);
	printf("VALOR DO END = %d\n", ms->end);




	temp = ft_substr(ms->line, ms->start, ms->end);



	printf("TEMP = |%s|\n", temp);



	temp2 = ft_getenv(temp);
	ft_free_point(temp);
	if(temp2 == NULL)
	{
		temp2 = ft_strdup("");




		printf("env null\n");


	}
	else
		printf("VALOR DO ENV:|%s|\n", temp2);


	ft_change_line_dollar(ms, temp2);
}

void	ft_change_line_dollar(t_ms *ms, char *dollar)
{
	char	*temp;
	char	*temp1;
	char 	*temp2;

	temp = ft_substr(ms->line, 0,(ms->i));



	printf("temp: }%s{\n", temp);


	if (ms->line[ms->k] != '\0')
	{
		temp1 = ft_substr(ms->line, ms->k, ft_strlen(&ms->line[ms->k]));


		printf("temp1: }%s{\n", temp1);


		ft_free_point(ms->line);
		temp2 = ft_strjoin(temp, dollar);


		printf("temp2: }%s{\n", temp2);



		ms->line = ft_strjoin(temp2, temp1);


		printf("LINE }%s{\n", ms->line);


		ft_free_point(temp1);
		ft_free_point(temp2);
	}
	else
	{
		ft_free_point(ms->line);
		ms->line = ft_strjoin(temp, dollar);

		printf("LINE }%s{\n", ms->line);
	}
	ft_free_point(temp);
}
