# Variables
SRC = $(addprefix src/, pipex.c pipex_utils.c pipex_err.c)
SRC_BONUS = $(addprefix src_bonus/, pipex_bonus.c pipex_bonus_utils.c pipex_err_bonus.c)
LIBFT = ./libft/libft.a
NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address
RM = rm -rf
MAKE = make

# Targets
all: $(NAME)

$(NAME): $(LIBFT) ${SRC}
	@${CC} ${CFLAGS} ${SRC} ${LIBFT} -o ${NAME}
	@echo "\033[1;33mpipex: pipex program compiled successfully!\033[0m"

$(LIBFT):
	@${MAKE} -C ./libft
	@echo "\033[1;32mpipex: libft.a library created!\033[0m"
	@${MAKE} clean -C ./libft

bonus: $(LIBFT) $(SRC_BONUS)
	@${CC} ${CFLAGS} ${SRC_BONUS} ${LIBFT} -o ${NAME}
	@echo "\033[1;33mpipex_bonus: bonus compiled successfully!\033[0m"

clean:
	@${MAKE} clean -C ./libft
	@echo "\033[1;31mpipex: Removed all .o files!\033[0m"

fclean:
	@${RM} ${NAME}
	@${MAKE} fclean -C ./libft
	@echo "\033[1;31mpipex: pipex exec && Removed all .o files!\033[0m"

re: fclean all
	@echo "\033[1;31mpipex: recreating the program\033[0m"

.PHONY: fclean clean re bonus all
