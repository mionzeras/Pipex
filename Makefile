# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gcampos- <gcampos-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/27 18:32:48 by gcampos-          #+#    #+#              #
#    Updated: 2023/10/05 18:30:04 by gcampos-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#SETUP
PROG = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -f
INCLUDE = -I .

#FILES
SRCS = pipex.c utils.c
OBJS = ${SRCS:.c=.o}
MAKE = make -C
LIBFT_PATH = libft
LIBFT = -L ${LIBFT_PATH} -lft

.c.o:	%.o : %.c
		${CC} ${CFLAGS} ${INCLUDE} -c $< -o ${<:.c=.o}

all:	${PROG}

$(PROG): ${OBJS}
		${MAKE} ${LIBFT_PATH} all
		${CC} ${OBJS} ${LIBFT} -o ${PROG}



clean:
		${MAKE} ${LIBFT_PATH} clean
		${RM} ${OBJS}

fclean: clean
		${MAKE} ${LIBFT_PATH} fclean
		${RM} ${PROG}

re: fclean all

.PHONY: all clean fclean re