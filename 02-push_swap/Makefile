# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/16 13:44:13 by yusengok          #+#    #+#              #
#    Updated: 2024/01/18 13:47:13 by yusengok         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
ARCHIVE = $(NAME).a
INCLUDE = includes
HEADER = $(INCLUDE)/push_swap.h
CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INCLUDE)
AR = ar rcs
RM = rm -f

SRCS_DIR = srcs
SRCS = $(wildcard $(SRCS_DIR)/*.c)
OBJS_DIR = .objs
OBJS = $(addprefix $(OBJS_DIR)/, $(notdir $(SRCS:.c=.o)))

all: $(NAME)

$(NAME): $(ARCHIVE)
	$(CC) $(CFLAGS) -o $@ $(ARCHIVE) -L./libft -lft

$(ARCHIVE): $(OBJS)
	$(MAKE) -C ./libft
	$(AR) $@ $(OBJS)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(HEADER)
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C ./libft clean
	$(RM) -r $(OBJS_DIR)

fclean: clean
	$(MAKE) -C ./libft fclean
	$(RM) $(NAME) $(ARCHIVE)

re: fclean all

.PHONY: all clean fclean re
