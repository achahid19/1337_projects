# Variables

CC = g++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = *.cpp

HEADERS = *.hpp

NAME = clapTrap

# Tragets

all: $(NAME)

$(NAME): $(SRCS) $(HEADERS)
	@$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean:
	@rm -rf $(NAME)

fclean:
	@find . -type f ! \( -name "*.cpp" -o -name "*.hpp" -o -name "Makefile" \) -delete

re: fclean all

.PHONY: re fclean clean all
