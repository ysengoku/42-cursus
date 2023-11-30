# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/20 16:10:58 by yusengok          #+#    #+#              #
#    Updated: 2023/11/30 11:25:00 by yusengok         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
INCLUDES = includes
CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INCLUDES)
AR = ar rcs
RM = rm

PRINTF_DIR = srcs/
LIBFT_DIR = srcs/libft/
OBJS_DIR = .objs/

PRINTF_FILES = ft_printf \
				ft_print_char \
				ft_print_ptr \
				ft_print_str \
				ft_print_nbr \
				ft_print_uint \
				ft_print_hex

SRCS_PRINTF = $(addprefix $(PRINTF_DIR), $(addsuffix .c, $(PRINTF_FILES)))

OBJS_PRINTF = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(PRINTF_FILES)))

OBJF = .cache_exists

all: $(NAME)

$(NAME): $(OBJS_PRINTF)
	@make -C $(LIBFT_DIR)
	@cp $(LIBFT_DIR)/libft.a libft.a
	@mv libft.a $(NAME)
	$(AR) $(NAME) $(OBJS_PRINTF)
	
# make -C $(LIBFT_DIR) ===> move to $(LIBFT_DIR), then make
# cp(= copy) from libft/libft.a to

#$(OBJS_DIR)%.o: $(LIBFT_DIR)%.c | $(OBJF)
#	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR)%.o: $(PRINTF_DIR)%.c | $(OBJF)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJF):
	@mkdir -p $(OBJS_DIR)

clean:
	$(RM) -rf $(OBJS_DIR)
	@make clean -C $(LIBFT_DIR)

fclean: clean
	$(RM) -f $(NAME)
	$(RM) -f $(LIBFT_DIR)/libft.a

re: fclean $(NAME)

.PHONY: all clean fclean re
