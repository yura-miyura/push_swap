# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yuriiartymicloud.com <yuriiartymicloud.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/21 18:12:56 by yuriiartymi       #+#    #+#              #
#    Updated: 2025/12/25 09:51:06 by yuriiartymi      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
AR = ar -rcs
OFLAGS = -Wall -Werror -Wextra
DEL = rm -rf
LIBFT_DIR = ./libft
LIBFT = ${LIBFT_DIR}/libft.a
OBJDIR = obj/

SRCS_PRINTF = ft_printf.c \
		len.c \
		print.c \
		put.c \
		format.c \
		padding.c \
		is.c \

OBJS := ${SRCS:.c=.o}

all: ${NAME}

bonus: all

${NAME}: ${OBJS}
	make -C ${LIBFT_DIR}
	cp ${LIBFT} ${NAME}
	${AR} ${NAME} ${OBJS}

${OBJDIR}:
	mkdir -p $@

${OBJS}: %.o: %.c
	${CC} ${OFLAGS} -c $< -o $@

fclean: clean
	${DEL} ${NAME}

clean:
	make fclean -C ${LIBFT_DIR}
	${DEL} ${OBJS}

re: fclean all

.PHONY: all fclean clean re
