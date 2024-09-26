# Variables

CPP = g++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = *.cpp

NAME = war

# Targets

all: $(NAME)

$(NAME): $(SRCS)
		@$(CPP) $(CFLAGS) $(SRCS) -o $(NAME)

clean:
		@rm -f $(NAME)

fclean: clean

re: fclean all

.PHONY: clean fclean all re
