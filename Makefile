# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yuriiartymicloud.com <yuriiartymicloud.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/21 18:12:56 by yuriiartymi       #+#    #+#              #
#    Updated: 2026/02/15 07:57:40 by yartym           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
OFLAGS = -g -Wall -Werror -Wextra
DEL = rm -rf
LIBFT_DIR = ./libft
LIBFT = ${LIBFT_DIR}/libft.a
OBJ_DIR = obj

SRCS = main.c \
		init_stack.c \
		s_p_r_rr.c \
		next_number.c \
		operations.c \
		lis.c \
		count.c \
		move_to_a.c \


OBJS = $(addprefix ${OBJ_DIR}/, ${SRCS:.c=.o})

all: ${NAME}

${NAME}: ${OBJS}
	make -C ${LIBFT_DIR}
	${CC} ${OFLAGS} $^ ${LIBFT} -o $@

${OBJ_DIR}:
	mkdir -p $@

${OBJS}: ${OBJ_DIR}/%.o: %.c | ${OBJ_DIR}
	${CC} ${OFLAGS} -c $< -o $@

fclean: clean
	${DEL} ${NAME}

clean:
	make fclean -C ${LIBFT_DIR}
	${DEL} ${OBJ_DIR}

re: fclean all

.PHONY: all fclean clean re
