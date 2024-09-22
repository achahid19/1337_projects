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
