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
		args_checker.c free_and_errors.c move_utils.c utils.c \
		push_swap_utils.c push_swap_utils2.c stack_shifting.c)

SRCS_BONUS = $(addprefix bonus/, actions2_bonus.c  args_checker_bonus.c \
			push_swap_bonus.c utils2_bonus.c actions_bonus.c free_errors_bonus.c\
			utils_bonus.c utils3_bonus.c)

OBJECTS_MANDATORY = $(SRCS:.c=.o)

OBJECTS_BONUS = $(SRCS_BONUS:.c=.o)

LIBFT = ./libft/libft.a

HEADER = $(addprefix includes/, push_swap.h)

HEADER_BONUS = $(addprefix includes/, push_swap_bonus.h)

NAME = push_swap

CHECKER_NAME = checker


# Targets

all: $(NAME)

$(NAME): $(OBJECTS_MANDATORY) $(HEADER) $(LIBFT)
		@$(CC) $(CFLAFS) $(OBJECTS_MANDATORY) $(LIBFT) -o $(NAME)
		@echo "🚀 Push_swap Program Compiled 🚀"

$(LIBFT):
		@$(MAKE) -C ./libft
		@echo "Libft archive created successfully ✅"

bonus: $(OBJECTS_BONUS) $(LIBFT) $(HEADER_BONUS)
		$(MAKE) all
		@$(CC) $(CFLAFS) $(OBJECTS_BONUS) $(LIBFT) -o $(CHECKER_NAME)
		@echo "Checker Program Compiled 💯"

clean:
		@rm -f $(OBJECTS_MANDATORY)
		@rm -f $(OBJECTS_BONUS)
		@echo "Push_swap Repo Cleaned ✅"
		@$(MAKE) clean -C ./libft
		@echo "Libft repo cleaned ✅"

fclean: clean
		@rm -f $(NAME)
		@rm -f $(CHECKER_NAME)
		@echo "Push_swap Program Deleted 🚮"
		@echo "Checker Program Deleted 🚮"
		@$(MAKE) fclean -C ./libft
		@echo "Libft Archive Deleted 🚮"

re: fclean all

.PHONY: clean fclean all re
