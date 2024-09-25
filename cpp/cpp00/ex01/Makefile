# Variables

CCP = g++

CFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = phonebook

SRCS = phonebook.cpp user.cpp utils.cpp

HEADERS = $(addprefix headers/, Contact.hpp PhoneBook.hpp main.hpp)

# Rules

all: $(NAME)

$(NAME): $(SRCS) $(HEADERS)
	@$(CCP) $(CFLAGS) $(SRCS) -o $(NAME)

clean:
	@rm -f $(NAME)
fclean: clean

re: fclean all

.PHONY: all clean fclean re
