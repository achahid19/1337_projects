# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achahid- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/01 18:09:13 by achahid-          #+#    #+#              #
#    Updated: 2024/03/01 18:09:14 by achahid-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = $(addprefix sources/, push_swap.c actions.c actions2.c \
		args_checker.c input_erros.c move_utils.c utils.c \
		push_swap_utils.c push_swap_utils2.c stack_shifting.c)

OBJECTS = $(SRCS:.c=.o)

LIBFT = ./libft/libft.a

HEADER = $(addprefix includes/, push_swap.h)

NAME = push_swap

# Targets

all: $(NAME)

$(NAME): $(SRCS) $(OBJECTS) $(HEADER) $(LIBFT)
		@$(CC) $(CFLAFS) $(OBJECTS) $(LIBFT) -o $(NAME)
		@echo "🚀 Push_swap Program Compiled 🚀"

$(LIBFT):
		@$(MAKE) -C ./libft
		@echo "Libft archive created successfully ✅"

clean:
		@rm -f $(OBJECTS)
		@echo "Push_swap Repo Cleaned ✅"
		@$(MAKE) clean -C ./libft
		@echo "Libft repo cleaned ✅"

fclean: clean
		@rm -f $(NAME)
		@echo "Push_swap Program Deleted 🚮"
		@$(MAKE) fclean -C ./libft
		@echo "Libft Archive Deleted 🚮"

re: fclean all

.PHONY: clean fclean all re
