# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/27 23:31:16 by Itachi-Logic      #+#    #+#              #
#    Updated: 2026/02/28 23:25:32 by Itachi-Logic     ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# --- Variables ---
NAME = ord
SRC_FILE = ord_alphlong.c  print_array.c  sort_array.c  strcasecmp.c
CC = gcc
FLAGS = -Wall -Wextra -Werror
RM = rm -f

# --- Rules ---

# Default rule to build the library
all: $(NAME)

# Rule to archive the .o files into the library
$(NAME): $(SRC_FILE)
	$(CC) $(FLAGS) $(SRC_FILE) -o $(NAME)

# Smart rule to compile any .c file into a .o file
%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

# Rule to delete everything
clean:
	$(RM) $(NAME)
