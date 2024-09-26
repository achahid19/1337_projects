# Variables

CPP = g++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = *.cpp

NAME = program

# Rules

all: $(NAME)

$(NAME): $(SRCS)
		@$(CPP) $(CFLAGS) $(SRCS) -o $(NAME)

clean:
		@rm -f $(NAME)

fclean: clean

re: fclean all

.PHONY: clean fclean re all
