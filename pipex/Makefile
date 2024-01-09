#Variables

SRC = $(addprefix src/, pipex.c pipex_utils.c)
LIBFT = ./libft/libft.a
NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
MAKE = make


all: $(NAME)

$(NAME): $(LIBFT)
		 @${CC} ${CFLAGS} ${SRC} ${LIBFT} -o ${NAME}
		 @echo "\033[1;33mpipex: pipex program compiled succesfully!\033[0m"

$(LIBFT):
		 @${MAKE} -C ./libft; ${MAKE} clean -C ./libft

clean:
		@${MAKE} clean -C ./libft
		@echo "\033[1;31mpipex: Removed all .o files!\033[0m"

fclean: 
		@${RM} ${NAME}
		@${MAKE} fclean -C ./libft
		@echo "\033[1;31mpipex: Removed all .o files!\033[0m"

re: fclean all
		@echo "\033[1;31mpipex: recreating the program\033[0m"