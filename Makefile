# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achahid- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/15 11:56:28 by achahid-          #+#    #+#              #
#    Updated: 2023/11/15 11:56:31 by achahid-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFILES = isalnum.c isprint.c memcmp.c \
		strlcat.c strncmp.c substr.c atoi.c isalpha.c \
		memcpy.c strchr.c strlcpy.c \
		strnstr.c tolower.c bzero.c  isascii.c \
		memmove.c strdup.c strlen.c strrchr.c \
		toupper.c calloc.c isdigit.c memchr.c memset.c \
		strjoin.c strtrim.c last_split.c itoa.c strmapi.c \
		ft_striteri.c putchar_fd.c  putstr_fd.c putendl_fd.c \
		putnbr_fd.c \

CFILES_B = lstnew.c lstadd_front.c lstsize.c lstlast.c \
			lstadd_back.c lstdelone.c lstclear.c lstiter.c lstmap.c \

OBJECTS = $(CFILES:.c=.o)

OBJECTS_B = $(CFILES_B:.c=.o)

CC = cc

FLAGS = -Werror -Wextra -Wall

NAME = libft.a

AR = ar rcs

all: $(NAME)

bonus:  $(OBJECTS_B) $(CFILES_B)
		$(CC) $(FLAGS) -c $(CFILES_B)
		$(AR) $(NAME) $(OBJECTS_B)

$(NAME): $(OBJECTS) $(CFILES)
		$(CC) $(FLAGS) -c $(CFILES)
		$(AR) $(NAME) $(OBJECTS)

clean: 
		rm -f $(OBJECTS) $(OBJECTS_B)

fclean: clean
		rm -f $(NAME)

re: clean fclean all
