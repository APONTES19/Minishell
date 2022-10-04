/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 20:49:01 by ryoshio-          #+#    #+#             */
/*   Updated: 2022/10/04 17:32:53 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/minishell.h"


void	ft_error(int number, t_ms *ms)
{
	if (number == 0)
		ft_printf("Invalid arguments\n");
	if (number == 1)
		ft_printf("quote is missing\n");
	if (number == 2)
		ft_printf("invalid character: %c\n", ms->line[ms->i]);
	if (number == 3)
		ft_printf("syntax error near "
			"unexpected token `%c'\n", ms->line[ms->i]);
	if (number == 4)
		ft_printf("syntax error near "
			"unexpected token `%c%c'\n", ms->line[ms->i], ms->line[ms->i + 1]);
	if (number == 5)
		ft_printf("malloc error\n");
	if (number == 6)
		ft_printf("envp error\n");
	if (number == 8)
		ft_printf("split error\n");
	if (number == 9)
		ft_printf("pipe error\n");
	if (number == 12)
		ft_printf("Erro no PID arguments\n");
	if (number == 13)
	{
		ft_putstr_fd("Erro na Execução do comando com a execve\n",2);
		exit(3);
	}
	if (number == 14)
		ft_printf("%s: No such file or directory\n",ms->path_infile);
	if (number == 15)
		ft_printf("%s:  Permission denied\n",ms->path_outfile);
	if (number == 16)
		ft_putstr_fd("cd: too many arguments\n", 2);
	if (number == 17)
		ft_putstr_fd("cd: OLDPWD not set\n", 2);
	if (number == 19)
		ft_putstr_fd("Value Envp = NUll\n", 2);
}

void	ft_error_2(int number, t_cmd *cmd, t_ms *ms)
{
	if (number == 07)
	{
		ft_printf("%s: command not found\n", cmd[0].arg_cmd[0]);
		if (ms->p == (ms->n_pipe -1))
			ft_base_free(ms, cmd);
	}
	if (number == 18)
	{
		dup2(1, 2);
		printf ("env: ‘%s’: we don't configure for arguments\n",
			cmd[ms->p].arg_cmd[1]);
	}
}

void	ft_base_free(t_ms *ms, t_cmd *cmd)
{
	int i;
	int j;

	j = 0;
	while(j < ms->n_pipe)
	{
		if(ms->n_pipe > 1)
		{
			free(cmd[0].base_list_cmd[j]);
			cmd[0].base_list_cmd[j] = NULL;
		}
	    i = 0;
	    while(cmd[j].arg_cmd[i])
	    {
	        free(cmd[j].arg_cmd[i]);
			cmd[j].arg_cmd[i] = NULL;
	        i ++;
	    }
	    free(cmd[j].arg_cmd);
	    cmd[j].arg_cmd =NULL;
	    j ++;
	}
	if(ms->n_pipe > 1)
		free(cmd[0].base_list_cmd);
	free(cmd);
}

void	ft_exit(t_ms *ms, t_cmd *cmd)
{
	ft_base_free(ms, cmd);
	free (ms->path_cmd);
	ms->path_cmd = NULL;
	if (ms->n_pipe > 1)
		{
			ms->i = 0;
			while(ms->fd[ms->i])
			{
				free(&ms->fd[ms->i]);
				ms->i++;
			}
		}
	free(ms->oldpwd);
	ms->oldpwd = NULL;
}

void	ft_cd_error(t_ms *ms, t_cmd *cmd)
{
	ft_putstr_fd("cd: ", 2);
	ft_putstr_fd(cmd[ms->p].arg_cmd[1], 2);
	if (access(cmd[ms->p].arg_cmd[1], F_OK) == 0)
		ft_putstr_fd(": Not a directory\n", 2);
	else
		ft_putstr_fd(": No such file or directory\n", 2);
}


void	ft_free_two_point(char **str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
}
