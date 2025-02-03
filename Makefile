# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: calguaci <calguaci@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/03 23:05:52 by calguaci          #+#    #+#              #
#    Updated: 2025/02/03 23:09:23 by calguaci         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	pipex

CC = cc
CFLAGS	=	-Wall -Wextra -Werror
STRUCT	= 	-Lminilibx-linux -lmlx_Linux -lX11 -lXext -o fractol
SRCS	=	render.c \
			math_utils.c \
			init.c \
			events.c \
			main.c \
			string_utils.c \

OBJS	=	${SRCS:.c=.o}

all: $(NAME)

$(NAME): $(UTILS) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS)  -o $(NAME) $(STRUCT) -I ./fractol.h

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re