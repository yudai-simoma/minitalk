# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/12 15:15:53 by yshimoma          #+#    #+#              #
#    Updated: 2023/03/01 21:11:30 by yshimoma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf.c ft_printf_utils.c ft_itoa.c ft_u_itoa.c ft_16_itoa_upper.c \
	ft_16_itoa_lower.c ft_16_address_itoa.c ft_putstr_fd.c ft_calloc.c ft_memset.c \
	ft_strlen.c
OBJS = ${SRCS:.c=.o}
NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = rcs

all: ${NAME}

${NAME}: ${OBJS}
	${AR} ${ARFLAGS} ${NAME} ${OBJS}

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re