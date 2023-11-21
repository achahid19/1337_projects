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

CFILES =  \

OBJECTS = $(CFILES:.c=.o)

CC = cc

CFLAGS = -Werror -Wextra -Wall

NAME = libft.a

AR = ar rcs

all: $(NAME)

$(NAME): $(OBJECTS)
		$(AR) $(NAME) $(OBJECTS)

clean: 
		rm -f $(OBJECTS)

fclean: clean
		rm -f $(NAME)

re: clean fclean all
