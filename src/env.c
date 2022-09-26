/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 19:50:22 by lucasmar          #+#    #+#             */
/*   Updated: 2022/09/26 23:22:38 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_env(t_ms *ms)
{
	char *teste;

	//teste = malloc (1024);
	teste = getenv("LOGNAME");
	ft_strcpy(teste, "LUCAS", 5);
}
