# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nfaust <nfaust@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/21 19:44:40 by nfaust            #+#    #+#              #
#    Updated: 2023/01/04 22:05:07 by nfaust           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
FLAGS = -Wextra -Wall -Werror
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
	src/print_instr.c \
	src/instructions.c \
	src/radix_sort.c \
	src/selection_sort.c \
	src/little_sort.c

OBJ = $(SOURCES:.c=.o)

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
	${REMOVE} ${OBJ}

fclean:	clean
	@make fclean -C libft
	@make fclean -C ft_printf
	${REMOVE} ${NAME}

keep_o: all clean

%.o : %.c ${HEADER} Makefile ${LIBFTNAME} ${PRINTFNAME}
	${CC} ${FLAGS}  -c $< -o $@ -I . 

re:    fclean all

fsan: re
	${CC} ${FLAGS} -fsanitize=address -g3 ${OBJ} ${LIBFTNAME} ${PRINTFNAME} -o ${NAME}

.PHONY: re fclean all clean libft keep_o ft_printf fsan