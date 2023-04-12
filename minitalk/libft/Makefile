# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/15 13:28:00 by yshimoma          #+#    #+#              #
#    Updated: 2023/02/12 15:38:03 by yshimoma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# コンパイル対象としたいプログラム
SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c\
	ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c\
	ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c ft_strdup.c\
	ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c\
	ft_strrchr.c ft_tolower.c ft_toupper.c\
	ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c\
	ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c\
	ft_putendl_fd.c ft_putnbr_fd.c
# 生成したいオブジェクトファイル名
# SRCSで定義されている.cファイルから.oファイルを生成する
OBJS = ${SRCS:.c=.o}
# bonusPratのプログラム
SRCS_BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c\
	ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
OBJS_BONUS = ${SRCS_BONUS:.c=.o}
# 生成したい静的ライブラリ名
NAME = libft.a
# コンパイラの指定
CC = cc
# コンパイルオプション
CFLAGS = -Wall -Wextra -Werror

# ボーナスが呼ばれた場合は、ボーナスのソースも追加する
ALL_OBJS = ${OBJS}
ifdef BONUS_FLG
ALL_OBJS += ${OBJS_BONUS}
endif

# clean fclean reを実行する(ビルドを実行)
all:	$(NAME)

# oファイルを.aファイルにコンパイルされる
$(NAME):	${ALL_OBJS}
	ar -r $(NAME) ${ALL_OBJS}

# .cファイルを.oファイルに変換
.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

# 全てのオブジェクトファイルを削除
clean:
	${RM} ${OBJS} ${OBJS_BONUS} 

# 全てのオブジェクトファイルと静的ライブラリを削除
fclean:	clean
	${RM} $(NAME)

# fclean→allを実行(コンパイルのやり直し)
re:	fclean all

# ボーナスが呼ばれたら、ブラグをtrueにする
bonus:
	@make BONUS_FLG=1

# サブコマンドを実行するために記載（ディレクトリに同名のファイルがあっても実行される）
.PHONY:	all clean fclean re bonus
