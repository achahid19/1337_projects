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

re: fclean all

.PHONY: clean fclean all re
