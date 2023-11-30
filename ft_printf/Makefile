# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/20 16:10:58 by yusengok          #+#    #+#              #
#    Updated: 2023/11/30 13:37:33 by yusengok         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
INCLUDE = includes
CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INCLUDE)
AR = ar rcs
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

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)
	
# make -C $(LIBFT_DIR) ===> move to $(LIBFT_DIR), then make
# cp(= copy) from libft/libft.a to

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c | $(OBJF)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJF):
	@mkdir -p $(OBJS_DIR)

clean:
	$(RM) -rf $(OBJS_DIR)

fclean: clean
	$(RM) -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
