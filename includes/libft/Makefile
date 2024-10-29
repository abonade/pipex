SRCS =  ft_atoi.c ft_isascii.c ft_memchr.c ft_strchr.c ft_strlen.c \
		ft_bzero.c ft_isdigit.c ft_memcmp.c ft_strdup.c ft_calloc.c \
		ft_isprint.c ft_memcpy.c ft_strncmp.c ft_tolower.c ft_isalnum.c \
		ft_memmove.c ft_strlcat.c ft_strnstr.c ft_toupper.c ft_isalpha.c \
		ft_memset.c ft_strlcpy.c ft_strrchr.c ft_substr.c ft_strjoin.c \
		ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
OBJS = ${SRCS:.c=.o}
BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
		ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
		ft_lstmap.c
OBJS_BONUS = ${BONUS:.c=.o}
GNL = ${addprefix gnl/, get_next_line_bonus.c get_next_line_utils_bonus.c}
OBJS_GNL = ${GNL:.c=.o}
ADDED = ${addprefix  end_utils/, ft_putstr_error.c}
OBJS_ADDED = ${ADDED:.c=.o}
NAME = libft.a
CFLAGS = -Wall -Werror -Wextra

.c.o:
			@cc ${CFLAGS} -c $< -o ${<:.c=.o} -I.

#${NAME}:	${OBJS}
#			ar rcs ${NAME} ${OBJS}

${NAME}:	${OBJS} ${OBJS_BONUS} ${OBJS_GNL} ${OBJS_ADDED}
			@ar rcs ${NAME} ${OBJS} ${OBJS_BONUS} ${OBJS_GNL} ${OBJS_ADDED}

all:		${NAME}

#bonus:		${OBJS} ${OBJS_BONUS} ${OBJS_GNL}
#			ar rcs ${NAME} ${OBJS} ${OBJS_BONUS} ${OBJS_GNL}

clean:
			@rm -f ${OBJS} ${OBJS_BONUS} ${OBJS_GNL} ${OBJS_ADDED}

fclean:		clean
			@rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
