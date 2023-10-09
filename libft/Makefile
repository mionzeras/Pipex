NAME = libft.a
PART1 = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
		ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c \
		ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c \
		ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c 

PART2 = ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_putchar_fd.c \
		ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_itoa.c ft_strmapi.c \
		ft_striteri.c
BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c \
		ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c
SRC = ${PART1} ${PART2}
OBJS = ${SRC:.c=.o}
BONUS_OBJ = ${BONUS:.c=.o}
HEADER = libft.h
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g

%.o:%.c
		@${CC} ${CFLAGS} -c -o $@ $^

$(NAME): ${OBJS} ${HEADER}
		@ar rcs ${NAME} ${OBJS} ${HEADER}

all:    ${NAME}

bonus:	${OBJS} ${BONUS_OBJ}
		@ar rcs ${NAME} ${OBJS} ${BONUS_OBJ}

clean:
		@${RM} ${OBJS} ${BONUS_OBJ}
		@echo "Cleaned"

fclean: clean
		@${RM} ${NAME}
		@echo "Fcleaned"

tclean: clean
		${RM}

re: fclean all

teste: all
		${CC} ${CFLAGS} -o teste main.c ${NAME}

.PHONY: all clean fclean tclean re