# Variables

CC = cc

CFLAGS = -Wall -Wextra -Werror

AR = ar rcs

RM = rm -f

SRCS = ft_printf.c helper_functions.c conversions_funcs.c ft_get_func.c \
		ft_print_hexa.c ft_print_pointer.c libft_funcs.c\

OBJ = $(SRCS:.c=.o)

NAME = libftprintf.a

# TARGET

all: $(NAME)

$(NAME): $(OBJ)
		$(AR) $(NAME) $(OBJ)
		
clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
