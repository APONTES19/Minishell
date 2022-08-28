/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 23:32:54 by ryoshio-          #+#    #+#             */
/*   Updated: 2022/08/27 08:18:17 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int counter_parse(char *line)
{
	int	counter;
	int i;

	i = 0;
	counter = 1;
	while(line[i] == ' ' && line [i])
		i++;
	while(line[i])
	{
		while(line[i] == ' ' && line [i])
		{
			if(line[i] == ' ' && (line[i+1] != ' ' && line[i+1]!= '\0'  ) )
				counter ++;
			if(line[i])	
				i ++;
			else
				break;
				
		}
		if(line[i] == '\"')
		{
			counter ++;
			i+= ft_strlen(&line[i+1]) - ft_strlen(ft_strchr(&line[i+1], '\"'))+1;	
		}
		else if( line[i] == '\'')
		{
			counter ++;
			i += ft_strlen(&line[i]) - ft_strlen(ft_strchr(&line[i+1], '\''));	
			
		}
		if(line[i])	
			i ++;
		else
			break;
		
	}
	return(counter);
	
}

