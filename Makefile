# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: calguaci <calguaci@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/03 23:05:52 by calguaci          #+#    #+#              #
#    Updated: 2025/02/04 09:31:58 by calguaci         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	pipex

CC = cc

CFLAGS	=	-Wall -Wextra -Werror

STRUCT	= 	-Lminilibx-linux -lmlx_Linux -lX11 -lXext -o fractol

SRCS	=	main.c \
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