# Variables

CC = c++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp

HEADERS = template.hpp

OBJ_DIR = .garbage_objs

OBJS = $(addprefix $(OBJ_DIR)/, $(SRC:.cpp=.o))

NAME = program

# Rules

all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o : %.cpp | $(OBJ_DIR)
	@$(CC) $(CPPFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(HEADERS)
	@$(CC) $(CPPFLAGS) $(OBJS) -o $(NAME)
	@echo "Program ready!"

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME) $(OBJ_DIR)
	@find . -maxdepth 1 -type f ! \( -name "*.cpp" -o -name "*.hpp" -o -name "Makefile" \) -print -delete
	@echo "Cleaning done!"

re: fclean all

.PHONY: re clean fclean all
