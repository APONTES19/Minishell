#include "../includes/minishell.h"

void	teste();

int main(void)
{
	int fd;
	int out;
	int in;
	int pip[2];



	out = dup(1);
	in = dup(0);
	fd = open("lucas",O_WRONLY | O_CREAT | O_TRUNC, 0644);

	pipe(pip);

	//muda a saida
	dup2(pip[1], 1);

	//execução
	printf("passei1\n");

	//muda a entrada para a padrão;
	dup2(pip[0],0);

	//muda o pipe salvo da saida padrão
	dup2(out, 1);

	//fecha os pipe
	close(pip[0]);
	close(pip[1]);

	//volta o padrão de sistema
	dup2(out, 1);
	dup2(in, 0);

	teste();
	return(0);
}

void teste()
{

	printf("passei2\n");
}
