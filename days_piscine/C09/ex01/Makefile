# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/24 23:36:06 by Itachi-Logic      #+#    #+#              #
#    Updated: 2026/03/30 22:12:18 by Itachi-Logic     ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FILES = ft_putchar.c \
        ft_swap.c \
        ft_putstr.c \
        ft_strlen.c \
        ft_strcmp.c

SRCS = $(addprefix srcs/, $(FILES))
OBJS = $(SRCS:.c=.o)
INCLUDES = -I includes
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)
	ranlib $(NAME)

re: fclean all

.PHONY: all clean fclean re

