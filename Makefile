# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yuriiartymicloud.com <yuriiartymicloud.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/21 18:12:56 by yuriiartymi       #+#    #+#              #
#    Updated: 2026/02/18 12:00:00 by yartym           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CHECKER = checker
CC = cc
CFLAGS = -Wall -Werror -Wextra
DEL = rm -rf
LIBFT_DIR = ./libft
LIBFT = ${LIBFT_DIR}/libft.a
LIBFT_INCL = -I ./libft/includes/
OBJ_DIR = obj
DIR_PSWP = src_push_swap
DIR_GNL = gnl
INCLUDES = -I ./includes/
DIR_CHECKER = src_checker

SRCS_SHARED = init_stack.c \
				util_moves.c \

SRCS_PSWP = lis.c \
			target.c \
			sort.c \
			move_stacks.c \
			small_sort.c \
			all_moves.c \
			main.c \

SRCS_GNL = get_next_line.c \
		get_next_line_utils.c \

SRCS_CHECKER = checker.c \
				utils.c \

OBJS_SHARED = $(addprefix ${OBJ_DIR}/, ${SRCS_SHARED:.c=.o})
OBJS_CHECKER = $(addprefix ${OBJ_DIR}/, ${SRCS_CHECKER:.c=.o})
OBJS_GNL = $(addprefix ${OBJ_DIR}/, ${SRCS_GNL:.c=.o})
OBJS_PSWP = $(addprefix ${OBJ_DIR}/, ${SRCS_PSWP:.c=.o} ${MAIN:.c=.o})

all: ${NAME}

checker: ${CHECKER}

${CHECKER}: ${OBJS_CHECKER} ${OBJS_SHARED} ${OBJS_GNL}
	make -C ${LIBFT_DIR}
	${CC} ${CFLAGS} ${INCLUDES} $^ ${LIBFT} -o $@

${NAME}: ${OBJS_PSWP} ${OBJS_SHARED}
	make -C ${LIBFT_DIR}
	${CC} ${CFLAGS} ${INCLUDES} $^ ${LIBFT} -o $@

${OBJS_CHECKER}: ${OBJ_DIR}/%.o: ${DIR_CHECKER}/%.c | ${OBJ_DIR}
	${CC} ${CFLAGS} ${INCLUDES} ${LIBFT_INCL} -c $< -o $@

${OBJS_GNL}: ${OBJ_DIR}/%.o: ${DIR_GNL}/%.c | ${OBJ_DIR}
	${CC} ${CFLAGS} ${INCLUDES} -c $< -o $@

${OBJS_PSWP}: ${OBJ_DIR}/%.o: ${DIR_PSWP}/%.c | ${OBJ_DIR}
	${CC} ${CFLAGS} ${INCLUDES} ${LIBFT_INCL} -c $< -o $@

${OBJS_SHARED}: ${OBJ_DIR}/%.o: ${DIR_PSWP}/%.c | ${OBJ_DIR}
	${CC} ${CFLAGS} ${INCLUDES} ${LIBFT_INCL} -c $< -o $@

${OBJ_DIR}:
	mkdir -p $@

fclean: clean
	make fclean -C ${LIBFT_DIR}
	${DEL} ${NAME} ${CHECKER}

clean:
	make clean -C ${LIBFT_DIR}
	${DEL} ${OBJ_DIR}

re: fclean all

.PHONY: all fclean clean re checker
