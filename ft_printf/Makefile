# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/20 16:10:58 by yusengok          #+#    #+#              #
#    Updated: 2023/11/24 15:35:18 by yusengok         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
INCLUDES = includes
CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INCLUDES)
AR = ar rcs
RM = rm

PRINTF_DIR = srcs/
LIBFT_DIR = srcs/Libft/
OBJS_DIR = .objs/

PRINTF_FILES = ft_printf \
				ft_print_char \
				ft_print_str \
				ft_print_nbr \
				ft_print_uint \
				ft_print_hex \

LIBFT_FILES = ft_itoa \
				ft_strlen \
				ft_putchar_fd \
				ft_putstr_fd \
				ft_calloc

SRCS_LIBFT = $(addprefix $(LIBFT_DIR), $(addsuffix .c, $(LIBFT_FILES)))
SRCS_PRINTF = $(addprefix $(PRINTF_DIR), $(addsuffix .c, $(PRINTF_FILES)))

#SRCS = $(SRCS_LIBFT)
#SRCS += $(SRCS_PRINTF)

OBJS_LIBFT = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(LIBFT_FILES)))
OBJS_PRINTF = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(PRINTF_FILES)))

OBJF = .cache_exists

all: $(NAME)

$(NAME): $(OBJS_LIBFT) $(OBJS_PRINTF)
	$(AR) $(NAME) $(OBJS_LIBFT) $(OBJS_PRINTF)

$(OBJS_DIR)%.o: $(LIBFT_DIR)%.c | $(OBJF)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR)%.o: $(PRINTF_DIR)%.c | $(OBJF)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJF):
	@mkdir -p $(OBJS_DIR)

clean:
	$(RM) -rf $(OBJS_DIR)

fclean: clean
	$(RM) -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
