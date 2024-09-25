# Variables

CPP = g++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = *.cpp

HEADERS = Zombie.h Zombie.hpp

NAME = Zombie

# Rules

all: $(NAME)

$(NAME): $(SRRC) $(HEADERS)
		@$(CPP) $(CFLAGS) $(SRCS) -o $(NAME)

clean:
		@rm -rf $(NAME)

fclean: clean

re: fclean all

.PHONY: fclean all re clean
