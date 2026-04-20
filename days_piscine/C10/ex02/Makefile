# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/24 23:36:06 by Itachi-Logic      #+#    #+#              #
#    Updated: 2026/04/20 23:10:20 by Itachi-Logic     ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_tail
SRCS = ft_tail.c\
	check_formula.c\
	ft_atoi.c\
	ft_display_tail.c\
	ft_print_header.c\
	ft_putstr_fd.c\
	ft_display_error.c

OBJS = $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)

.PHONY: all clean fclean
