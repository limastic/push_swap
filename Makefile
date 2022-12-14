# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nfaust <nfaust@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/21 19:44:40 by nfaust            #+#    #+#              #
#    Updated: 2022/12/14 04:38:23 by nfaust           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
LIBFTNAME = libft/libft.a
CC = cc
FLAGS = -Wall -Werror -Wextra
ARCHIVE = ar rc
REMOVE = rm -f

HEADER = headers/ft_printf.h \
	headers/push_swap.h \
	libft/libft.h

SOURCES = src/ft_printf.c \
	src/print_functions.c \
	src/ft_print_u.c \
	src/push_swap.c \
	src/error_management.c \
	src/utils.c

BONUS_SOURCES = \

OBJ = $(SOURCES:.c=.o)
BONUS_OBJ = $(BONUS_SOURCES:.c=.o)

all:	lib ${NAME}

lib:
	@make -C libft

${NAME}:     ${OBJ}
	${CC} ${FLAGS} ${OBJ} ${LIBFTNAME} -o ${NAME}

clean:
	@make clean -C libft
	${REMOVE} ${OBJ} ${OBJ_BONUS}

fclean:	clean
	@make fclean -C libft
	${REMOVE} ${NAME}

bonus: lib ${OBJ} ${BONUS_OBJ}
	${CC} ${FLAGS} ${OBJ} ${BONUS_OBJ} ${LIBFTNAME} -o ${NAME}

keep_o: bonus clean

%.o : %.c ${HEADER} Makefile
	${CC} ${FLAGS}  -c $< -o $@ -I . 

re:    fclean all

.PHONY: re fclean all clean bonus lib keep_o