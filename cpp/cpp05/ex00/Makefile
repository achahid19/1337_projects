#Variables

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp Bureaucrat.cpp

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.cpp=.o))

OBJ_DIR = .garbage_objs

HEADERS = Bureaucrat.hpp

NAME = Bureaucrat

# Rules

all: $(NAME)

$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ) $(HEADERS)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "Program Ready"

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME) $(OBJ_DIR)
	@echo "Cleaning Done"

re: fclean all

.PHONY: fclean clean all re
