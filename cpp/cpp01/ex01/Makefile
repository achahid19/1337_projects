# Variables

CPP = g++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = *.cpp

HEADERS = Zombie.h Zombie.hpp

NAME = Zombie

# Rules

all: $(NAME)

$(NAME): $(SRCS) $(HEADERS)
	@$(CPP) $(CFLAGS) $(SRCS) -o $(NAME)

clean:
	@rm -rf $(NAME)

fclean: clean
	@find . -type f ! \( -name "*.cpp" -o -name "*.hpp" -o -name "*.h" -o -name "Makefile" \) -delete

re: fclean all

.PHONY: fclean all re clean
