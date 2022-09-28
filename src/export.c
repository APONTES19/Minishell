/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 19:50:27 by lucasmar          #+#    #+#             */
/*   Updated: 2022/09/28 14:54:56 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

//verificar se o segundo argumento é == null ou começa com # se for fazer declare -x

//vericar se tem o  =

//verificar se começa com alfa e ou se tem caracter não valido no nome
//export: `n#ome=l': not a valid identifier
//export: `&': not a valid identifier

//pegar palavra depois até o igual ex nome=lucas ficaria nome
//chamar a função getenv assim verifica se já existe esse nome
//se existir, ele deve retornar o ponteiro com o conteudo.
//então simplesmente subistituimos o nosso cmd depois do =;
// se não existir percorremos o enve e usamos a dup para adicionar a linha completa com o =

void	ft_export(t_ms *ms, t_cmd *cmd, char **envp)
{
	if (cmd[ms->p].arg_cmd[1] == NULL || ft_strncmp(cmd[ms->p].arg_cmd[1], "#", 1) == 0)
		ft_print_export(ms, envp);
	else if (ft_strchr(cmd[ms->p].arg_cmd[1], '=') != 0)
	{
		if (ft_isalpha(cmd[ms->p].arg_cmd[1][1]) == 0 ||
			ft_export_special(ms, cmd) == 1)
			ft_printf("error\n");
			//retorna mensagem de erro export: `&': not a valid identifier
		else
			printf("fazer o processo\n");
	}
	// não tem o igual não faz nada;
	return ;
}

int	ft_export_special(t_ms *ms, t_cmd *cmd)
{
	ms->i = 0;
	while(cmd[ms->p].arg_cmd[1][ms->i] != '\0' &&
		cmd[ms->p].arg_cmd[1][ms->i] != '=')
	{
		if (ft_isalnum(cmd[ms->p].arg_cmd[1][ms->i]) == 0 &&
			cmd[ms->p].arg_cmd[1][ms->i] != '_')
			return (1);
		ms->i++;
	}
	return (0);
}

void	ft_print_export(t_ms *ms, char **envp)
{
	int	comp;
	int	r;
	ms->i = 0;
	while(envp[ms->i])
		ms->i++;
	ms->j = 1;
	ms->k = 0;
	r =0;
	while (r <= ms->i)
	{
		while (envp[ms->j] != NULL)
		{
			comp = ft_strncmp(envp[ms->k], envp[ms->j],
				ft_strlen(envp[ms->k]));
			if (comp < 0)
				ms->j++;
			else
			{
				ms->k = ms->j;
				ms->j++;
			}
		}
		ft_printf("declare -x ");
		ft_printf("%s\n", envp[ms->k]);
		ms->k++;
	}
	printf("%d\n",ft_strncmp("lucas",0,5));
}
