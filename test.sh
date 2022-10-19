#!/bin/sh

MINISHELL="./minishell"
# MINISHELL="valgrind -q --leak-check=full --track-fds=yes ./minishell"
# MINISHELL="./minishell"

make
clear

enterkey()
{
	echo -n "\t\t\t\t\t--> Next ";
	read anything;
}


echo TESTE MINISHELL
echo "=============================================================="
echo TESTE BUILDS
echo "=============================================================="
echo "=============================================================="
echo ECHO
echo "=============================================================="
echo 'echo Hello\necho $?\nexit' | $MINISHELL
echo "=============================================================="
echo 'echo -n Hello\necho $?\nexit' | $MINISHELL
echo "=============================================================="
echo 'echo -n Hello -n \necho $?\nexit' | $MINISHELL
echo "=============================================================="


enterkey()
{
	echo -n "\t\t\t\t\t--> Next ";
	read anything;
}











echo "=============================================================="
echo '\nexit' | $MINISHELL
echo "=============================================================="
echo '         \nexit' | $MINISHELL
echo "=============================================================="
echo 'ls\necho $?\nexit' | $MINISHELL
echo "=============================================================="
echo 'ls srrc\necho $?\nexit' | $MINISHELL
echo "=============================================================="
echo '/bin/ls -la\necho $?\nexit' | $MINISHELL
echo "=============================================================="
echo 'ls *\necho $?\nexit' | $MINISHELL
echo "=============================================================="
echo "=============================================================="
echo 'exit 0\necho $?' | $MINISHELL
echo $?
echo "=============================================================="
echo 'exit 1\necho $?' | $MINISHELL
echo $?
echo "=============================================================="
echo 'exit 33\necho $?' | $MINISHELL
echo $?
echo "=============================================================="
echo 'exit exit exit' | $MINISHELL
echo $?
echo "=============================================================="
echo 'exit exit 33' | $MINISHELL
echo $?
echo "=============================================================="
echo 'exit 2 exit\necho $?\nexit' | $MINISHELL
echo "=============================================================="
echo 'exit 2 2\necho $?\nexit' | $MINISHELL
echo "=============================================================="
echo '/usr/bin/tr -x\necho $?\nexit' | $MINISHELL
echo "=============================================================="
echo '/usr/bin/tr "-x b"\necho $?\nexit' | $MINISHELL
echo "=============================================================="
echo '/bin/ls srrc\necho $?\nexit' | $MINISHELL
echo "=============================================================="
echo '/bin/lss srrc\necho $?\nexit' | $MINISHELL
echo "=============================================================="
echo 'echoo\necho $?\nexit' | $MINISHELL
echo "=============================================================="
echo 'lss\necho $?\nexit' | $MINISHELL
echo "=============================================================="
echo 'pwdd\necho $?\nexit' | $MINISHELL
echo "=============================================================="
echo 'echo aaaaaaaaaaaaaaaaa > out\ncat out\necho $?\nrm -rf out\nexit' | $MINISHELL
echo "=============================================================="
echo 'echo aaaaaaaaaaaaaaaaa > out\ncat out | cat out > out\ncat out\necho $?\nrm -rf out\nexit' | $MINISHELL
echo "=============================================================="
echo 'echo aaaaaaaaaaaaaaaaa > out\necho "cat out | cat out > out"\necho $?\nrm -rf out\nexit' | $MINISHELL
echo "=============================================================="
echo "echo '\$USER'\\nexit" | $MINISHELL
echo "=============================================================="
echo "echo 'abacate'\nexit" | $MINISHELL
echo "=============================================================="
echo 'export TESTE1=batata\necho $TESTE1\nunset TESTE1\necho $TESTE1\nexit' | $MINISHELL
echo "=============================================================="
echo 'cd\npwd\nexit' | $MINISHELL
echo "=============================================================="
echo 'cd .\npwd\nexit' | $MINISHELL
echo "=============================================================="
echo 'cd ~\npwd\nexit' | $MINISHELL
echo "=============================================================="
echo 'cd ~~\npwd\nexit' | $MINISHELL
echo "=============================================================="
echo 'cd nope~\npwd\nexit' | $MINISHELL
echo "=============================================================="
echo 'cd ~nope\npwd\nexit' | $MINISHELL
echo "=============================================================="
echo 'cd ~/\npwd\nexit' | $MINISHELL
echo "=============================================================="
echo 'cd ..\npwd\nexit' | $MINISHELL
echo "=============================================================="
echo 'cd ..\ncd ..\npwd\nexit' | $MINISHELL
echo "=============================================================="
echo 'cd ../..\npwd\nexit' | $MINISHELL
echo "=============================================================="
echo 'cd /\npwd\nexit' | $MINISHELL
echo "=============================================================="
echo 'cd \npwd\nexit' | $MINISHELL
echo "=============================================================="
echo 'cd not_exist\necho $?\nexit' | $MINISHELL
echo "=============================================================="
echo 'unset HOME\ncd\necho $?\npwd\nexit' | $MINISHELL
echo "=============================================================="
echo 'unset HOME\ncd \necho $?\npwd\nexit' | $MINISHELL
echo "=============================================================="
echo 'unset HOME\ncd ~\necho $?\npwd\nexit' | $MINISHELL
echo "=============================================================="
echo 'unset HOME\ncd $HOME\necho $?\npwd\nexit' | $MINISHELL
echo "=============================================================="
echo 'echo aaaaa | wc -l\necho $?\nexit' | $MINISHELL
echo "=============================================================="
echo 'unset PATH\nls\nwc\nclear\nexport PATH=/usr/bin\nls\nexit' | $MINISHELL
echo "=============================================================="
echo 'unset PATH\nexport PATH=/usr/bin:/bin\nenv | grep PATH\nexit' | $MINISHELL
echo "=============================================================="
echo 'echo aaaaaaaaaaa > out1 > out2 > out3\ncat out1\ncat out2\ncat out3\nrm -rf out1 out2 out3\nexit' | $MINISHELL
echo "=============================================================="
echo 'echo aaaaaaaaaaa>out1>out2>out3\ncat out1\ncat out2\ncat out3\nrm -rf out1 out2 out3\nexit' | $MINISHELL
echo "=============================================================="
echo 'echo bbbbbbbbbbb>out1>out2>out3\ncat out1 && cat out2 && cat out3\nrm -rf out1 out2 out3\nexit' | $MINISHELL
echo "=============================================================="
echo 'echo ccccccccccc>out1>out2>out3\necho ddddddddddd >> out3\ncat out1 && cat out2 && cat out3\nrm -rf out1 out2 out3\nexit' | $MINISHELL
echo "=============================================================="
echo 'echo ccccccccccc>out1>out2>out3\necho fffffffffff >> out4\ncat out1 && cat out2 && cat out3 && cat out4\nrm -rf out1 out2 out3 out4\nexit' | $MINISHELL
echo "=============================================================="
echo 'echo aaaaaaaaaaa > out1\necho bbbbbbbbbbb > out2\necho ccccccccccc > out3\necho ddddddddddd > out4\necho fffffffffff >> out4\ncat out1 && cat out2 && cat out3 && cat out4\nrm -rf out1 out2 out3 out4\nexit' | $MINISHELL
echo "=============================================================="
echo 'echo aaaaaaaaaaa > out1\necho bbbbbbbbbbb > out2\necho ccccccccccc > out3\ncat < out1 < out2 < out3\nrm -rf out1 out2 out3\nexit' | $MINISHELL
echo "=============================================================="
echo 'echo aaaaaaaaaaa>out1\necho bbbbbbbbbbb > out2\necho ccccccccccc > out3\ncat <out1<out2<out3\nrm -rf out1 out2 out3\nexit' | $MINISHELL
echo "=============================================================="
echo 'echo aaaaaaaaaaa > out1\necho bbbbbbbbbbb > out2\necho ccccccccccc > out3\ncat <out1<out2<out3\nrm -rf out1 out2 out3\nexit' | $MINISHELL
echo "=============================================================="
echo 'echo aaaaaaaaaaa > out1\ncat < out1 > out2\ncat < out2\nrm -rf out1 out2\nexit' | $MINISHELL
echo "=============================================================="
echo '<< OUT\nexit' | $MINISHELL
echo "=============================================================="
echo '<<OUT\nexit' | $MINISHELL
echo "=============================================================="
echo 'echo aaaaaaaaaaa > out1\necho bbbbbbbbbbb > out2\necho ccccccccccc > out3\ncat <not_exist<out2<out3\necho $?\nrm -rf out1 out2 out3\nexit' | $MINISHELL
echo "=============================================================="
echo 'echo aaaaaaaaaaa > out1\necho bbbbbbbbbbb > out2\necho ccccccccccc > out3\ncat <out1<not_exist<out3\necho $?\nrm -rf out1 out2 out3\nexit' | $MINISHELL
echo "=============================================================="
echo 'echo aaaaaaaaaaa > out1\necho bbbbbbbbbbb > out2\necho ccccccccccc > out3\ncat <out1<out2<not_exist\necho $?\nrm -rf out1 out2 out3\nexit' | $MINISHELL
echo "=============================================================="
echo 'echo aaaaaaaaaaa > out1\necho bbbbbbbbbbb > out2\necho ccccccccccc > out3\ncat < out1 < out2 < not_exist\necho $?\nrm -rf out1 out2 out3\nexit' | $MINISHELL
echo "=============================================================="
echo 'echo aaaaaaaaaaa > out1\n< out1 tr a b | tr b c | tr c d\necho $?\nrm -rf out1\nexit' | $MINISHELL
echo "=============================================================="
echo 'ping -c1 8.8.8.8 > out1\ncat out1 | grep ms | more\necho $?\nrm -rf out1\nexit' | $MINISHELL
echo "=============================================================="
echo 'cat | cat | ls\necho $?\nexit' | $MINISHELL
echo "=============================================================="
echo 'export USER=potato\necho $?\necho $USER\necho $?\nexit' | $MINISHELL
echo "=============================================================="
echo 'echo $USER\necho $?\nexit' | $MINISHELL
echo "=============================================================="
echo 'echo "$USER"\necho $?\nexit' | $MINISHELL
echo "=============================================================="
echo "echo "\"\'\$USER\'"\"\necho $?\nexit" | $MINISHELL
echo "=============================================================="
echo "echo "\'\"\$USER\"\'"\necho $?\nexit" | $MINISHELL
echo "=============================================================="
echo 'echo $USER $ $USER $\necho $?\nexit' | $MINISHELL
echo "=============================================================="
echo 'echo $ $USER $ $USER\necho $?\nexit' | $MINISHELL
echo "=============================================================="
echo 'echo $USER123\necho $?\nexit' | $MINISHELL
echo "=============================================================="
echo 'echo $U\necho $?\nexit' | $MINISHELL
echo "=============================================================="
echo 'echo $USE\necho $?\nexit' | $MINISHELL
echo "=============================================================="
echo 'echo $USERR\necho $?\nexit' | $MINISHELL
echo "=============================================================="
echo 'echo ~\necho $?\nexit' | $MINISHELL
echo "=============================================================="
echo 'echo "~"\necho $?\nexit' | $MINISHELL
echo "=============================================================="
echo "echo '~'\necho \$?\nexit" | $MINISHELL
echo "=============================================================="
echo "echo ~nope\necho \$?\nexit" | $MINISHELL
echo "=============================================================="
echo "echo nope~\necho \$?\nexit" | $MINISHELL
echo "=============================================================="
echo "echo ~/\necho \$?\nexit" | $MINISHELL
echo "=============================================================="
echo "echo ~ ~nope ~ nope~ ~ ~nope~ ~ 'quote~' ~ \"dquote~\" ~/path '~/quote' \"~/dquote\"\necho \$?\nexit" | $MINISHELL
echo "=============================================================="
echo 'echo oi && echo io\nexit' | $MINISHELL
echo "=============================================================="
echo 'echo oi || echo io\nexit' | $MINISHELL
echo "=============================================================="
echo 'ech oi || echo io\nexit' | $MINISHELL
echo "=============================================================="
echo 'echo oi || ech io\nexit' | $MINISHELL
echo "=============================================================="
echo 'echo "oi" && echo "io"\nexit' | $MINISHELL
echo "=============================================================="
echo 'echo "oi" || echo "io"\nexit' | $MINISHELL
echo "=============================================================="
echo 'ech "oi" || "echo io"\nexit' | $MINISHELL
echo "=============================================================="
echo 'echo "oi" || "ech io"\nexit' | $MINISHELL
echo "=============================================================="
echo 'echo "oi\nexit' | $MINISHELL
echo "=============================================================="
echo "echo 'oi\nexit" | $MINISHELL
echo "=============================================================="
echo 'echo 1 && ech2 2 || (ech3 3 || echo 4) && echo 5\necho 1 4 5\nexit' | $MINISHELL
echo "=============================================================="
echo '(echo 1 && echo 2)\necho 1 2\nexit' | $MINISHELL
echo "=============================================================="
echo '(echo 1 || echo 2)\necho 1\nexit' | $MINISHELL
echo "=============================================================="
echo '(echo oi && echo tchau) | wc -l\necho 2\nexit' | $MINISHELL
echo "=============================================================="
echo 'echo oi && echo tchau | wc -l\necho 1\nexit' | $MINISHELL
echo "=============================================================="
echo 'echo ()\nexit' | $MINISHELL
echo "=============================================================="
echo 'echo "()"\nexit' | $MINISHELL
echo "=============================================================="
echo 'echo "||><|;()|"\necho $?\nexit' | $MINISHELL
echo "=============================================================="
echo 'echo ||><|;()|\necho $?\nexit' | $MINISHELL
echo "=============================================================="
echo 'echo ||><|;()|)\necho $?\nexit' | $MINISHELL
echo "=============================================================="
echo 'echo "||><|;()|)"\necho $?\nexit' | $MINISHELL
echo "=============================================================="
echo 'echo >||><|;()|<\necho $?\nexit' | $MINISHELL
echo "=============================================================="
echo 'echo <||><|;()|>\necho $?\nexit' | $MINISHELL
echo "=============================================================="
echo 'echo <||>>><<<|;()|>\necho $?\nexit' | $MINISHELL
echo "=============================================================="
echo 'echo "<||>>><<<|;()|>"\necho $?\nexit' | $MINISHELL
echo "=============================================================="
echo 'echo ||\necho $?\nexit' | $MINISHELL
echo "=============================================================="
echo 'echo | |\necho $?\nexit' | $MINISHELL
echo "=============================================================="
echo 'echo |\necho $?\nexit' | $MINISHELL
echo "=============================================================="
echo 'echo ;;\necho $?\nexit' | $MINISHELL
echo "=============================================================="
echo 'echo > <\necho $?\nexit' | $MINISHELL
echo "=============================================================="
echo 'echo >\necho $?\nexit' | $MINISHELL
echo "=============================================================="
echo 'env | grep USER\necho $?\nexit' | $MINISHELL
echo "=============================================================="
echo 'env | grep PATH\necho $?\nexit' | $MINISHELL
echo "=============================================================="
echo 'top -bn 1\necho $?\nexit' | $MINISHELL
echo "=============================================================="
echo 'env ls\necho $?\nexit' | $MINISHELL
echo "=============================================================="
echo 'env TESTE=1 env | grep TESTE\necho $?\nexit' | $MINISHELL
echo "=============================================================="
echo 'env\necho $?\nexit' | $MINISHELL
echo "=============================================================="
echo 'unset ?\necho $?\nexit' | $MINISHELL
echo "=============================================================="
