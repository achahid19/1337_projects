# Variables

CPP = g++

#CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = *.cpp

HEADERS = *.hpp

NAME = harlFilter

# Rules

all: $(NAME)

$(NAME): $(SRCS) $(HEADERS)
	@$(CPP) $(CFLAGS) $(SRCS) -o $(NAME)

clean:
	@rm -f $(NAME)
		
fclean: clean
	@find . -type f ! \( -name "*.cpp" -o -name "Makefile" -o -name "*.hpp" \) -delete

re: fclean all

.PHONY: clean fclean all re
