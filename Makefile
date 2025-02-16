# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: calguaci <calguaci@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/16 21:12:31 by calguaci          #+#    #+#              #
#    Updated: 2025/02/16 22:23:56 by calguaci         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB = ar rcs
RM = rm -f

CC = cc

CCFLAGS = -Wall -Wextra -Werror -g3

SRC_DIR = src

SRC = main.c \
		pipex_functs_1.c \
		pipex_functs_2.c\

OBJ = $(SRC:.c=.o)

INCLUDE = pipex.h

NAME = pipex

LIBFTA = libft-full/libft.a

all: $(NAME)

%.o: %.c
	@$(CC) $(CCFLAGS) -I/libft/libft.h -I/usr/include -Iminilibx-linux -O3 -c $< -o $@

$(NAME): $(OBJ)
	@cd libft-full && make
	@$(CC) $(CCFLAGS) $(OBJ) -Ilibft-full $(LIBFTA) -o $(NAME)

clean:
	@$(RM) $(OBJ)
	@cd libft-full && make clean

fclean:
	@$(RM) $(NAME) $(OBJ)
	@cd libft-full && make fclean

re: fclean all

.PHONY: all clean fclean re
