#!/bin/bash

MINISHELL="./minishell"
make

echo 'ls' | $MINISHELL 2> /dev/null
echo 'cd -'
echo 'exit'
