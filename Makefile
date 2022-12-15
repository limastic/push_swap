# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nfaust <nfaust@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/21 19:44:40 by nfaust            #+#    #+#              #
#    Updated: 2022/12/15 06:07:20 by nfaust           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
FLAGS = -Wall -Werror -Wextra
ARCHIVE = ar rc
REMOVE = rm -f

NAME = push_swap
LIBFTNAME = libft/libft.a
PRINTFNAME = ft_printf/ft_printf.a

HEADER = ft_printf/ft_printf.h \
	headers/push_swap.h \
	libft/libft.h

SOURCES = src/push_swap.c \
	src/error_management.c \
	src/utils.c \
	src/print_instr.c

BONUS_SOURCES = \

OBJ = $(SOURCES:.c=.o)
BONUS_OBJ = $(BONUS_SOURCES:.c=.o)

all:	libft ft_printf ${NAME}

libft:
	@make -C libft

ft_printf:
	@make -C ft_printf

${NAME}:     ${OBJ}
	${CC} ${FLAGS} ${OBJ} ${LIBFTNAME} ${PRINTFNAME} -o ${NAME}

clean:
	@make clean -C libft
	@make clean -C ft_printf
	${REMOVE} ${OBJ} ${OBJ_BONUS}

fclean:	clean
	@make fclean -C libft
	@make fclean -C ft_printf
	${REMOVE} ${NAME}

bonus: libft ft_printf ${OBJ} ${BONUS_OBJ}
	${CC} ${FLAGS} ${OBJ} ${BONUS_OBJ} ${LIBFTNAME} ${PRINTFNAME} -o ${NAME}

keep_o: bonus clean

%.o : %.c ${HEADER} Makefile
	${CC} ${FLAGS}  -c $< -o $@ -I . 

re:    fclean all

fsan:
	${CC} ${FLAGS} -fsanitize=address -g3 ${OBJ} ${LIBFTNAME} ${PRINTFNAME} -o ${NAME}

.PHONY: re fclean all clean bonus libft keep_o ft_printf