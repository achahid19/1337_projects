# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achahid- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/28 10:16:05 by achahid-          #+#    #+#              #
#    Updated: 2024/09/28 10:16:07 by achahid-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables

CPP = g++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = *.cpp

HEADERS = main.hpp

NAME = replace

# Rules

all: $(NAME)

$(NAME): $(SRCS) $(HEADERS)
	@$(CPP) $(CFLAGS) $(SRCS) -o $(NAME)

clean:
	@rm -f $(NAME)
		
fclean: clean
	@find . -type f ! \( -name "*.cpp" -o -name "Makefile" -o -name "*.hpp" \) -delete

re: fclean all

.PHONY: clean fclean all re
