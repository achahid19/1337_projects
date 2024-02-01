# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achahid- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/01 09:47:25 by achahid-          #+#    #+#              #
#    Updated: 2024/02/01 09:47:27 by achahid-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables

CC = cc

CFLAGS = -Wall -Wextra -Werror

MLX_LIB = -Lminilibx-linux -lmlx_Linux -lX11 -lXext

MAIN = fractol.c

SRC = $(addprefix fractol_utils/, fractol_init.c  fractol_rendering.c \
		julia_parsing.c  math_utils.c fractol_hooks.c) \
		$(addprefix fractol_erros/, erros.c) \

SRC_LIBFT = $(addprefix libft/, libft_utils.c)

HEADERS = $(addprefix inc/, fractol.h)

NAME = fractol

# Targets

all: $(NAME)

$(NAME): $(MAIN) $(SRC) $(SRC_LIBFT) $(HEADERS)
		@$(CC) $(CFLAGS) $(MAIN) $(SRC) $(SRC_LIBFT) $(MLX_LIB) -o $(NAME)
		@echo "\033[1;32mFractol: Program Compiled Successfully!\033[0m"

clean:
		@rm -rf $(NAME)
		@echo "\033[1;33mFractol: Repo Cleaned!\033[0m"

fclean: clean

re: fclean all

.PHONY: all re fclean clean
