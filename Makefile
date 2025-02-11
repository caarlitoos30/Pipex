# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: calguaci <calguaci@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/09 18:44:49 by calguaci          #+#    #+#              #
#    Updated: 2025/02/11 17:18:22 by calguaci         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB = ar rcs
RM = rm -f

CC = cc

CCFLAGS = -Wall -Wextra -Werror -g3

SRC_DIR = src

SRC = main.c \
		pipex_functs_1.c \
		pipex_functs_2.c \

OBJ = $(SRC:.c=.o)

INCLUDE = pipex.h

NAME = pipex

LIBFTA = libft_ext/libft.a

all: $(NAME)

%.o: %.c
	@$(CC) $(CCFLAGS) -I/libft/libft.h -I/usr/include -Iminilibx-linux -O3 -c $< -o $@

$(NAME): $(OBJ)
	@cd libft_ext && make
	@$(CC) $(CCFLAGS) $(OBJ) -Ilibft_ext $(LIBFTA) -o $(NAME)
	@echo "$(YELLOW)        ||>>    $(BLUE)pipex $(YELLOW)compiled!!    <<||$(RESET)"

clean:
	@$(RM) $(OBJ)
	@cd libft_ext && make clean

fclean:
	@$(RM) $(NAME) $(OBJ)
	@cd libft_ext && make fclean

re: fclean all

.PHONY: all clean fclean re