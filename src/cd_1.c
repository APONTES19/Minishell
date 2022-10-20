/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 19:50:11 by lucasmar          #+#    #+#             */
/*   Updated: 2022/10/20 15:17:26 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

//cd - o terminal ao rodar pela primiera vez ele não carrega o OLDPWD então deve retornar erro
//cd - se não for a primeira execução do cd retorna pra ultima pasta acessada
//cd
//cd ./42 valido e absoluto
//cd 42 valido relativo
//cd ~
// cd ~/
// cd /
//cd $HOME  comando absoluto pois espande ex vira cd /home/apontes19 se não tiver path home retorna erro
//cd $HGJ expandi vazio variavel invalida ex: cd se então volta pra home se não tiver path erro
//cd $PWD retorna a pasta atual
//cd sjndj argumento invalido
//cd Makefile arquivo tem que retornar erro
//cd pastaBloqueada tem que dar erro
//cd com mais argumentos de pipe não deve executar nada ex ls | cd | mais importante gera erros normais
//cd pasta com espaço o nosso da erro seria um caminho relativo ou absoluto.
//cd remove o unset OLDPATH  o programa tem que recriar o path e reconhecer ao usar o cd - pela segunda vez apos a exlusão
//cd remova o pwd pois se não existir NÃO PODE AFETAR O FUNCIONAMENTO
//cd remove path home se não tiver o path home retorna erro
//cd ~ home absoluto mesmo removendo path home
//cd ~/ home absoluto
//

void	ft_cd(t_ms *ms, t_cmd *cmd)
{
	g_ms.exit_s = 0;
	ms->k = 0;
	if (cmd[ms->p].arg_cmd[1] != NULL && cmd[ms->p].arg_cmd[2] != NULL)
		ft_error(14, ms, cmd, cmd[ms->p].arg_cmd[1]);
	else if (ft_cd_home(ms ,cmd) == 0)
		ft_change_cd(ms, "HOME");
	else if (ft_strncmp_m(cmd[ms->p].arg_cmd[1], "-") == 0)
		ft_minus_cd(ms);
	else if (access(cmd[ms->p].arg_cmd[1], X_OK) == 0
		&& ft_valid_dir(cmd[ms->p].arg_cmd[1]) == 1)
		ft_change_cd(ms, cmd[ms->p].arg_cmd[1]);
	else
		ft_error(21, ms, cmd, cmd[ms->p].arg_cmd[1]);
	return ;
}

int	ft_cd_home(t_ms *ms, t_cmd *cmd)
{
	ms->k = 0;
	if (cmd[ms->p].arg_cmd[1] == NULL)
		return(0);
	if(ft_strncmp_m(cmd[ms->p].arg_cmd[1], "~") == 0)
	{
		ms->k = -890;
		return (0);
	}
	if(ft_strncmp_m(cmd[ms->p].arg_cmd[1], "~/") == 0)
	{
		ms->k = -890;
		return (0);
	}
	return (1);
}

void	ft_change_cd(t_ms *ms, char *change)
{
	char	*temp;
	char	*temp2;

	if (ms->n_pipe == 1)
	{
		ms->oldpwd = (char *) malloc(1024 * sizeof(char));
		getcwd(ms->oldpwd, 1024);
		temp = ft_getenv("OLDPWD");
		if (temp == NULL)
		{
			temp = ft_strjoin ("OLDPWD=", ms->oldpwd);
			ft_add_envp(temp);
			ft_free_point(temp);
		}
		temp2 = ft_strjoin ("OLDPWD=", ms->oldpwd);
		ft_change_envp("OLDPWD", temp2);
		if (ft_strncmp_m(change, "HOME") == 0)
			ft_aux_cd_change(ms, change);
		else
			chdir(change);
		ft_update_pwd(ms);
		ft_free_point(ms->oldpwd);
		ft_free_point(temp2);
		g_ms.cd++;
	}
}

int	ft_minus_cd(t_ms *ms)
{
	char	*temp;
	char	*temp2;
	char	*temp3;

	temp = ft_getenv("OLDPWD");
	if (temp == NULL)
	{
		ft_error(15, ms, NULL, NULL);
		return (1);
	}
	else
	{
		temp3 = ft_strdup(temp);
		ms->temp = (char *) malloc (1024 * sizeof(char));
		getcwd(ms->oldpwd, 1024);
		temp2 = ft_strjoin("OLDPWD=", ms->temp);
		ft_change_envp("OLDPWD", temp2);
		ft_printf("%s\n", temp3);
		chdir(temp3);
		ft_update_pwd(ms);
		ft_free_point(temp2);
		ft_free_point(temp3);
		ft_free_point(ms->temp);
	}
	return (0);
}

