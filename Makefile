# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/11 21:19:28 by ncolomer          #+#    #+#              #
#    Updated: 2023/11/05 17:09:32 by achahid-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
SRCS := isalnum.c isprint.c memcmp.c \
        strlcat.c strncmp.c substr.c atoi.c isalpha.c \
        memcpy.c strchr.c strlcpy.c \
        strnstr.c tolower.c bzero.c  isascii.c \
        memmove.c strdup.c strlen.c strrchr.c \
        toupper.c calloc.c isdigit.c memchr.c memset.c \
		strjoin.c strtrim.c last_split.c itoa.c strmapi.c \
		ft_striteri.c putchar_fd.c  putstr_fd.c putendl_fd.c \
		putnbr_fd.c lstnew.c lstadd_front.c lstsize.c lstlast.c \
		lstadd_back.c lstdelone.c lstclear.c lstiter.c lstmap.c\

OBJS := $(SRCS:.c=.o)

CC := cc
RM := rm -f
CFLAGS := -Wall -Wextra -Werror

NAME := libft.a

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)
clean:
				$(RM) $(OBJS) $(BONUS_OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

bonus:			$(OBJS) $(BONUS_OBJS)
				ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

.PHONY:			all clean fclean re bonus
