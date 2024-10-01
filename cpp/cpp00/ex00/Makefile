# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achahid- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/01 09:08:49 by achahid-          #+#    #+#              #
#    Updated: 2024/10/01 09:08:51 by achahid-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Varialbes

CPP = g++

CFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = megaphone

SRCS = megaphone.cpp

# Rules

all: $(NAME)

$(NAME): $(SRCS)
	@$(CPP) $(CFLAGS) $(SRCS) -o $(NAME)

clean:
	@rm -f $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re
