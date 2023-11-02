# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gcampos- <gcampos-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/27 18:32:48 by gcampos-          #+#    #+#              #
#    Updated: 2023/11/02 15:03:45 by gcampos-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#SETUP
PROG = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -f
INCLUDE = -I .

#FILES
SRCS = pipex.c utils.c process.c
OBJS = ${SRCS:.c=.o}
MAKE = make -C
LIBFT_PATH = libft
LIBFT = -L ${LIBFT_PATH} -lft

.c.o:
		${CC} ${CFLAGS} ${INCLUDE} -c $< -o ${<:.c=.o}

all:	${PROG}

$(PROG): ${OBJS}
		@echo "Compiling libft..."
		@${MAKE} ${LIBFT_PATH} all
		@echo "libft compiled!"
		@echo "Compiling ${PROG}..."
		${CC} ${OBJS} ${LIBFT} -o ${PROG}
		@echo "pipex compiled!"


clean:
		${MAKE} ${LIBFT_PATH} clean
		@echo "libft cleaned!"
		@${RM} ${OBJS}
		@echo "pipex cleaned!"

fclean: clean
		${MAKE} ${LIBFT_PATH} fclean
		@echo "libft fcleaned!"
		@${RM} ${PROG}
		@echo "pipex fcleaned!"

re: fclean all

.PHONY: all clean fclean re