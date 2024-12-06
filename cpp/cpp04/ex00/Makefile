# Variables

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = Animal.cpp Cat.cpp Dog.cpp main.cpp

OBJ_DIR = .garbage_objs

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.cpp=.o))

HEADERS = Animal.hpp Dog.hpp Cat.hpp

NAME = Animal

# Rules

all: $(NAME)

$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ) $(HEADERS)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "Program Compiled!"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@echo "cleaning done"
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME) $(OBJ_DIR)
	
re: fclean all

.PHONE: clean fclean all re