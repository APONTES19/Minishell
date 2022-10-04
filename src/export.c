/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 19:50:27 by lucasmar          #+#    #+#             */
/*   Updated: 2022/10/04 17:48:01 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	*sort_emvp(void);
void initializing_sort(t_sort *sort);


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

void	ft_export(t_ms *ms, t_cmd *cmd)
{
	ft_teste_add();
	if (cmd[ms->p].arg_cmd[1] == NULL || ft_strncmp(cmd[ms->p].arg_cmd[1], "#", 1) == 0)
		ft_print_export( );
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




void	ft_print_export(void)
{
	int	*sort;
	int i;

	sort= sort_emvp();
	i = 0;
	while(g_ms.envp[i])
	{
		ft_printf("declare -x ");
		ft_printf("%s\n", g_ms.envp[sort[i]]);
		i ++;
	}
	free(sort);

}

int	*sort_emvp(void)
{
	t_sort sort;

	initializing_sort(&sort);
	sort.i = 0;
	while (g_ms.envp[sort.i])
	{
		sort.k=0;
		while(sort.catch[sort.k]==0 && g_ms.envp[sort.k])
			sort.k++;
		sort.j = -1;
		while(g_ms.envp[++sort.j])
			if(ft_strncmp(g_ms.envp[sort.k], g_ms.envp[sort.j], ft_strlen(g_ms.envp[sort.k])) > 0 && sort.catch[sort.j] == 1)
				sort.k = sort.j;
		sort.sort[sort.i] = sort.k;
		sort.catch[sort.k] = 0;
		sort.i ++;
	}
	free(sort.catch);
	return(sort.sort);
}

void initializing_sort(t_sort *sort)
{
	sort->i = 0;
	while(g_ms.envp[sort->i])
		sort->i++;
	sort->sort = malloc(sizeof(int) * sort->i);
	sort->catch = malloc(sizeof(int) * sort->i);
	sort->i = 0;
	while(g_ms.envp[sort->i])
	{
		sort->catch[sort->i] = 1;
		sort->i ++;
	}
}

void	ft_teste_add()
{
	printf ("\n\n\n\n\n\n______________inicio\n\n");
	ft_add_envp("LUCAS->>>>=MARTINS_APONTES!!!!!!!!");
	printf ("\n\n\n\n\n\n______________fim\n\n");

}
