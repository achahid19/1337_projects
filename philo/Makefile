# Variables

CC = cc

CFLAGS = -Wall -Wextra -Werror -fsanitize=thread

SRC = $(addprefix src/, data.c  estr.c  monitoring.c  parsing.c  philo.c \
		philos_dinning.c  print.c  syncro.c  libft_utils.c philo_utils.c)

OBJ = $(SRC:.c=.o)

INCLUDES = includes/philo.h

NAME = philo

# Targets

all: $(NAME)

$(NAME): $(OBJ) $(INCLUDES)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
		@echo "philo program compiled 💯"

clean:
		@rm -f $(OBJ)
		@echo "Object files deleted 🚮"

fclean: clean
		@rm -f $(NAME)
		@echo "Executable deleted 🚮"

re: fclean all

.PHONY: clean fclean re all
