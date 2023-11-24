# Variables

CC = cc

CFLAGS = -Wall -Wextra -Werror

AR = ar rcs

RM = rm

HEADER = includes/ft_printf.h

HEADER_LIBFT = includes/libft.h

SRCS_LIBFT = libft/ft_isalnum.c libft/ft_isprint.c libft/ft_memcmp.c \
		libft/ft_strlcat.c libft/ft_strncmp.c libft/ft_substr.c libft/ft_atoi.c libft/ft_isalpha.c \
		libft/ft_memcpy.c libft/ft_strchr.c libft/ft_strlcpy.c \
		libft/ft_strnstr.c libft/ft_tolower.c libft/ft_bzero.c libft/ft_isascii.c \
		libft/ft_memmove.c libft/ft_strdup.c libft/ft_strlen.c libft/ft_strrchr.c \
		libft/ft_toupper.c libft/ft_calloc.c libft/ft_isdigit.c libft/ft_memchr.c libft/ft_memset.c \
		libft/ft_strjoin.c libft/ft_strtrim.c libft/ft_split.c libft/ft_itoa.c libft/ft_strmapi.c \
		libft/ft_striteri.c libft/ft_putchar_fd.c libft/ft_putstr_fd.c libft/ft_putendl_fd.c \
		libft/ft_putnbr_fd.c libft/ft_lstnew.c libft/ft_lstadd_front.c libft/ft_lstsize.c libft/ft_lstlast.c \
		libft/ft_lstadd_back.c libft/ft_lstdelone.c libft/ft_lstclear.c libft/ft_lstiter.c libft/ft_lstmap.c \

SRCS = ft_printf.c helper_functions.c conversions_funcs.c ft_get_func.c \
		ft_print_hexa.c ft_print_pointer.c \

OBJ = $(SRCS:.c=.o)

OBJ_LIBFT = $(SRCS_LIBFT: .c=.o)



NAME = libftprintf.a

# TARGET

all: $(NAME)

$(NAME): $(OBJ) $(OBJ_LIBFT) $(HEADER_LIBFT) $(HEADER)
		$(AR) $(NAME) $(OBJ) $(OBJ_LIBFT)
