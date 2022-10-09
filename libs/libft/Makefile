# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/23 16:18:34 by lucasmar          #+#    #+#              #
#    Updated: 2022/10/08 20:27:21 by ryoshio-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# creates library ************************************************************ #
NAME = libft.a

SRC_PATH=./src
OBJ_PATH=./obj
HEADERS_PATH=./includes

FILES =	ft_isdigit.c\
		ft_isalnum.c\
		ft_isascii.c\
		ft_isprint.c\
		ft_strlen.c\
		ft_memset.c\
		ft_bzero.c\
		ft_memcpy.c\
		ft_memmove.c\
		ft_strlcpy.c\
		ft_strlcat.c\
		ft_toupper.c\
		ft_tolower.c\
		ft_strchr.c\
		ft_strrchr.c\
		ft_strncmp.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_strnstr.c\
		ft_atoi.c\
		ft_calloc.c\
		ft_isalpha.c\
		ft_strdup.c\
		ft_substr.c\
		ft_strjoin.c\
		ft_strtrim.c\
		ft_split.c\
		ft_itoa.c\
		ft_strmapi.c\
		ft_striteri.c\
		ft_putchar_fd.c\
		ft_putstr_fd.c\
		ft_putendl_fd.c\
		ft_putnbr_fd.c\
		get_next_line.c

SRC=$(addprefix $(SRC_PATH)/, $(FILES))
OBJ=$(SRC:$(SRC_PATH)/%.c=$(OBJ_PATH)/%.o)

LIBRARY=ar -rcs

# clear ********************************************************************** #
RM=rm -f
RM_DIR=rm -rf

# compilation **************************************************************** #
FLAGS=-Wall -Wextra -Werror
CC=cc

# rules ********************************************************************** #
$(OBJ_PATH)/%.o:$(SRC_PATH)/%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(FLAGS) -I $(HEADERS_PATH) -c $< -o $@

all:${NAME}

$(NAME):$(OBJ)
		@${LIBRARY} $@ $(OBJ)
		@ranlib $@
		@echo "\033[1;32m       libf.a created ✓ \033[0m"

clean:
		@$(RM) $(OBJ)
		@$(RM_DIR) $(OBJ_PATH)
		@echo "\033[0;31m       ▥ libft objects clean ✓ \033[0m"

fclean: clean
		@$(RM) $(NAME)
		@echo "\033[0;31m       ▥ libft.a clean ✓ \033[0m"

re: fclean all

.PHONY: all clean fclean re

