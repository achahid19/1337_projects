# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achahid- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/09 09:15:55 by achahid-          #+#    #+#              #
#    Updated: 2024/10/09 09:15:56 by achahid-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables

CC = g++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = *.cpp

HEADERS = Fixed.hpp Point.hpp

NAME = rawBits

# Targets

all: $(NAME)

$(NAME): $(SRCS) $(HEADERS)
	@$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean:
	@rm -f $(NAME)

fclean: clean
	@find . -type f ! \( -name "*.cpp" -o -name "*.hpp" -o -name "Makefile" \) -delete

re: fclean all

.PHONY: clean fclean re all
