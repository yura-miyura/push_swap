# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yartym <yartym@student.42london.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/19 08:46:47 by yartym            #+#    #+#              #
#    Updated: 2026/02/19 09:04:43 by yartym           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CHECKER = checker
CC = cc
CFLAGS = -Wall -Werror -Wextra
DEL = rm -rf

# Directories
LIBFT_DIR = ./libft
OBJ_DIR = obj
DIR_SHARED = src_shared
DIR_PSWP = src_push_swap
DIR_GNL = gnl
DIR_CHECKER = src_checker
DIR_INCLUDES = includes

# Libraries & Includes
LIBFT = ${LIBFT_DIR}/libft.a
INCLUDES = -I ./includes/ -I ./libft/includes/

# Sources
HEADERS = checker.h get_next_line.h push_swap.h
HDRS = $(addprefix ${DIR_INCLUDES}/, ${HEADERS})

SRCS_SHARED = init_stack.c util_moves.c
SRCS_PSWP = lis.c target.c sort.c move_stacks.c small_sort.c all_moves.c main.c
SRCS_GNL = get_next_line.c get_next_line_utils.c
SRCS_CHECKER = checker.c utils.c

# Objects
OBJS_SHARED = $(addprefix ${OBJ_DIR}/, ${SRCS_SHARED:.c=.o})
OBJS_PSWP = $(addprefix ${OBJ_DIR}/, ${SRCS_PSWP:.c=.o})
OBJS_GNL = $(addprefix ${OBJ_DIR}/, ${SRCS_GNL:.c=.o})
OBJS_CHECKER = $(addprefix ${OBJ_DIR}/, ${SRCS_CHECKER:.c=.o})

vpath %.c ${DIR_PSWP} ${DIR_GNL} ${DIR_CHECKER} ${DIR_SHARED}

all: ${NAME}

${NAME}: ${OBJS_PSWP} ${OBJS_SHARED} ${LIBFT}
	${CC} ${CFLAGS} ${INCLUDES} $^ -o $@

${CHECKER}: ${OBJS_CHECKER} ${OBJS_SHARED} ${OBJS_GNL} ${LIBFT}
	${CC} ${CFLAGS} ${INCLUDES} $^ -o $@

${OBJ_DIR}/%.o: %.c ${HDRS}| ${OBJ_DIR}
	${CC} ${CFLAGS} ${INCLUDES} -c $< -o $@

${LIBFT}:
	@make --no-print-directory -C ${LIBFT_DIR}

${OBJ_DIR}:
	@mkdir -p $@

clean:
	@make --no-print-directory -C ${LIBFT_DIR} clean
	${DEL} ${OBJ_DIR}

fclean: clean
	@make --no-print-directory -C ${LIBFT_DIR} fclean
	${DEL} ${NAME} ${CHECKER}

re: fclean all

.PHONY: all fclean clean re checker
