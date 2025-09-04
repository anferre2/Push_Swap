# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anferre2 <anferre2@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/18 16:05:29 by anferre2          #+#    #+#              #
#    Updated: 2025/08/18 16:11:36 by anferre2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC_DIRS = error operations sort stack utils
HEADERS = push_swap.h

# Find all .c files in the directories
SRCS = main.c $(wildcard $(addsuffix /*.c,$(SRC_DIRS)))
OBJS = $(SRCS:.c=.o)

GREEN = \033[0;32m
RESET = \033[0m

all: $(NAME)

# Build executable
$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)$(NAME) compiled successfully!$(RESET)"

# Compile .c -> .o
%.o: %.c $(HEADERS)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@echo "$(GREEN)Object files removed.$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(GREEN)Executable removed.$(RESET)"

re: fclean all