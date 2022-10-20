/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 14:27:22 by lucasmar          #+#    #+#             */
/*   Updated: 2022/10/20 17:28:21 by lucasmar         ###   ########.fr       */
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
		if (ms->line[ms->i] == '\"')
		{
			ms->i++;
			while(ms->line[ms->i] != '\"')
			{
				if (ms->line[ms->i] == '$')
				{
					if (ft_strchr(" |", ms->line[ms->i + 1]) != NULL)
						ms->i++;
					else
					{
						ft_get_path_dollar(ms);
						ms->i = -1;
						break;
					}
				}
				ms->i++;
			}
		}
		if (ms->line[ms->i] == '$' && ms->i > 0)
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
	while(ft_strchr(" |\"\'", ms->line[ms->k]) == NULL)
		ms->k++;
	ms->end = (ms->k - ms->start);


	printf("VALOR DO FIM K = %d\n", ms->k);
	printf("VALOR DO END = %d\n", ms->end);




	temp = ft_substr(ms->line, ms->start, ms->end);
	temp2 = NULL;


	printf("TEMP = |%s|\n", temp);
	if (ft_strncmp_m(temp, "0") == 0)
	{
		ms->j = -1;
		temp2 = ft_strdup("-minishell");
	}
	if (ft_strncmp_m(temp, "PWD") == 0)
	{
		ms->j = -1;
		printf("entrei no PWD\n");
		temp2 = ft_getenv(temp);
		if (temp2 == NULL)
		{
			temp2 = (char *) malloc (1024 * sizeof(char));
			getcwd(temp2, 1024);
		}
	}
	else if (ft_strncmp_m(temp, "?") == 0)
	{
		ms->j = -1;
		temp2 = ft_itoa(g_ms.exit_s);
		ft_printf("ENTREI temp2= |%s|\n",temp2);
	}
	else if (temp2 == NULL)
	{
		temp2 = ft_getenv(temp);
		if (temp2 == NULL)
		{
			temp2 = ft_strdup("");
			printf("env null\n");
		}
	}
	else
	printf("VALOR DO ENV:|%s|\n", temp2);
	ft_change_line_dollar(ms, temp2);

	if (ms->j == -1)
		ft_free_point(temp2);
	ft_free_point(temp);
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
