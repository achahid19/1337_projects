# Variables

CC = c++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp Serializer.cpp

HEADERS = Serializer.hpp

OBJ_DIR = .garbage.objs

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.cpp=.o))

NAME = Serializer

# Rules

all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	$(CC) $(CPPFLAGS) -c $< -o $@
		
$(NAME): $(OBJ) $(HEADERS)
	$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)
	@echo "Program Ready!"

clean:
	@rm -rf $(OBJ)

fclean:	clean
	@rm -rf $(OBJ_DIR) $(NAME)
	@find . -maxdepth 1 -type f  ! \( -name "*.cpp" -o -name "*.hpp" -o -name "Makefile" \) -print -delete
	@echo "Cleaning Done!"

re: fclean all

.PHONY: all clean fclean re
