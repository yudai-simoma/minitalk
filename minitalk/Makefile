# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/09 18:23:46 by yshimoma          #+#    #+#              #
#    Updated: 2023/03/10 19:29:09 by yshimoma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
NAME_SERVER = server
NAME_CLIENT = client
SRCS_SERVER = server.c
OBJS_SERVER = ${SRCS_SERVER:.c=.o}
SRCS_CLIENT = client.c
OBJS_CLIENT = ${SRCS_CLIENT:.c=.o}
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = rcs

all: ${NAME}

${NAME}: ${NAME_SERVER} ${NAME_CLIENT}

${NAME_SERVER}: ${OBJS_SERVER}
	$(MAKE) -C libft
	$(MAKE) -C ft_printf
	${CC} ${CFLAGS} libft/libft.a ft_printf/libftprintf.a ${SRCS_SERVER} -o ${NAME_SERVER}

${NAME_CLIENT}: ${OBJS_CLIENT}
	$(MAKE) -C libft
	$(MAKE) -C ft_printf
	${CC} ${CFLAGS} libft/libft.a ft_printf/libftprintf.a ${SRCS_CLIENT} -o ${NAME_CLIENT}

clean:
	${RM} ${OBJS_SERVER} ${OBJS_CLIENT}

fclean: clean
	${RM} ${NAME_SERVER} ${NAME_CLIENT}

re: fclean all

.PHONY: all clean fclean re