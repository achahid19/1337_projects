# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achahid- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/01 12:46:37 by achahid-          #+#    #+#              #
#    Updated: 2024/10/01 12:46:39 by achahid-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Varaibales

CPP = g++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = Account.cpp tests.cpp

HEADERS = Account.hpp

NAME = accounts

# Rules

all: $(NAME)

$(NAME): $(SRCS) $(HEADERS)
	@$(CPP) $(CFLAGS) $(SRCS) -o $(NAME)

clean:
	@rm -f $(NAME)

fclean: clean
	@find . -type f ! \( -name "*.cpp" -o -name "*.hpp" -o -name "*.log" -o -name "Makefile" \) -delete

re: fclean all

.PHONY: clean fclean all re
