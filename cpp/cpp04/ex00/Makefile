# Variables

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = *.cpp

HEADERS = *.hpp

NAME = Animal

# Rules

all: $(NAME)

$(NAME): $(SRC) $(HEADERS)
	@$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
	@echo "cleaning done"

fclean: clean
	@rm -rf $(NAME)
	
re: fclean all

.PHONE: clean fclean all re
