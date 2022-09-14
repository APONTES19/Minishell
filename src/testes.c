#include <stdlib.h> // exit
#include <stdio.h> // fget
#include <string.h>//readline
#include <unistd.h>// read
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	int	pid;
	int	fd[4];

	pid = fork();

	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1],1);
		printf("PROCESSO FILHO AGORA");
		close(fd[1]);
	}
	if (pid > 0)
	{
		wait(&pid);
		char	teste[100];
		read(fd[0],teste,100);
		printf("|%s|\n",teste);
		printf("PROCESSO PAI\n");
		close(fd[0]);
		close(fd[1]);
	}
	return(0);
}
