# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/09 13:32:07 by lucasmar          #+#    #+#              #
#    Updated: 2022/07/09 09:35:43 by lucasmar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# creates library ************************************************************ #
NAME=libftprintf.a

SRC_PATH=./src
OBJ_PATH=./obj
HEADERS_PATH=./headers

FILES=ft_printf.c\
	ft_putc.c\
	ft_puts.c\
	ft_putn.c\
	ft_puth.c\
	ft_strchr.c\
	ft_itoa.c

SRC=$(addprefix $(SRC_PATH)/, $(FILES))
OBJ=$(SRC:$(SRC_PATH)/%.c=$(OBJ_PATH)/%.o)

LIBRARY = ar -rcs

# compilation **************************************************************** #
CC=cc
FLAGS=-Wall -Wextra -Werror

# clear ********************************************************************** #
RM=rm -f
RM_DIR=rm -rf

# rules ********************************************************************** #
$(OBJ_PATH)/%.o:$(SRC_PATH)/%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) -fPIE $(FLAGS) -I $(HEADERS_PATH) -c $< -o $@

$(NAME):$(OBJ)
		@${LIBRARY} $@ $(OBJ)
		@ranlib $@
		@echo "\033[1;32m\n       libftprintf.a created ✓ \033[0m"

all:$(NAME)

clean:
		@$(RM) $(OBJ)
		@$(RM_DIR) $(OBJ_PATH)
		@echo "\033[0;31m       ▥ libftprintf objects clean ✓ \033[0m"

fclean: clean
		@$(RM) $(NAME)
		@echo "\033[0;31m       ▥ libftprintf.a clean ✓ \033[0m"

re: fclean all

.PHONY: all clean fclean re
