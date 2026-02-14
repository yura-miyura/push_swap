# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yartym <yartym@student.42london.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/07 14:41:00 by yartym            #+#    #+#              #
#    Updated: 2026/02/07 14:47:23 by yartym           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
AR = ar -rcs
RM = rm -rf
CFLAGS := -Wall -Werror -Wextra
OBJ_DIR = obj
SRCS_DIR = src
INCLUDES = -I includes

SRCS = ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_strlen.c \
		ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strncmp.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strnstr.c \
		ft_atoi.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c \

OBJS := $(addprefix ${OBJ_DIR}/, ${SRCS:.c=.o})

all: ${NAME}

${NAME}: ${OBJS}
	${AR} $@ $^

${OBJS}: ${OBJ_DIR}/%.o: ${SRCS_DIR}/%.c | ${OBJ_DIR}
	${CC} ${CFLAGS} ${INCLUDES} -c $< -o $@

${OBJ_DIR}:
	mkdir -p $@

fclean: clean
	${RM} ${NAME}

clean:
	${RM} ${OBJ_DIR}

re: fclean all

.PHONY: all fclean clean re bonus
