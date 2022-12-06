# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nfaust <nfaust@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/21 19:44:40 by nfaust            #+#    #+#              #
#    Updated: 2022/12/06 14:07:28 by nfaust           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a
CC = cc
FLAGS = -Wall -Werror -Wextra
ARCHIVE = ar rc
HEADER = headers/ft_printf.h
REMOVE = rm -f
SOURCES = src/ft_printf.c \
	src/print_functions.c \
	src/ft_print_u.c \
	src/push_swap.c

BONUS_SOURCES = \

OBJ = $(SOURCES:.c=.o)

BONUS_OBJ = $(BONUS_SOURCES:.c=.o)

all:	${NAME}

${NAME}:    ${OBJ}
	${ARCHIVE} ${NAME} ${OBJ}
	make bonus -C libft

clean:
	${REMOVE} ${OBJ} ${OBJ_BONUS}
	make clean -C libft

fclean:	clean
	${REMOVE} ${NAME}
	make fclean -C libft

bonus: ${OBJ} ${BONUS_OBJ}
	${ARCHIVE} ${NAME} ${OBJ} ${BONUS_OBJ}
	make bonus -C libft

%.o : %.c ${HEADER} Makefile
	${CC} ${FLAGS} -c $< -o $@ -I . 

re:    fclean all

.PHONY: re fclean all clean bonus