
#include <stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include "lib/libft/libft.h"
//void	ft_copy_envp(char **envp);

int main(int argc, char **argv, char **envp)
{
	int i;
	char **temp;
	i =0;
	while(envp[i++])
	temp=(char **) malloc(i * sizeof(char **));

	ft_memcpy(temp, envp,  sizeof(char **));

	i=0;
	while(temp[i++])
		printf("%s\n", temp[i]);

}




























/*

void	ft_copy_envp(char **envp)
{
	int	i;
	char **c_envp;

	i = 0;
	while (envp[i])
		i++;
	c_envp = (char **) malloc(i * sizeof(char **));
	i = 0;
	while (envp[i])
	{
		c_envp[i] = ft_strdup(envp[i]);
		i++;
	}
	c_envp[i] = NULL;

	//c_envp = (char **) malloc((i + 2) * sizeof(char **));
	c_envp[i] = ft_strdup("NOVA=VARIAVEL");
	c_envp[i+1] = NULL;

	i = 0;
	while (c_envp[i])
	{
		printf("C_ENVP -> %s\n",c_envp[i]);
		if (envp[i] != NULL)
			printf("ORIGINAL ->ENVP - > %s\n",envp[i]);
		i++;
	}

	i = 0;
	while (c_envp[i] != NULL)
	{
		free(c_envp[i]);
		c_envp[i] =NULL;
		i++;
	}
	free(c_envp);
	c_envp = NULL;

}
*/
