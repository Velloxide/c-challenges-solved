# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/24 23:36:06 by Itachi-Logic      #+#    #+#              #
#    Updated: 2026/04/06 18:55:54 by Itachi-Logic     ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_display_file
SRCS = ft_display_content.c\
	ft_display_file.c\
	ft_puterror.c\
	ft_putstr_size.c
OBJS = $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)
fclean: clean
	rm -rf $(NAME)
re: fclean all

.PHONY: all clean fclean re
