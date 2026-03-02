# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/27 23:31:16 by Itachi-Logic      #+#    #+#              #
#    Updated: 2026/03/02 21:02:42 by Itachi-Logic     ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# --- Variables ---
NAME = ord
SRC_FILE = ord_alphlong.c  print_array.c  sort_array.c  strcasecmp.c
CC = gcc
FLAGS = -Wall -Wextra -Werror
RM = rm -f

# --- Rules ---

# Default rule to build the executable
all: $(NAME)

# Rule to compile source files directly into the executable
$(NAME): $(SRC_FILE)
	$(CC) $(FLAGS) $(SRC_FILE) -o $(NAME)

# Empty clean rule because there are no .o files to delete
clean:

# Rule to delete the executable file
fclean: clean
	$(RM) $(NAME)

# Rule to rebuild everything from scratch
re: fclean all

# Protect rules from conflicting with real files
.PHONY: all clean fclean re
