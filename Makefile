NAME = pipex
SRCS_DIR = srcs
SRCS = ${addprefix ${SRCS_DIR}/, pipex.c  command.c exec.c \
									utils.c error.c command_utils.c}
OBJS = ${SRCS:.c=.o}
LIBFT_DIR = ./includes/libft
LIBFT = -L${LIBFT_DIR} -lft
CFLAGS = -Wall -Werror -Wextra -g3
RM = rm -rf

.c.o:
			@cc ${CFLAGS} -c $< -o ${<:.c=.o} -I.

${NAME}:		${OBJS}
				@make -C ${LIBFT_DIR}
				@cc ${CFLAGS} -o ${NAME} ${OBJS} ${LIBFT}
				@echo "\e[38;5;82mCompilation pipex OK\033[92m"

all:			${NAME} 

clean:
				@${RM} ${OBJS}
				@make clean -C ${LIBFT_DIR}
				@echo "\e[38;5;82mclean OK\033[92m"	

fclean:			clean
				@${RM} ${NAME}
				@make fclean -C ${LIBFT_DIR}
				@echo "\e[38;5;82mfclean OK\033[92m"	

re: fclean all

.PHONY: all clean fclean re
