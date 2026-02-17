# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yuriiartymicloud.com <yuriiartymicloud.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/21 18:12:56 by yuriiartymi       #+#    #+#              #
#    Updated: 2026/02/17 15:03:35 by yartym           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Werror -Wextra
DEL = rm -rf
LIBFT_DIR = ./libft
LIBFT = ${LIBFT_DIR}/libft.a
LIBFT_INCL = -I ./libft/includes/
OBJ_DIR = obj
SRCS_DIR = src
INCLUDES = -I ./includes/

SRCS = main.c \
		init_stack.c \
		util_moves.c \
		lis.c \
		target.c \
		sort.c \
		move_stacks.c \
		small_sort.c \
		all_moves.c \


OBJS = $(addprefix ${OBJ_DIR}/, ${SRCS:.c=.o})

all: ${NAME}

${NAME}: ${OBJS}
	make -C ${LIBFT_DIR}
	${CC} ${CFLAGS} $^ ${LIBFT} -o $@

${OBJ_DIR}:
	mkdir -p $@

${OBJS}: ${OBJ_DIR}/%.o: ${SRCS_DIR}/%.c | ${OBJ_DIR}
	${CC} ${CFLAGS} ${INCLUDES} ${LIBFT_INCL} -c $< -o $@

fclean: clean
	${DEL} ${NAME}

clean:
	make fclean -C ${LIBFT_DIR}
	${DEL} ${OBJ_DIR}

re: fclean all

.PHONY: all fclean clean re
