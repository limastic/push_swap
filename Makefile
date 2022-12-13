# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nfaust <nfaust@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/21 19:44:40 by nfaust            #+#    #+#              #
#    Updated: 2022/12/13 21:56:38 by nfaust           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a
LIBFTNAME = libft/libft.a
CC = cc
FLAGS = -Wall -Werror -Wextra
ARCHIVE = ar rc
HEADER = headers/ft_printf.h
REMOVE = rm -f
SOURCES = src/ft_printf.c \
	src/print_functions.c \
	src/ft_print_u.c \
	src/push_swap.c \
	src/error_management.c \
	src/utils.c

BONUS_SOURCES = \

OBJ = $(SOURCES:.c=.o)
BONUS_OBJ = $(BONUS_SOURCES:.c=.o)

all:	${NAME}

libft:
	make bonus -C libft

${NAME}:    libft ${OBJ}
	cp ${LIBFTNAME} ${NAME}
	${ARCHIVE} ${NAME} ${OBJ}

clean:
	make clean -C libft
	${REMOVE} ${OBJ} ${OBJ_BONUS}

fclean:	clean
	make fclean -C libft
	${REMOVE} ${NAME}

bonus: libft ${OBJ} ${BONUS_OBJ}
	cp ${LIBFTNAME} ${NAME}
	${ARCHIVE} ${NAME} ${OBJ} ${BONUS_OBJ}

keep_a: bonus clean

%.o : %.c ${HEADER} Makefile
	${CC} ${FLAGS}  -c $< -o $@ -I .

re:    fclean all

.PHONY: re fclean all clean bonus libft test keep_a