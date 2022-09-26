/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 19:50:22 by lucasmar          #+#    #+#             */
/*   Updated: 2022/09/26 23:40:34 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_env(t_ms *ms, char **envp)
{
	ms->i = 0;

	char *teste;

	teste = getenv("LOGNAME");
	ft_strlcpy(teste, "LUCAS", 6);

	while(envp[ms->i])
	{
		printf("%s\n", envp[ms->i]);
		ms->i++;
	}
	//exit(3);
}
