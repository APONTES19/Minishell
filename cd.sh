#!/bin/bash

MINISHELL="./minishell"
#MINISHELL="valgrind --leak-check=full --show-leak-kinds=all --suppressions=./includes/readline.supp ./minishell"
comando=0
function next()
{
	echo
	echo "                                  Press to Next ------------->"
	read END
	echo
}

make
clear
echo
echo "███╗   ███╗██╗███╗   ██╗██╗███████╗██╗  ██╗███████╗██╗     ██╗"
echo "████╗ ████║██║████╗  ██║██║██╔════╝██║  ██║██╔════╝██║     ██║"
echo "██╔████╔██║██║██╔██╗ ██║██║███████╗███████║█████╗  ██║     ██║"
echo "██║╚██╔╝██║██║██║╚██╗██║██║╚════██║██╔══██║██╔══╝  ██║     ██║"
echo "██║ ╚═╝ ██║██║██║ ╚████║██║███████║██║  ██║███████╗███████╗███████╗"
echo "╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝╚══════╝╚═╝  ╚═╝╚══════╝╚══════╝╚══════╝"
echo
next;clear

echo   "██████╗ ██╗   ██╗██╗██╗     ██████╗ ███████╗"
echo   "██╔══██╗██║   ██║██║██║     ██╔══██╗██╔════╝"
echo   "██████╔╝██║   ██║██║██║     ██║  ██║███████╗"
echo   "██╔══██╗██║   ██║██║██║     ██║  ██║╚════██║"
echo   "██████╔╝╚██████╔╝██║███████╗██████╔╝███████║"
echo   "╚═════╝  ╚═════╝ ╚═╝╚══════╝╚═════╝ ╚══════╝"
next;clear
echo          "██████╗██████╗"
echo          "██╔════╝██╔══██╗"
echo          "██║     ██║  ██║"
echo          "██║     ██║  ██║"
echo          "╚██████╗██████╔╝"
echo          "╚═════╝╚═════╝ "


next
((comando++))
echo "🟢 $comando - Comando 'CD -' Primeiro acesso deve retornar erro"
echo "<------------------------------------------------------------->"
echo
echo 'ls' | $MINISHELL
echo
echo 'ls -la' | $MINISHELL
echo
echo 'ls' | $MINISHELL

next
((comando++))
echo "🟢 $comando - Comando 'CD -' Primeiro acesso deve retornar erro"
echo "<------------------------------------------------------------->"
echo
echo 'exit' | $MINISHELL

echo
echo "████████╗██╗  ██╗███████╗    ███████╗███╗   ██╗██████╗ "
echo "╚══██╔══╝██║  ██║██╔════╝    ██╔════╝████╗  ██║██╔══██╗"
echo "   ██║   ███████║█████╗      █████╗  ██╔██╗ ██║██║  ██║"
echo "   ██║   ██╔══██║██╔══╝      ██╔══╝  ██║╚██╗██║██║  ██║"
echo "   ██║   ██║  ██║███████╗    ███████╗██║ ╚████║██████╔╝"
echo
echo
next
clear

#ls
#lgh
#cd
#"''" funções com problema
#""
#''
#'"
#>>
#<<
#> // leak
#<
#<<<
#>>>
#>l
#<l inexistente
#<l bloqueado
#>pasta existente
#>>|
#<<|
#>|
#>|
#<>
#> lucas
#>> lucas abrir incremento
# >>
#> $PWD deve dar erro pois abre o ende atual e não arquivo
#> $PWD/arquivo  tem que criar o arquivo no caminho
#> 'lasd      sdf' o nome do arquivo deve ser igual ao digitado
#<< 'nsdkcn oijkko ' deve funcionar e ou não travar



#cd - o terminal ao rodar pela primiera vez ele não carrega o OLDPWD então deve retornar erro
#cd - se não for a primeira execução do cd retorna pra ultima pasta acessada
#cd
#cd ./42 valido e absoluto
#cd 42 valido relativo
#cd ~
# cd ~/
# cd /
#cd lfkf lkflkf lklfk varios algumentos
#cd $HOME  comando absoluto pois espande ex vira cd /home/apontes19 se não tiver path home retorna erro
#cd $HGJ expandi vazio variavel invalida ex: cd se então volta pra home se não tiver path erro
#cd $PWD retorna a pasta atual
#cd sjndj argumento invalido
#cd Makefile arquivo tem que retornar erro
#cd pastaBloqueada tem que dar erro
#cd com mais argumentos de pipe não deve executar nada ex ls | cd | mais importante gera erros normais
#cd pasta com espaço o nosso da erro seria um caminho relativo ou absoluto.
#cd remove o unset OLDPATH  o programa tem que recriar o path e reconhecer ao usar o cd - pela segunda vez apos a exlusão
#cd remova o pwd pois se não existir NÃO PODE AFETAR O FUNCIONAMENTO
#cd remove path home se não tiver o path home retorna erro
#cd ~ home absoluto mesmo removendo path home
#cd ~/ home absoluto
#echo '$HOME' "$HOME" "'$HOME'" '"$HOME"'
