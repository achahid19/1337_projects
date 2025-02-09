# Variables

CC = c++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp

HEADERS = Array.hpp

OBJ_DIR = .garbage_objs

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.cpp=.o))

NAME = array

# Rules

all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o : %.cpp | $(OBJ_DIR)
	@$(CC) $(CPPFLAGS) -c $< -o $@

$(NAME): $(OBJ) $(HEADERS)
	@$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)
	@echo "Program ready!"

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME) $(OBJ_DIR)
	@find . -maxdepth 1 -type f ! \( -name "*.cpp" -o -name "*.hpp" -o -name "Makefile" -o -name "*.tpp" \) -print -delete
	@echo "Cleaning Done!"

re: fclean all

.PHONY: clean fclean all re