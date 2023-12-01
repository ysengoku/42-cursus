# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/20 16:10:58 by yusengok          #+#    #+#              #
#    Updated: 2023/12/01 10:56:33 by yusengok         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
INCLUDE = includes/
HEADER = includes/ft_printf.h
CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INCLUDE)
AR = ar rcs
# ar: オブジェクトファイルを静的ライブラリー (アーカイブ) に変換
# r (replace): ファイルを挿入し、同名のファイルがあったら置換する
# c (create): アーカイブを作成する。ファイルを更新する操作の場合には、指定したファイルが存在しなければ
#			常に作成されるが、このとき警告メッセージが出る。このオプションをあらかじめ指定しておけば、
#			この警告を抑止できる。
# s: オブジェクトファイルの索引をファイルに書き込むか、または存在する索引を更新する。
#	書庫に何の変化がなくても更新は行われる。このオプションはどんな操作とも同時に用いることができるし、
#	単独でも用いることができる。 `ar s 'をアーカイブに対して実行するのは、 `ranlib 'と等価である。 
RM = rm

SRCS_DIR = srcs/
OBJS_DIR = .objs/

FILES = ft_printf \
				ft_print_char \
				ft_print_ptr \
				ft_print_str \
				ft_print_nbr \
				ft_print_uint \
				ft_print_hex \
				ft_utils

SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))

OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))

OBJF = .cache_exists
# Check if the cache exists

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c $(HEADER) | $(OBJF)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJF):
	@mkdir -p $(OBJS_DIR)
# 新規ディレクトリを作成して、その下にサブディレクトリを作りたい場合は-pオプションを使用。

clean:
	$(RM) -rf $(OBJS_DIR)

fclean: clean
	$(RM) -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
